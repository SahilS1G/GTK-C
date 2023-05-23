#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
    const char *title;
    int width, height;

    gtk_init(&argc,&argv);

    //gtk code

    GtkWidget *window;
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    // gtk_window_maximize(GTK_WINDOW(window));

    // gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    
    gtk_window_set_title(GTK_WINDOW(window),"social media");

    gtk_window_set_default_size(GTK_WINDOW(window),700,500);

    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

    title = gtk_window_get_title(GTK_WINDOW(window));

    printf("your title is %s\n", title);

    gtk_window_get_size(GTK_WINDOW(window),&width,&height);

    printf("the height is %d and widht is %d \n", height, width);


    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}
