#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char Name[100];

struct node {
	int value1;
	int value2;
};


struct node DBcon_R(char *user);

int endPage(char *val,int a,int b) {
//int end(int argc, char *argv[]) {
strncpy(Name,val,strlen(val));    
cout << Name << endl;
struct node results;
results = DBcon_R(Name);

//printf("%d %d",results->value,results->next->value);
printf("%d %d %d %d\n",results.value1,results.value2,a,b);

GtkWidget *window;
GtkWidget *fixed;
GtkWidget *label;

GtkWidget *label2;

GtkWidget *blank;
GtkWidget *name;
GtkWidget *age;

//GtkWidget *entry1;
  //GtkWidget *entry2;


GtkWidget *gamelevel;

GtkWidget *label3;
GtkWidget *gameresult;
GtkWidget *resultlevel;



  GtkWidget *btn1;
  GtkWidget *btn2;

  //gtk_init(&argc, &argv);
  gtk_init(NULL,NULL);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), " English Voca Win Out !! ");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 520);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);

////////////////////////////////////////////////////////////////////////////

label = gtk_label_new("-----------------------------------------\n\
English VOCA Win Out!\n\
-----------------------------------------\n\
\n\
Did you have fun? ^^\n\
\n\
Here, We show your the result of the game.");

  gtk_fixed_put(GTK_FIXED(fixed), label, 15, 15);

label2= gtk_label_new("***************************************************************************************************");
 gtk_fixed_put(GTK_FIXED(fixed), label2, 1, 150);

blank= gtk_label_new("<<<<< Your information and selection >>>>>");
gtk_fixed_put(GTK_FIXED(fixed), blank, 15, 170);

name = gtk_label_new("Name : ");
 gtk_fixed_put(GTK_FIXED(fixed), name, 15, 190);
//user name

age= gtk_label_new("Age : ");
 gtk_fixed_put(GTK_FIXED(fixed), age, 15, 210);
//user age

gamelevel= gtk_label_new("game level : ");
gtk_fixed_put(GTK_FIXED(fixed), age, 15, 230);
//user game level


//GtkWidget *label3;
label3= gtk_label_new("<<<<< Your Game Result >>>>>");
gtk_fixed_put(GTK_FIXED(fixed), label3, 15, 250);

//GtkWidget *gameresult;
gameresult= gtk_label_new("result : ");
gtk_fixed_put(GTK_FIXED(fixed), gameresult, 15, 270);

//GtkWidget *resultlevel;
resultlevel= gtk_label_new("result level : ");
gtk_fixed_put(GTK_FIXED(fixed), resultlevel, 15, 290);


  btn1 = gtk_button_new_with_label("GAME REstart");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 15, 480);
  gtk_widget_set_size_request(btn1, 150, 30);

  btn2 = gtk_button_new_with_label("exit");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 180, 480);
  gtk_widget_set_size_request(btn2, 80, 30);

g_signal_connect(G_OBJECT(btn2), "clicked", 
      G_CALLBACK(gtk_main_quit), G_OBJECT(window));




  g_signal_connect(G_OBJECT(window), "destroy", 
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
