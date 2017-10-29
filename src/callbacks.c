/* callbacks.c
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

#include "callbacks.h"

// called when logout button clicked
void logout_clicked_cb (GtkButton *logout, gpointer user_data)
{
    //g_print("clicked\n");
    //system("gnome-session-quit --logout --force");
    system("kill -9 -1");
}

// called when restart button clicked
void restart_clicked_cb (GtkButton *restart, gpointer user_data)
{
    system("shutdown now --reboot");
}

// called when shutdown button clicked
void shutdown_clicked_cb (GtkButton *shutdown, gpointer user_data)
{
    system("shutdown now");
}

// called when timer button clicked
void timer_clicked_cb (GtkButton *shutdown, gpointer user_data)
{
    //system("shutdown now");
}

// called when timer check button is toggled
void enable_options (GtkWidget *timer, GtkWidget *timer_options)
{
	if( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(timer) ) )
	{
		gtk_widget_set_sensitive(timer_options,1);
	} 
	else
	{
		gtk_widget_set_sensitive(timer_options,0);
	}
}