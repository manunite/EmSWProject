#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <iconv.h>
#include <unistd.h>
#include <time.h>

#define total 5

using namespace std;
////////////////////////////////////////
GtkWidget *window;
  //GtkWidget *button;
  //GtkWidget *button_1,*button_2,*button_3,*button_4;
  GtkWidget *button[10];
  GtkWidget *vbox_1, *vbox_2,*vbox_3,*vbox_4,*vbox_5;
  GtkWidget *hbox_1,*hbox_2;
  GtkWidget *label_Name, *label_Diff;
  GtkWidget *input_Name, *input_Diff;
  GtkWidget *QuizIntro, *Quiz;
  GtkWidget *result;
  GtkWidget *Title;
////////////////////////////////////////
char R_voca[200];
char R_mean[200];
char W_mean1[200];
char W_mean2[200];
char W_mean3[200];
int UserId;
char UserName[30];
int idx_R=0;
int idx_O=0;
char result_Arr[300];
char receive_Arr[300];
char result_Arr1[300];
char receive_Arr1[300];
char result_Arr2[300];
char receive_Arr2[300];
char result_Arr3[300];
char receive_Arr3[300];
int i;
int CorrectNum;
int WrongNum;
int k;
int AnswerIdx;
int QuizCNT;

int DBcon(char *user,int QuizNum,int Correct,int Wrong);
//int main (int argc, char *argv[]);
int euckr2utf8(char *source, char *dest, int dest_size) ;
char* Voca_Mean(void);
void tokenizer2(char *receive1,char *str);
void tokenizer(char *receive1,char *receive2,char *str);
void noncorrect (GtkWidget *widget);
void correct (GtkWidget *widget);

void reset()
{
	////////답 추출///////////
	cout << "Correct : " << CorrectNum << " ---- " << "Wrong : " << WrongNum << endl;
  memset(result_Arr,0x00,sizeof(result_Arr));
  memset(receive_Arr,0x00,sizeof(receive_Arr));
  memset(result_Arr1,0x00,sizeof(result_Arr1));
  memset(receive_Arr1,0x00,sizeof(receive_Arr1));
  memset(result_Arr2,0x00,sizeof(result_Arr2));
  memset(receive_Arr2,0x00,sizeof(receive_Arr2));
  memset(result_Arr3,0x00,sizeof(result_Arr3));
  memset(receive_Arr3,0x00,sizeof(receive_Arr3));
  
  char *R_Protocol = Voca_Mean(); usleep(100*100);//1000*1000-100000
  strncpy(receive_Arr,R_Protocol,strlen(R_Protocol));

  char *Wrong_Answer1 = Voca_Mean(); usleep(100*100);
  strncpy(receive_Arr1,Wrong_Answer1,strlen(Wrong_Answer1));

  char *Wrong_Answer2 = Voca_Mean(); usleep(100*100);
  strncpy(receive_Arr2,Wrong_Answer2,strlen(Wrong_Answer2));

  char *Wrong_Answer3 = Voca_Mean(); usleep(100*100);
  strncpy(receive_Arr3,Wrong_Answer3,strlen(Wrong_Answer3));
  //////////////////////////


  int euclen5 = euckr2utf8(receive_Arr, receive_Arr, sizeof(receive_Arr));
  //euclen1 = euckr2utf8(R_Protocol, R_Protocol, sizeof(R_Protocol));
  int euclen2 = euckr2utf8(receive_Arr1, receive_Arr1, sizeof(receive_Arr1));
  int euclen3 = euckr2utf8(receive_Arr2, receive_Arr2, sizeof(receive_Arr2));
  int euclen4 = euckr2utf8(receive_Arr3, receive_Arr3, sizeof(receive_Arr3));
  
  memset(R_voca,0x00,sizeof(R_voca));
  memset(R_mean,0x00,sizeof(R_mean));
  memset(W_mean1,0x00,sizeof(W_mean1));
  memset(W_mean2,0x00,sizeof(W_mean2));
  memset(W_mean3,0x00,sizeof(W_mean3));

  tokenizer(R_voca,R_mean,receive_Arr);
  tokenizer2(W_mean1,receive_Arr1);
  tokenizer2(W_mean2,receive_Arr2);
  tokenizer2(W_mean3,receive_Arr3);
  
  cout << R_voca << "- " << R_mean << endl;
  cout << W_mean1 << endl;
  cout << W_mean2 << endl;
  cout << W_mean3 << endl;
  
  k = rand()%4 + 1;
  g_print("%d\n",k);
  
  gtk_label_set_text(GTK_LABEL(Quiz),R_voca);
  gtk_button_set_label(GTK_BUTTON(button[(k++)%4 + 1]),W_mean1);
  gtk_button_set_label(GTK_BUTTON(button[(k++)%4 + 1]),W_mean2);
  gtk_button_set_label(GTK_BUTTON(button[(k++)%4 + 1]),W_mean3);
  gtk_button_set_label(GTK_BUTTON(button[(k++)%4 + 1]),R_mean);
  
  AnswerIdx = ((k-1)%4)+1;
  g_print("%d\n",AnswerIdx);
  
  gtk_signal_disconnect_by_data(GTK_OBJECT(button[1]),(gpointer)(NULL));
  gtk_signal_disconnect_by_data(GTK_OBJECT(button[2]),(gpointer)(NULL));
  gtk_signal_disconnect_by_data(GTK_OBJECT(button[3]),(gpointer)(NULL));
  gtk_signal_disconnect_by_data(GTK_OBJECT(button[4]),(gpointer)(NULL));
  
  
  for(i=1;i<=4;i++)
  {
	  if(i==AnswerIdx)
		gtk_signal_connect (GTK_OBJECT (button[AnswerIdx]), "clicked", G_CALLBACK (correct), NULL);
	  else
		gtk_signal_connect (GTK_OBJECT (button[i]), "clicked", G_CALLBACK (noncorrect), NULL);
  }
  return;
}

void correct (GtkWidget *widget)
{
	QuizCNT++;
  g_print ("correct\n");
  gtk_label_set_text(GTK_LABEL(result),"Correct!");
  CorrectNum++;
  if(QuizCNT == total)
  {
	  DBcon(UserName,total,CorrectNum,WrongNum);
	  exit(0);
	  //뭔가 처리되어야함 ex. 어느 페이지로 갈지
  }
  reset();
}

void noncorrect (GtkWidget *widget)
{
	QuizCNT++;
  g_print ("Wrong\n");
  gtk_label_set_text(GTK_LABEL(result),"Wrong Answer!");
  WrongNum++;
  if(QuizCNT == total) 
  {
	  DBcon(UserName,total,CorrectNum,WrongNum);
	  exit(0);
	  //뭔가 처리되어야함 ex. 어느 페이지로 갈지
  }
  reset();
}

void destroy (void)
{
  gtk_main_quit ();
}

 int utf82euckr(char *source, char *dest, int dest_size)
{
    iconv_t it;
    char *pout;
    size_t in_size, out_size;
 
    it = iconv_open("EUC-KR", "UTF-8");
    in_size = strlen(source);
    out_size = dest_size;
    pout = dest;
    if (iconv(it, &source, &in_size, &pout, &out_size) < 0)
        return(-1);
    iconv_close(it);
    return(pout - dest);
    /* return(out_size); */
}
 int euckr2utf8(char *source, char *dest, int dest_size) //EUCKR -> UTF8
{
    iconv_t it;
    char *pout;
    size_t in_size, out_size;
 
    it = iconv_open("UTF-8", "EUC-KR");
    in_size = strlen(source);
    out_size = dest_size;
    pout = dest;
    if (iconv(it, &source, &in_size, &pout, &out_size) < 0)
        return(-1);
    iconv_close(it);
    return(pout - dest);
    /* return(out_size); */
}

void tokenizer(char *receive1,char *receive2,char *str)
{
  idx_R=0;
  idx_O=0;
  char temp;
  while((temp = str[idx_R++]) != '%')
  {
     receive1[idx_O++] = temp;
  }
  idx_O=0;
  while((temp = str[idx_R++]) != 0)
  {
     receive2[idx_O++] = temp;
  }
}

void tokenizer2(char *receive1,char *str)
{
  char temp;
  idx_R=0;
  idx_O=0;
  while((temp = str[idx_R++]) != '%')
  {
     //receive1[idx_O++] = temp;
  }
  idx_O=0;
  while((temp = str[idx_R++]) != 0)
  {
     receive1[idx_O++] = temp;
  }
}


//int main(int argc, char *argv[])
int GTKmain(char *name)
{
  //UserId = ID;
  strncpy(UserName,name,strlen(name));
  char result_Arr[300];
  char receive_Arr[300];
  int euclen1,euclen2,euclen3,euclen4,euclen5;
  //UtfTime=g_convert(buffer, sizeof(buffer), "UTF-8", "euc-kr",NULL,NULL,&error); 
  locale::global(locale("ko_KR.UTF-8"));
  locale::global(locale("ko_KR.euckr"));
  locale::global(locale("ko_KR.utf8"));
  memset(result_Arr,0x00,sizeof(result_Arr));
  memset(receive_Arr,0x00,sizeof(receive_Arr));
  //setlocale(LC_ALL, "korean");

  ////////답 추출///////////
  char *R_Protocol = Voca_Mean(); usleep(100*10);//1000*1000-100000
  strncpy(receive_Arr,R_Protocol,strlen(R_Protocol));

  char *Wrong_Answer1 = Voca_Mean(); usleep(100*10);
  strncpy(receive_Arr1,Wrong_Answer1,strlen(Wrong_Answer1));

  char *Wrong_Answer2 = Voca_Mean(); usleep(100*10);
  strncpy(receive_Arr2,Wrong_Answer2,strlen(Wrong_Answer2));

  char *Wrong_Answer3 = Voca_Mean(); usleep(100*10);
  strncpy(receive_Arr3,Wrong_Answer3,strlen(Wrong_Answer3));
  //////////////////////////


  //b = iconv("EUC-KR","UTF-8",*R_Protocol);
  //cout << "--->" << R_Protocol << endl;
  euclen5 = euckr2utf8(receive_Arr, receive_Arr, sizeof(receive_Arr));
  //euclen1 = euckr2utf8(R_Protocol, R_Protocol, sizeof(R_Protocol));
  euclen2 = euckr2utf8(receive_Arr1, receive_Arr1, sizeof(receive_Arr1));
  euclen3 = euckr2utf8(receive_Arr2, receive_Arr2, sizeof(receive_Arr2));
  euclen4 = euckr2utf8(receive_Arr3, receive_Arr3, sizeof(receive_Arr3));
  
  cout << receive_Arr << endl;
  cout << receive_Arr1 << endl;
  cout << receive_Arr2 << endl;
  cout << receive_Arr3 << endl;
  
  cout << "-------------------------------------------" << endl;

  memset(R_voca,0x00,sizeof(R_voca));
  memset(R_mean,0x00,sizeof(R_mean));
  memset(W_mean1,0x00,sizeof(W_mean1));
  memset(W_mean2,0x00,sizeof(W_mean2));
  memset(W_mean3,0x00,sizeof(W_mean3));

  tokenizer(R_voca,R_mean,receive_Arr);
  tokenizer2(W_mean1,receive_Arr1);
  tokenizer2(W_mean2,receive_Arr2);
  tokenizer2(W_mean3,receive_Arr3);
  
  cout << R_voca << "-" << R_mean << endl;
  cout << W_mean1 << endl;
  cout << W_mean2 << endl;
  cout << W_mean3 << endl;

  

  //gtk_init (&argc, &argv);
   gtk_init (NULL, NULL);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);
  //gtk_container_border_width (GTK_CONTAINER (window), 10);
  vbox_1 = gtk_vbox_new(TRUE,0);
  vbox_2 = gtk_vbox_new(TRUE,0);
  vbox_3 = gtk_vbox_new(TRUE,0);
  vbox_4 = gtk_vbox_new(TRUE,0);
  vbox_5 = gtk_vbox_new(TRUE,0);
  hbox_1 = gtk_hbox_new(TRUE,0);
  hbox_2 = gtk_hbox_new(TRUE,0);

  label_Name = gtk_label_new("Name");
  label_Diff = gtk_label_new("Difficult");
  input_Name = gtk_label_new("만들어야함");
  input_Diff = gtk_label_new("만들어야함");
  QuizIntro = gtk_label_new("다음 단어의 뜻을 고르시오.");
  Quiz = gtk_label_new(R_voca);
  Title = gtk_label_new("문제풀이");
  result = gtk_label_new("결과가 떠야함");

  ////////////////////문제 배치////////////////////////////
  srand((unsigned)time(NULL) + (unsigned)getpid());
  k = rand()%4 + 1;
  g_print("%d\n",k);
  button[(k++)%4 + 1] = gtk_button_new_with_label (W_mean1);
  button[(k++)%4 + 1] = gtk_button_new_with_label (W_mean2);
  button[(k++)%4 + 1] = gtk_button_new_with_label (W_mean3);
  button[(k++)%4 + 1] = gtk_button_new_with_label (R_mean);
  AnswerIdx = ((k-1)%4)+1;
  g_print("%d\n",AnswerIdx);
  //////////////////////////////////////////////////////

  gtk_widget_set_size_request(label_Name,200,60);
  gtk_widget_set_size_request(label_Diff,200,60);
  gtk_widget_set_size_request(input_Name,200,60);
  gtk_widget_set_size_request(input_Diff,200,60);
  gtk_widget_set_size_request(Title,100,60);
  gtk_widget_set_size_request(QuizIntro,100,60);
  gtk_widget_set_size_request(Quiz,100,60);
  gtk_widget_set_size_request(button[1],120,10);
  gtk_widget_set_size_request(button[2],120,10);
  gtk_widget_set_size_request(button[3],120,10);
  gtk_widget_set_size_request(button[4],120,10);
  gtk_widget_set_size_request(result,80,50);


  gtk_container_add(GTK_CONTAINER(vbox_1),label_Name);
  gtk_container_add(GTK_CONTAINER(vbox_1),label_Diff);
  gtk_container_add(GTK_CONTAINER(vbox_2),input_Name);
  gtk_container_add(GTK_CONTAINER(vbox_2),input_Diff);
  gtk_container_add(GTK_CONTAINER(vbox_3),Title);
  gtk_container_add(GTK_CONTAINER(vbox_4),QuizIntro);
  gtk_container_add(GTK_CONTAINER(vbox_4),Quiz);
  gtk_container_add(GTK_CONTAINER(vbox_5),result);
  gtk_container_add(GTK_CONTAINER(hbox_2),button[1]);
  gtk_container_add(GTK_CONTAINER(hbox_2),button[2]);
  gtk_container_add(GTK_CONTAINER(hbox_2),button[3]);
  gtk_container_add(GTK_CONTAINER(hbox_2),button[4]);

  
  for(i=1;i<=4;i++)
  {
	  if(i==AnswerIdx)
		gtk_signal_connect (GTK_OBJECT (button[AnswerIdx]), "clicked", G_CALLBACK (correct), NULL);
	  else
		gtk_signal_connect (GTK_OBJECT (button[i]), "clicked", G_CALLBACK (noncorrect), NULL);
  }

  gtk_container_add (GTK_CONTAINER (hbox_1), vbox_1);
  gtk_container_add (GTK_CONTAINER (hbox_1), vbox_2);
  gtk_container_add (GTK_CONTAINER (vbox_3), hbox_1);
  gtk_container_add (GTK_CONTAINER (vbox_3), vbox_4);
  gtk_container_add (GTK_CONTAINER (vbox_3), hbox_2);
  gtk_container_add (GTK_CONTAINER (vbox_3), vbox_5);
  gtk_container_add (GTK_CONTAINER (window), vbox_3);
  gtk_widget_set_usize(window, 600, 300);
  //gtk_widget_show (button);
  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}

