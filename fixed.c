#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;

    GtkWidget *fixed;
    
    GtkWidget *button1;
    GtkWidget *button2;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "social media");

    gtk_window_set_default_size(GTK_WINDOW(window), 700, 500);

    fixed = gtk_fixed_new();

    button1 = gtk_button_new_with_label("button1");

    button2 = gtk_button_new_with_label("button2");

    gtk_fixed_put(GTK_FIXED(fixed), button1, 100, 100);
    
    gtk_fixed_put(GTK_FIXED(fixed), button2, 200, 200);

    gtk_fixed_move(GTK_FIXED(fixed), button2, 100, 100);
    gtk_fixed_move(GTK_FIXED(fixed), button1, 200, 200);
    
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), 
    NULL);

    gtk_container_add(GTK_CONTAINER(window), fixed);

    gtk_widget_show_all(window);

    gtk_main();
    
}