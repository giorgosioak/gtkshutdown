#ifndef UTILITIES_H
#define UTILITIES_H
/* utilities.h
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

// transform hours and minutes to shutdown options format
char* get_shutdown_timer_options (GtkWidget *timer_box);

int get_shutdown_timer_options_in_minutes (GtkWidget *timer_box);

/* find child in container
 * thanks to Darius Kucinskas ( @dkucinskas ) */
GtkWidget* find_child(GtkWidget* parent, const gchar* name);
#endif

/* Notifies user via libnotify */
void notify_user(char const* message, char* options);

/* Play an alert sound via libcanberra */
void play_alert_sound();