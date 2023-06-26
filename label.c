#include <gtk/gtk.h>

// Global variables to store the main window and new window
// GtkWidget *window;
GtkWidget *label;
GtkWidget *back_button;
GtkWidget *window;
GtkWidget *grid;
GtkWidget *login_button;
GtkWidget *signup_button;

// void on_login_button_clicked(GtkButton *button, gpointer user_data)
// {
//     g_print("Login button clicked!\n");
//     // Add your login logic here
// }

// Sign up button callback function
void on_signup_button_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Sign up button clicked!\n");
    // Add your sign up logic here
}


// Callback function for the first button click event
void on_button_clicked(GtkButton *button, gpointer data)
{
    // Remove the button from the main window
    gtk_container_remove(GTK_CONTAINER(window), GTK_WIDGET(login_button));
    gtk_container_remove(GTK_CONTAINER(window), GTK_WIDGET(signup_button));

    // Create a grid container for the label and back button
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);

    // Create a label for the main window
    label = gtk_label_new("Label Text");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    // Create a new button for the main window
    back_button = gtk_button_new_with_label("Back");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), back_button, 0, 1, 1, 1);

    // Add the grid container to the main window
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Show all widgets
    gtk_widget_show_all(window);
}

// Callback function for the back button click event
void on_back_button_clicked(GtkButton *button, gpointer data)
{
    // Remove the label, back button, and grid from the main window
    gtk_container_remove(GTK_CONTAINER(window), label);
    gtk_container_remove(GTK_CONTAINER(window), back_button);
    gtk_container_remove(GTK_CONTAINER(window), gtk_widget_get_parent(label));

    // Create the original button and add it to the main window
    GtkWidget *original_button = gtk_button_new_with_label("Open Window");
    g_signal_connect(original_button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(window), original_button);

    // Show all widgets
    gtk_widget_show_all(window);
}

// Function to create the GUI
void create_gui(int argc, char *argv[])
{
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Login/Sign Up");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the window size change event
    g_signal_connect(window, "size-allocate", G_CALLBACK(gtk_widget_queue_draw), NULL);

    // Create a grid to hold the buttons
    grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create the login button
    login_button = gtk_button_new_with_label("Login");
    // g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_button_clicked), NULL);
    gtk_widget_set_hexpand(login_button, TRUE);
    gtk_widget_set_vexpand(login_button, TRUE);
    gtk_grid_attach(GTK_GRID(grid), login_button, 0, 0, 1, 1);

    // Create the sign up button
    signup_button = gtk_button_new_with_label("Sign Up");
    g_signal_connect(signup_button, "clicked", G_CALLBACK(on_signup_button_clicked), NULL);
    gtk_widget_set_hexpand(signup_button, TRUE);
    gtk_widget_set_vexpand(signup_button, TRUE);
    gtk_grid_attach(GTK_GRID(grid), signup_button, 1, 0, 1, 1);

    // Center the buttons both horizontally and vertically
    gtk_widget_set_halign(login_button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(login_button, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(signup_button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(signup_button, GTK_ALIGN_CENTER);

    // Connect the window destroy event
  
    g_signal_connect(login_button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Add the button to the main window
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

   
    gtk_main();
}

int main(int argc, char *argv[])
{
    // Call the function to create the GUI
    create_gui(argc, argv);

    return 0;
}
