#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *grid;
GtkWidget *login_button;
GtkWidget *signup_button;
GtkWidget *confirm_button;
GtkWidget *label1, *label2;
GtkWidget *entry1, *entry2;

// Confirm button callback function
void on_confirm_button_clicked(GtkButton *button, gpointer user_data)
{
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(entry1));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry2));

    g_print("Username: %s\n", username);
    g_print("Password: %s\n", password);

    // Add your logic here to handle the entered username and password
}

// Login button callback function
void on_login_button_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Login button clicked!\n");

    // Remove the login and sign up buttons from the grid
    gtk_container_remove(GTK_CONTAINER(grid), login_button);
    gtk_container_remove(GTK_CONTAINER(grid), signup_button);

    // Create labels and entry fields for username and password
    label1 = gtk_label_new("Enter your username:");
    gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
    label2 = gtk_label_new("Enter your password:");
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
    entry1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry1, 1, 0, 1, 1);
    entry2 = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(entry2), FALSE); // Hide the entered password
    gtk_grid_attach(GTK_GRID(grid), entry2, 1, 1, 1, 1);

    // Create the confirm button
    confirm_button = gtk_button_new_with_label("Confirm");
    g_signal_connect(confirm_button, "clicked", G_CALLBACK(on_confirm_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), confirm_button, 1, 2, 1, 1);

    // Show the new labels, entry fields, and confirm button
    gtk_widget_show_all(grid);
}

// Sign up button callback function
void on_signup_button_clicked(GtkButton *button, gpointer user_data)
{
    g_print("Sign up button clicked!\n");

    // Remove the login and sign up buttons from the grid
    gtk_container_remove(GTK_CONTAINER(grid), login_button);
    gtk_container_remove(GTK_CONTAINER(grid), signup_button);

    // Create labels and entry fields for username and password
    label1 = gtk_label_new("Create a username:");
    gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
    label2 = gtk_label_new("Enter a strong password:");
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
    entry1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry1, 1, 0, 1, 1);
    entry2 = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(entry2), FALSE); // Hide the entered password
    gtk_grid_attach(GTK_GRID(grid), entry2, 1, 1, 1, 1);

    // Create the confirm button
    confirm_button = gtk_button_new_with_label("Confirm");
    g_signal_connect(confirm_button, "clicked", G_CALLBACK(on_confirm_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), confirm_button, 1, 2, 1, 1);

    // Show the new labels, entry fields, and confirm button
    gtk_widget_show_all(grid);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Login/Sign Up");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the window destroy event
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid to hold the buttons and labels
    grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create the login button
    login_button = gtk_button_new_with_label("Login");
    g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_button_clicked), NULL);
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

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
