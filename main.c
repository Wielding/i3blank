#include <gtk/gtk.h>

gboolean close_window(GtkWidget* pWidget, GVariant* pVariant, gpointer pVoid)
{
    gtk_window_close(GTK_WINDOW(pWidget));
};

static void on_activate(GtkApplication* app)
{
    // Create a new windowV
    GtkWidget* window = gtk_application_window_new(app);

    gtk_window_set_decorated((GtkWindow*) window, false);

    // Create a new button
    GtkWidget* button = gtk_button_new_with_label("\\/\n/\\");
    gtk_button_set_has_frame(GTK_BUTTON(button), FALSE);

    // When the button is clicked, close the window passed as an argument
    // g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close), window);

    GtkEventController* controller = gtk_shortcut_controller_new();

    GtkShortcut* shortcut = gtk_shortcut_new(
            gtk_keyval_trigger_new(GDK_KEY_x, 0),
            gtk_callback_action_new(close_window, window, NULL));

    gtk_shortcut_controller_add_shortcut((GtkShortcutController*) controller, shortcut);
    gtk_widget_add_controller(window, controller);

    gtk_window_set_child(GTK_WINDOW(window), button);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv)
{
    // Create a new application
    GtkApplication* app = gtk_application_new("net.wielding.blank", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    return g_application_run(G_APPLICATION(app), argc, argv);
}
