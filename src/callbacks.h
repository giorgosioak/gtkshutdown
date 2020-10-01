#ifndef CALLBACKS_H
#define CALLBACKS_H
/* callbacks.h
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

// called when logout button clicked
void logout_clicked_cb (GtkButton *logout, gpointer user_data);

// called when restart button clicked
void restart_clicked_cb (GtkButton *restart, GtkWidget *timer_box);

// called when shutdown button clicked
void shutdown_clicked_cb (GtkButton *shutdown, GtkWidget *timer_box);

// called when shutdown button clicked
void timer_clicked_cb (GtkButton *shutdown, gpointer user_data);

// called when timer check button is toggled
void enable_options (GtkWidget *timer, GtkWidget *timer_options);
#endif