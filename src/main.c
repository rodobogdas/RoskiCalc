#include <stdlib.h>
#include <gtk/gtk.h>

#include "callbacks.h"

GtkWidget *entry;
GtkWidget *label;

void destroy (GtkWidget* widget, gpointer data)
{
    g_application_quit(G_APPLICATION(data));
}

static void activate(GtkApplication *app, gpointer data)
{
    char *labels[21] = {
        "0", ".", "+", "1", "2", "3", "-", "^", "sqrt",
        "4", "5", "6", "*", "(", ")", "7", "8", "9", "/", "⟲", "C"
    };

    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *grid;

    GdkPixbuf *icon;

    window = gtk_application_window_new(app);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "RoskiCalc");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 380);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

    icon = create_pixbuf("icon.png");
    gtk_window_set_default_icon(icon);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
    gtk_container_add(GTK_CONTAINER(window), box);

    label = gtk_label_new("");
    gtk_box_pack_end(GTK_BOX(box), label, FALSE, TRUE, 0);

    grid = gtk_grid_new();
    gtk_box_pack_end(GTK_BOX(box), grid, TRUE, TRUE, 0);

    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 3);

    GtkWidget *button[20];

    button[0] = gtk_button_new_with_label(labels[0]);
    gtk_grid_attach(GTK_GRID(grid), button[0], 1, 4, 2, 1);

    button[1] = gtk_button_new_with_label(labels[1]);
    gtk_grid_attach(GTK_GRID(grid), button[1], 3, 4, 1, 1);

    button[2] = gtk_button_new_with_label(labels[2]);
    gtk_widget_set_tooltip_text(button[2], "Add");
    gtk_grid_attach(GTK_GRID(grid), button[2], 4, 4, 1, 1);

    button[3] = gtk_button_new_with_label(labels[3]);
    gtk_grid_attach(GTK_GRID(grid), button[3], 1, 3, 1, 1);

    button[4] = gtk_button_new_with_label(labels[4]);
    gtk_grid_attach(GTK_GRID(grid), button[4], 2, 3, 1, 1);

    button[5] = gtk_button_new_with_label(labels[5]);
    gtk_grid_attach(GTK_GRID(grid), button[5], 3, 3, 1, 1);

    button[6] = gtk_button_new_with_label(labels[6]);
    gtk_widget_set_tooltip_text(button[6], "Unary Minus");
    gtk_grid_attach(GTK_GRID(grid), button[6], 4, 3, 1, 1);

    button[7] = gtk_button_new_with_label(labels[7]);
    gtk_widget_set_tooltip_text(button[7], "Power of");
    gtk_grid_attach(GTK_GRID(grid), button[7], 5, 3, 1, 1);

    button[8] = gtk_button_new_with_label(labels[8]);
    gtk_widget_set_tooltip_text(button[8], "Square Root");
    gtk_grid_attach(GTK_GRID(grid), button[8], 6, 3, 1, 1);

    button[9] = gtk_button_new_with_label(labels[9]);
    gtk_grid_attach(GTK_GRID(grid), button[9], 1, 2, 1, 1);

    button[10] = gtk_button_new_with_label(labels[10]);
    gtk_grid_attach(GTK_GRID(grid), button[10], 2, 2, 1, 1);

    button[11] = gtk_button_new_with_label(labels[11]);
    gtk_grid_attach(GTK_GRID(grid), button[11], 3, 2, 1, 1);

    button[12] = gtk_button_new_with_label(labels[12]);
    gtk_widget_set_tooltip_text(button[12], "Multiply");
    gtk_grid_attach(GTK_GRID(grid), button[12], 4, 2, 1, 1);

    button[13] = gtk_button_new_with_label(labels[13]);
    gtk_widget_set_tooltip_text(button[13], "Start Group");
    gtk_grid_attach(GTK_GRID(grid), button[13], 5, 2, 1, 1);

    button[14] = gtk_button_new_with_label(labels[14]);
    gtk_widget_set_tooltip_text(button[14], "End Group");
    gtk_grid_attach(GTK_GRID(grid), button[14], 6, 2, 1, 1);

    button[15] = gtk_button_new_with_label(labels[15]);
    gtk_grid_attach(GTK_GRID(grid), button[15], 1, 1, 1, 1);

    button[16] = gtk_button_new_with_label(labels[16]);
    gtk_grid_attach(GTK_GRID(grid), button[16], 2, 1, 1, 1);

    button[17] = gtk_button_new_with_label(labels[17]);
    gtk_grid_attach(GTK_GRID(grid), button[17], 3, 1, 1, 1);

    button[18] = gtk_button_new_with_label(labels[18]);
    gtk_widget_set_tooltip_text(button[18], "Divide");
    gtk_grid_attach(GTK_GRID(grid), button[18], 4, 1, 1, 1);

    button[19] = gtk_button_new_with_label(labels[20]);
    gtk_widget_set_tooltip_text(button[19], "Clear Display");
    gtk_grid_attach(GTK_GRID(grid), button[19], 6, 1, 1, 1);

    GtkWidget *button_equal = gtk_button_new_with_label("=");
    gtk_widget_set_tooltip_text(button_equal, "Calculate Result");
    GdkRGBA font_color;
    font_color.red = 0.2;
    font_color.green = 0;
    font_color.blue = 0.7;
    font_color.alpha = 0.45;
    gtk_widget_override_background_color(button_equal, GTK_STATE_FLAG_NORMAL, &font_color);
    gtk_grid_attach(GTK_GRID(grid), button_equal, 5, 4, 2, 1);

    GtkWidget *button_undo = gtk_button_new_with_label(labels[19]);
    gtk_widget_set_tooltip_text(button_undo, "Undo");
    gtk_grid_attach(GTK_GRID(grid), button_undo, 5, 1, 1, 1);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, TRUE, TRUE, 0);
    PangoFontDescription *fontDesc = pango_font_description_from_string("calibri 25");
    gtk_widget_override_font(entry, fontDesc);

    GtkWidget *button_quit = gtk_button_new_with_label("Quit");
    gtk_box_pack_end(GTK_BOX(box), button_quit, FALSE, FALSE, 10);
    gtk_box_reorder_child(GTK_BOX(box), button_quit, 0);
    gtk_widget_set_tooltip_text(button_quit, "Quit this application");

    for (int i = 0; i < 19; ++i)
    {
        g_signal_connect(button[i], "clicked", G_CALLBACK(main_buttons_clicked), labels[i]);
    }

    g_signal_connect(button_equal, "clicked", G_CALLBACK(button_equal_clicked), NULL);
    
    /* If the user clicks on "enter" key, handle it 
       as button_equal */
    g_signal_connect(entry, "activate", G_CALLBACK(button_equal_clicked), NULL);
    
    /* Clear any error message when the user clicks on "backspace" key */    
    g_signal_connect(entry, "backspace", G_CALLBACK(clear_label), NULL);
    
    /* If the user changes the cursor position using the mouse */
    g_signal_connect(entry, "button-release-event", G_CALLBACK(get_cursor_position), NULL);


    g_signal_connect(button_undo, "clicked", G_CALLBACK(button_undo_clicked), NULL);


    g_signal_connect(button[19], "clicked", G_CALLBACK(button_clear_clicked), NULL);

    
    g_signal_connect(button_quit, "clicked", G_CALLBACK(destroy), app);


    gtk_widget_show_all(window);
}


int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status = 0;

    app = gtk_application_new("com.github.ilrffy.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run (G_APPLICATION(app), argc, argv);
    g_object_unref (app);

    return status;
}
