#include <gtk/gtk.h>
/*
void show_about(GtkWidget *widget, gpointer data) {

  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("battery.png", NULL);

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "English VOCA");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "Win Out!"); 
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),"-team name-");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), 
     "If you win the game, can achieve the goals about vacabulary.");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), 
     "Please review and give your comments at aaa@gmail.com ");
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}
*/
int main(int argc, char *argv[]) {
    
  GtkWidget *window;
  GtkWidget *label;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "English VOCA");
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);

  label = gtk_label_new("-----------------------------------------\n\
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

  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_container_add(GTK_CONTAINER(window), label);

  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
