#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char Name[100];
char A[10];
char B[10];
char C[10];
int lel;

struct node {
	int value1;
	int value2;
	int value3;
};


struct node DBcon_R(char *user);

int endPage(char *val,int a,int b,char *c) {
//int end(int argc, char *argv[]) {
strncpy(Name,val,strlen(val));    
cout << Name << endl;
struct node results;
results = DBcon_R(Name);

printf("%d %d %d %d %d\n",results.value1,results.value2,results.value3,a,b);

lel = results.value3;
C[0] = lel+48;

if(a>=10)
{
	A[0] = (a/10)+48;
	A[1] = (a%10)+48;
}
else if(a<10) A[0] = a+48;

if(b>=10)
{
	B[0] = (a/10)+48;
	B[1] = (b%10)+48;
}
else if(b<10) B[0] = b+48;



GtkWidget *window;
  GtkWidget *fixed;
GtkWidget *label;

GtkWidget *label2;

GtkWidget *blank;
GtkWidget *name;
//GtkWidget *;

//GtkWidget *entry1;
  //GtkWidget *entry2;


GtkWidget *gamelevel;

GtkWidget *label3;
//GtkWidget *gameresult;
GtkWidget *resultlevel;

GtkWidget *correct_num;
GtkWidget *wrong_num;

GtkWidget *Info;

GtkWidget *db_name;
GtkWidget *db_gamelvl;
GtkWidget *db_resultlvl;
GtkWidget *db_corNum;
GtkWidget *db_WroNum;



  GtkWidget *btn1;
  GtkWidget *btn2;

  gtk_init(NULL, NULL);

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
gtk_fixed_put(GTK_FIXED(fixed), blank, 15, 180);

name = gtk_label_new("Name : ");
 gtk_fixed_put(GTK_FIXED(fixed), name, 15, 210);
//user name

db_name = gtk_label_new(Name);
 gtk_fixed_put(GTK_FIXED(fixed), db_name, 70, 210);

gamelevel= gtk_label_new("Game Level : ");
gtk_fixed_put(GTK_FIXED(fixed), gamelevel, 15, 240);
//user game level
db_gamelvl = gtk_label_new(c);
 gtk_fixed_put(GTK_FIXED(fixed), db_gamelvl, 110, 240);


//GtkWidget *label3;
label3= gtk_label_new("<<<<< Your Game Result >>>>>");
gtk_fixed_put(GTK_FIXED(fixed), label3, 15, 270);

//GtkWidget *resultlevel;
resultlevel= gtk_label_new("Result Level : ");
gtk_fixed_put(GTK_FIXED(fixed), resultlevel, 15, 300);

db_resultlvl = gtk_label_new(C);
 gtk_fixed_put(GTK_FIXED(fixed), db_resultlvl, 110, 300);
 
 Info = gtk_label_new("** Level 1 : Top Class  /  Level 2 : Middle Class  /  Level 3 : NoAnswer **");
gtk_fixed_put(GTK_FIXED(fixed), Info, 30, 330);

//GtkWidget *correct_num;
resultlevel= gtk_label_new("Correct Num : ");
gtk_fixed_put(GTK_FIXED(fixed), resultlevel, 15, 360);

db_corNum = gtk_label_new(A);
 gtk_fixed_put(GTK_FIXED(fixed), db_corNum, 120, 360);


//GtkWidget *wrong_num;
resultlevel= gtk_label_new("Wrong Num : ");
gtk_fixed_put(GTK_FIXED(fixed), resultlevel, 15, 390);

db_WroNum = gtk_label_new(B);
 gtk_fixed_put(GTK_FIXED(fixed), db_WroNum, 110, 390);


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
