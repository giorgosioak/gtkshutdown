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

#include <gtk/gtk.h>
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
    if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(radio_in) ) )
    {
        // g_print("radio_in ACTIVE ~> %d hours : %d minutes\n", in_hours, in_minutes );

        in_minutes = in_hours * 60 + in_minutes;

        sprintf(minutes, "%d", in_minutes);

        // create +m format
        ret = strdup("+");
        strncat(ret, minutes, sizeof ret - strlen(ret));
        
    } else {

        // g_print("radio_at ACTIVE ~> %d hours : %d minutes\n", at_hours, at_minutes );

        sprintf(hours, "%d", at_hours);
        sprintf(minutes, "%d", at_minutes);

        // create hh:mm format
        ret = strdup(hours);
        strncat(ret, ":", sizeof ret - strlen(ret));
        strncat(ret, minutes, sizeof ret - strlen(ret));
        
    }

    return ret;

}

// find child in container
GtkWidget* find_child(GtkWidget* parent, const gchar* name)
{
    if (g_strcasecmp(gtk_widget_get_name((GtkWidget*)parent), (gchar*)name) == 0) { 
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