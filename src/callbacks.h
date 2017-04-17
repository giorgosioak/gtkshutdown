#include <gtk/gtk.h>
#include <stdlib.h>

// called when logout button clicked
void logout_clicked_cb (GtkButton *logout, gpointer user_data);

// called when restart button clicked
void restart_clicked_cb (GtkButton *restart, gpointer user_data);

// called when shutdown button clicked
void shutdown_clicked_cb (GtkButton *shutdown, gpointer user_data);