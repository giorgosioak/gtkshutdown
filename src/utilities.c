/* utilities.c
 *
 * Copyright (C) 2017 George Ioakeimidis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <canberra.h>
#include <gtk/gtk.h>
#include <libnotify/notify.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

// transform hours and minutes to shutdown options format
char* get_shutdown_timer_options (GtkWidget *timer_box){

    char* ret = malloc( 64 * sizeof(char) );        memset(ret, 0, 64);
    char* hours = malloc( 20 * sizeof(char) );      memset(hours, 0, 20);
    char* minutes = malloc( 20 * sizeof(char) );    memset(minutes, 0, 20);


    // Get (GtkGrid) timer_options
    GtkWidget *timer_options = find_child(timer_box,"timer_options");

    // Get (GtkRadioButton) radio_in
    GtkWidget *radio_in = find_child(timer_options,"radio_in");

    // Get hours and minutes values from GtkSpinButton
    int in_hours = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"in_hours"));
    int in_minutes = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"in_minutes"));
    int at_hours = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"at_hours"));
    int at_minutes = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"at_minutes"));


    // Check if radio_in is active. If radio_in is not active then radio_at is active
    if (gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(radio_in))) {
        return g_strdup_printf("+%d", in_hours * 60 + in_minutes);
    } else {
        return g_strdup_printf("%d:%d", at_hours, at_minutes);
    }
}

int get_shutdown_timer_options_in_minutes (GtkWidget *timer_box) {
    char* ret = malloc( 64 * sizeof(char) );        memset(ret, 0, 64);
    char* hours = malloc( 20 * sizeof(char) );      memset(hours, 0, 20);
    char* minutes = malloc( 20 * sizeof(char) );    memset(minutes, 0, 20);
    time_t T = time(NULL);
    struct tm time = *localtime(&T);

    // Get (GtkGrid) timer_options
    GtkWidget *timer_options = find_child(timer_box,"timer_options");

    // Get (GtkRadioButton) radio_in
    GtkWidget *radio_in = find_child(timer_options,"radio_in");

    // Get hours and minutes values from GtkSpinButton
    int in_hours = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"in_hours"));
    int in_minutes = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"in_minutes"));
    int at_hours = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"at_hours"));
    int at_minutes = gtk_spin_button_get_value( (GtkSpinButton *) find_child(timer_options,"at_minutes"));

    // Check if radio_in is active. If radio_in is not active then radio_at is active
    if (gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(radio_in))) {
        return in_hours * 60 + in_minutes;
    } else {
        int system_time_mins = time.tm_hour * 60 + time.tm_min;
        int selected_time_mins = at_hours * 60 + at_minutes;
        return selected_time_mins - system_time_mins;
    }    
}

// find child in container
GtkWidget* find_child(GtkWidget* parent, const gchar* name) {
    if (g_ascii_strcasecmp(gtk_widget_get_name((GtkWidget*)parent), (gchar*)name) == 0) { 
        return parent;
    }

    if (GTK_IS_BIN(parent)) {
        GtkWidget *child = gtk_bin_get_child(GTK_BIN(parent));
        return find_child(child, name);
    }

    if (GTK_IS_CONTAINER(parent)) {

        GList *children = gtk_container_get_children(GTK_CONTAINER(parent));

        do {

            GtkWidget* widget = find_child(children->data, name);

            if (widget != NULL) {
                return widget;
            }

        } while ((children = g_list_next(children)) != NULL);
    }

    return NULL;
}

void notify_user(char const* message, char* options) {
    GError* err = NULL;
    char* body_message = malloc(80 * sizeof(char));
    snprintf(body_message, 80 * sizeof(char), message, options);
    NotifyNotification* notif = notify_notification_new("Shutdown Manager",body_message,"system-shutdown");
    notify_notification_show(notif,&err);
    g_free(body_message);
}

void play_alert_sound() {
    ca_context* alert;
	ca_context_create(&alert);
	ca_context_play(alert, 0,
		CA_PROP_EVENT_ID, "bell",
        // CA_PROP_MEDIA_FILENAME, "/usr/share/sounds/gtkshutdown/alert.wav"
		CA_PROP_EVENT_DESCRIPTION, "gtkshutdown alert",
		NULL);
	g_usleep(2000000);
}