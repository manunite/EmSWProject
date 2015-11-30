
#include <gtk/gtk.h>

gboolean OnWindowDeleteEvent(GtkWidget* widget, GdkEventAny* event, gpointer data)
{
 /*return false so that window will be destroyed*/
 return FALSE;
}

void OnWindowDestroy(GtkObject* object, gpointer data)
{
 /*exit main loop*/
 gtk_main_quit();
}


void OnNotebookSwitchPage(GtkNotebook* notebook, GtkNotebookPage* page, gint pageNum, gpointer data)
{
 GtkWidget* child;
 GtkWidget* tabLabel;
 gchar* pageName;
   
 /*get page name*/
 child = gtk_notebook_get_nth_page(notebook, pageNum);
 tabLabel = gtk_notebook_get_tab_label(notebook, child);
 gtk_label_get(GTK_LABEL(tabLabel), &pageName);
 
 /*Print info*/
 g_print("Switched to page %d\n", pageNum);
 g_print("New page's name is %s\n", pageName);
 g_print("\n");
}

void OnButtonNextClicked(GtkWidget* button, gpointer data)
{
 GtkWidget* notebook;
   
 /*cast data to a GtkWidget*/
 notebook = (GtkWidget*)data;
 
 /*move to the next page*/
 gtk_notebook_next_page(GTK_NOTEBOOK(notebook));
}

void OnButtonPrevClicked(GtkWidget* button, gpointer data)
{
 GtkWidget* notebook;
   
 /*cast data to a GtkWidget*/
 notebook = (GtkWidget*)data;
 
 /*move to the previous page*/
 gtk_notebook_prev_page(GTK_NOTEBOOK(notebook));
}

void OnButtonInfoClicked(GtkWidget* button, gpointer data)
{
 gint pageNum;
 GtkWidget* notebook;
 GtkWidget* childLabel;
 GtkWidget* tabLabel;
 GtkWidget* menuLabel;
 gchar* tabLabelText;
 gchar* menuLabelText;
 gchar* childLabelText;
   
 /*cast data to a GtkWidget*/
 notebook = (GtkWidget*)data;
 
 /*get the current page*/
 pageNum = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
 
 /*get current page's labels*/
 childLabel = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), pageNum);
 tabLabel = gtk_notebook_get_tab_label(GTK_NOTEBOOK(notebook), childLabel);
 menuLabel = gtk_notebook_get_menu_label(GTK_NOTEBOOK(notebook), childLabel);
 if(menuLabel == NULL)
  menuLabel = tabLabel; /*No menu label was placed on this page,
         default menu label matches tab label*/
     
 /*get label text*/
 gtk_label_get(GTK_LABEL(tabLabel), &tabLabelText);
 gtk_label_get(GTK_LABEL(menuLabel), &menuLabelText);
 gtk_label_get(GTK_LABEL(childLabel), &childLabelText);
 
 /*print page info*/
 g_print("Page number: %d\n", pageNum);
 g_print("Tab Label: %s\n", tabLabelText);
 g_print("Menu Label: %s\n", menuLabelText);
 g_print("Child Label: %s\n", childLabelText);
 g_print("\n");
}

void OnButtonRemoveClicked(GtkWidget* button, gpointer data)
{
 gint pageNum;
 GtkWidget* notebook;
   
 /*cast data to a GtkWidget*/
 notebook = (GtkWidget*)data;
 
 /*get the current page number*/
 pageNum = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
 
 /*remove the page*/
 gtk_notebook_remove_page(GTK_NOTEBOOK(notebook), pageNum);
}

void OnButtonReorderClicked(GtkWidget* button, gpointer data)
{
 gint pageNum;
 GtkWidget* page;
 GtkWidget* notebook;
   
 /*cast data to a GtkWidget*/
 notebook = (GtkWidget*)data;
 
 /*get the current page number*/
 pageNum = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
 page = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), pageNum);
 
 /*make the current page the first*/
 gtk_notebook_reorder_child(GTK_NOTEBOOK(notebook), page, 0);
}

int main(int argc, char** argv)
{
 GtkWidget* window;  
 GtkWidget* vbox; 
 GtkWidget* hbox; 
 GtkWidget* notebook; /*the notebook widget*/
 
 GtkWidget* buttonPrev; /*buttons*/
 GtkWidget* buttonNext; 
 GtkWidget* buttonInfo;
 GtkWidget* buttonRemove;
 GtkWidget* buttonReorder;
 
 GtkWidget* label1;  /*notbook page tab labels*/
 GtkWidget* label2;
 GtkWidget* label3;
 
 GtkWidget* child1;  /*notebook page widgets*/
 GtkWidget* child2;
 GtkWidget* child3;
 
 GtkWidget* menu3; /*pop up menu label for page 3*/
 
 /*init gtk+*/
 gtk_init(&argc, &argv);
 
 /*create a window, set its title and hook up signal handlers (the usual stuff)*/
 window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window), "Notebook Example");
 gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
 gtk_signal_connect(GTK_OBJECT(window), "delete-event", GTK_SIGNAL_FUNC(OnWindowDeleteEvent), NULL);
 gtk_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(OnWindowDestroy), NULL);
 
 /*create a vertical box to hold child widgets and pack it into the window*/
 vbox = gtk_vbox_new(FALSE, 0);
 gtk_container_add(GTK_CONTAINER(window), vbox);
 
 /*create a horizontal box for the buttons and pack into vertical box*/
 hbox = gtk_hbox_new(TRUE, 0);
 gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
 
 /*create a notebook and pack it into the vertical box*/
 //----- 노트를 만든다. -----//
  notebook = gtk_notebook_new();
 gtk_box_pack_start(GTK_BOX(vbox), notebook, TRUE, TRUE, 0);
 
 //----- 노트 손잡이를 윈도우의 아래쪽으로 옮긴다. -----//
 gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
 
 //----- 노트 손잡이들을 같은 크기로... -----//
 gtk_notebook_set_homogeneous_tabs(GTK_NOTEBOOK(notebook), TRUE);
 
 //----- 노트 위젯 팝업 메뉴 활성화 -----//
 gtk_notebook_popup_enable(GTK_NOTEBOOK(notebook));
 
 //----- 노트에 페이지를 넣는다. -----//
 child1 = gtk_label_new("This is notebook page #1");
 label1 = gtk_label_new("Page one");
 gtk_notebook_append_page(GTK_NOTEBOOK(notebook), child1, label1);
 gtk_notebook_set_tab_label_packing(GTK_NOTEBOOK(notebook), child1, FALSE, FALSE, GTK_PACK_START);
 child3 = gtk_label_new("This is notebook page #3");
 label3 = gtk_label_new("Page three");
 menu3 = gtk_label_new("Goto page 3");
 gtk_notebook_append_page_menu(GTK_NOTEBOOK(notebook), child3, label3, menu3);

 //----- 중간에 페이지2를 넣기... -----//
 child2 = gtk_label_new("This is notebook page #2");
 label2 = gtk_label_new("Page two");
 gtk_notebook_insert_page(GTK_NOTEBOOK(notebook), child2, label2, 1);
 
 /*connect to notebook's "switch-page" signal*/
 gtk_signal_connect(GTK_OBJECT(notebook), "switch-page",
    GTK_SIGNAL_FUNC(OnNotebookSwitchPage), (gpointer)notebook);
 
 /*create buttons, pack into horizontal box and connect signals*/
 buttonPrev = gtk_button_new_with_label("Prev");
 gtk_box_pack_start(GTK_BOX(hbox), buttonPrev, TRUE, TRUE, 0);
 gtk_signal_connect(GTK_OBJECT(buttonPrev), "clicked",
    GTK_SIGNAL_FUNC(OnButtonPrevClicked), (gpointer)notebook);

 buttonNext = gtk_button_new_with_label("Next");
 gtk_box_pack_start(GTK_BOX(hbox), buttonNext, TRUE, TRUE, 0);
 gtk_signal_connect(GTK_OBJECT(buttonNext), "clicked",
    GTK_SIGNAL_FUNC(OnButtonNextClicked), (gpointer)notebook);
 
 buttonInfo = gtk_button_new_with_label("Info");
 gtk_box_pack_start(GTK_BOX(hbox), buttonInfo, TRUE, TRUE, 0);
 gtk_signal_connect(GTK_OBJECT(buttonInfo), "clicked",
    GTK_SIGNAL_FUNC(OnButtonInfoClicked), (gpointer)notebook);
 
 buttonRemove = gtk_button_new_with_label("Remove");
 gtk_box_pack_start(GTK_BOX(hbox), buttonRemove, TRUE, TRUE, 0);
 gtk_signal_connect(GTK_OBJECT(buttonRemove), "clicked",
    GTK_SIGNAL_FUNC(OnButtonRemoveClicked), (gpointer)notebook);
 
 buttonReorder = gtk_button_new_with_label("Reorder");
 gtk_box_pack_start(GTK_BOX(hbox), buttonReorder, TRUE, TRUE, 0);
 gtk_signal_connect(GTK_OBJECT(buttonReorder), "clicked",
    GTK_SIGNAL_FUNC(OnButtonReorderClicked), (gpointer)notebook);
  
 /*show the window and all child widgets*/
 gtk_widget_show_all(window);
  
 /*enter main loop*/
 gtk_main();
 
 return 0;
}
