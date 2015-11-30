#include <gtk/gtk.h>

void show_info(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            "-----------------------------------------\n\
English VOCA Win Out!\n\
-----------------------------------------\n\
\n\
-team name-\n\
\n\
If you win the game, can achieve the goals about vacabulary.\n\
\n\
Please review and give your comments ( aaa@gmail.com )\n\
\n\
Enjoy the English:D");
  gtk_window_set_title(GTK_WINDOW(dialog), "Information");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_error(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Yeah! Voca Game Start!");
  gtk_window_set_title(GTK_WINDOW(dialog), "Game Start");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_question(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Are you sure to quit?");
  gtk_window_set_title(GTK_WINDOW(dialog), "Game Quit");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_warning(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;

  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_WARNING,
            GTK_BUTTONS_OK,
            "Fill your information in box and choose the game");
  gtk_window_set_title(GTK_WINDOW(dialog), "Join");



  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *info;
  GtkWidget *join;
  GtkWidget *start;
  GtkWidget *quit;

GtkWidget *label1;
 GtkWidget *entry1;


////////////////////////////////////
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
  gtk_window_set_title(GTK_WINDOW(window), "English VOCA Win Out!");

  table = gtk_table_new(2, 2, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  info = gtk_button_new_with_label("Info");
  join = gtk_button_new_with_label("Join");
start = gtk_button_new_with_label("Start");  
quit = gtk_button_new_with_label("Quit");
  

  gtk_table_attach(GTK_TABLE(table), info, 0, 1, 0, 1, 
      GTK_FILL, GTK_FILL, 3, 3);
  gtk_table_attach(GTK_TABLE(table), join, 1, 2, 0, 1, 
      GTK_FILL, GTK_FILL, 3, 3);
  gtk_table_attach(GTK_TABLE(table), start, 0, 1, 1, 2, 
      GTK_FILL, GTK_FILL, 3, 3);
  gtk_table_attach(GTK_TABLE(table), quit, 1, 2, 1, 2, 
      GTK_FILL, GTK_FILL, 3, 3);
  
  gtk_container_add(GTK_CONTAINER(window), table);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);

  g_signal_connect(G_OBJECT(info), "clicked", 
        G_CALLBACK(show_info), (gpointer) window); 

  g_signal_connect(G_OBJECT(join), "clicked", 
        G_CALLBACK(show_warning), (gpointer) window); 

  g_signal_connect(G_OBJECT(quit), "clicked", 
        G_CALLBACK(show_question), (gpointer) window); 

  g_signal_connect(G_OBJECT(start), "clicked", 
        G_CALLBACK(show_error), (gpointer) window); 

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}