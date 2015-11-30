#include <iostream>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



GtkWidget *windows;
const gchar *namea;
char NAMENAME[100];

int GTKmain(char *name);
int end(void);

void process(GtkWidget *btn1, gpointer data)
{
	GtkWidget *tb;
	tb = GTK_WIDGET(data);
	gtk_entry_set_text(GTK_ENTRY(tb),gtk_entry_get_text(GTK_ENTRY(tb)));
	namea = gtk_entry_get_text(GTK_ENTRY(tb));
	strncpy(NAMENAME,namea,strlen(namea));
	printf("-----------%s--------------",NAMENAME);
	
	//GTKmain(UserName);
	gtk_widget_destroy(windows);
	
	GTKmain(NAMENAME);
	//end();
}



int main(int argc, char *argv[]) {
    
  
  GtkWidget *fixed;
GtkWidget *label;

GtkWidget *label2;

GtkWidget *blank;
GtkWidget *names;
GtkWidget *age;




GtkWidget *gamelevel;


GtkWidget *cb1;
GtkWidget *cb2;
GtkWidget *cb3;

  GtkWidget *btn1;
  GtkWidget *btn2;
GtkWidget *entry1;
GtkWidget *entry2;
  gtk_init(&argc, &argv);

  windows = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(windows), " English Voca Win Out !! ");
  gtk_window_set_default_size(GTK_WINDOW(windows), 500, 520);
  gtk_window_set_position(GTK_WINDOW(windows), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(windows), fixed);


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
  gtk_fixed_put(GTK_FIXED(fixed), label, 15, 15);

label2= gtk_label_new("***************************************************************************************************");
 gtk_fixed_put(GTK_FIXED(fixed), label2, 1, 230);

blank= gtk_label_new("<<<<< Fill in the blank box below >>>>>");
gtk_fixed_put(GTK_FIXED(fixed), blank, 15, 250);

///////////////////////////////////////////////////////////////////////////////////
names = gtk_label_new("Name : ");
 gtk_fixed_put(GTK_FIXED(fixed), names, 15, 280);
entry1 = gtk_entry_new();
entry1 = gtk_entry_new_with_max_length(70);
//entry1.connect("activate", self.enter_callback, entry1)
//g_signal_connect (entry1, "activate",G_CALLBACK (enter_callback),entry1);
 gtk_fixed_put(GTK_FIXED(fixed), entry1, 80, 280);
 gtk_entry_set_text(GTK_ENTRY(entry1), "Insert You Name");
 gtk_widget_show(entry1);
 //gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, TRUE, 1);

age= gtk_label_new("Age : ");
 gtk_fixed_put(GTK_FIXED(fixed), age, 15, 310);
  entry2 = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), entry2, 80, 310);

gamelevel= gtk_label_new("Choose the game level : ");
 gtk_fixed_put(GTK_FIXED(fixed), gamelevel, 15, 350);
/////////////////////////////////////////////////////////////////////////////////////

cb1 = gtk_check_button_new_with_label("High Level");
gtk_fixed_put(GTK_FIXED(fixed), cb1, 15, 370);

cb2 = gtk_check_button_new_with_label("Middle Level");
gtk_fixed_put(GTK_FIXED(fixed), cb2, 15, 395);

cb3 = gtk_check_button_new_with_label("Low Level");
gtk_fixed_put(GTK_FIXED(fixed), cb3, 15, 420);

  btn1 = gtk_button_new_with_label("GAME start");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 15, 480);
  gtk_widget_set_size_request(btn1, 150, 30);

  btn2 = gtk_button_new_with_label("exit");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 180, 480);
  gtk_widget_set_size_request(btn2, 80, 30);
  
  g_signal_connect(btn1, "clicked", G_CALLBACK(process), entry1);

  g_signal_connect(G_OBJECT(btn2), "clicked", G_CALLBACK(gtk_main_quit), G_OBJECT(windows));




  g_signal_connect(G_OBJECT(windows), "destroy", 
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(windows);

  gtk_main();

  return 0;
}
