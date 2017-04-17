#include "callbacks.h"

// called when logout button clicked
void logout_clicked_cb (GtkButton *logout, gpointer user_data)
{
    g_print("clicked\n");
    // system("gnome-terminal &");
}

// called when restart button clicked
void restart_clicked_cb (GtkButton *restart, gpointer user_data)
{
    system("gnome-terminal &");
}

// called when shutdown button clicked
void shutdown_clicked_cb (GtkButton *shutdown, gpointer user_data)
{
    system("gnome-terminal &");
}