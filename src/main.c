/* main.c
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
#include "callbacks.h"

int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    // init gtk lib
    gtk_init(&argc, &argv);

    // add glade files
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "/org/gnome/gtkshutdown/window_main.glade", NULL);

    // get window_main widget
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    // connect auto signal
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    // show widget
    gtk_widget_show(window);
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}