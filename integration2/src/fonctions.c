#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>
void ajouter(Menus menu) {  

    
    

  
    
    
     
    FILE *f = NULL;
    f = fopen("Nutritionniste.txt", "a");
    fprintf(f,"%d %d %s %s %s \n", menu.jours, menu.tp, menu.pe,menu.pp,menu.pf);
    fclose(f);
}

void Supprimer(Menus R) {
    
    Menus menu;
    
    FILE *f1=NULL;
    FILE *f2=NULL;

  
    

    f1 = fopen("Nutritionniste.txt","r");
    f2 = fopen("Nutriti_tamp.txt", "a");
    while (fscanf(f1,"%d %d %s %s %s \n", &menu.jours, &menu.tp, menu.pe,menu.pp,menu.pf) !=EOF){
        if (menu.jours != R.jours) {
            fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.tp, menu.pe,menu.pp,menu.pf);
        }
       else if ((menu.tp != R.tp) && (menu.jours == R.jours))
     {fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.tp, menu.pe,menu.pp,menu.pf);}
    }
    fclose(f1);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("Nutriti_tamp.txt", "Nutritionniste.txt");
}

int rechercher(Menus R) {
    
    
    Menus menu;
    
   

    FILE *f = NULL;
    f = fopen("Nutritionniste.txt","r");
    while(fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.tp, menu.pe,menu.pp,menu.pf)!=EOF) {

        if(R.jours==menu.jours){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;

}

void afficher(Menus menu) {

    

    FILE *f = NULL;
    f=fopen("Nutritionniste.txt","r");
    
    while (fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.tp, menu.pe,menu.pp,menu.pf) !=EOF){
    printf("%d %d %s %s %s \n", menu.jours, menu.tp, menu.pe,menu.pp,menu.pf);
        
    }
    fclose(f);
    //return 0;
}


void modifier(Menus new){
    
    
    
    Menus menu;
    FILE *f=NULL;
    FILE *f2=NULL;


    

    
    
    f=fopen("Nutritionniste.txt","r");
    f2=fopen("modif_nut.txt","a");
    while(fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.tp, menu.pe,menu.pp,menu.pf)!=EOF)
    {
    if ((menu.jours == new.jours)&&(menu.tp == new.tp)) {
            fprintf(f2,"%d %d %s %s %s \n", new.jours, new.tp, new.pe,new.pp,new.pf);
        }
        else {
        fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.tp, menu.pe,menu.pp,menu.pf);
        }
    };
    fclose(f);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("modif_nut.txt","Nutritionniste.txt");

    }



void dashboard(char T[]){
    
    
    int jours , plat,i;
    char dechet[50],s1[50],s2[50],s3[50],s4[50];
   
    FILE *f2=NULL;

 
    strcpy(s1,"99.99");
    strcpy(s2,"99.99");
    strcpy(s3,"99.99");
    strcpy(s4,"99.99");

    
    
    
   
    f2=fopen("dechets.txt","r");
     
         while(fscanf(f2,"%d %d %s \n",&jours, &plat , dechet )!=EOF)
    {
        if (jours<8){
        
        if (strcmp(dechet,s1)==-1){
            strcpy(s1,dechet);}}
     if ((jours<15)&&(jours>7)){
       
        if (strcmp(dechet,s2)==-1){
            strcpy(s2,dechet);}}
  if ((jours<22)&&(jours>14)){
        
        if (strcmp(dechet,s3)==-1){
           strcpy( s3,dechet);}}
     if ((jours<31)&&(jours>21)){
          if (strcmp(dechet,s4)==-1){
            strcpy(s4,dechet);}}
    }
    fclose(f2);
   strcpy(T[0],s1);
   strcpy(T[1],s2);
   strcpy(T[2],s3);
   strcpy(T[3],s4);


}
enum
{
JOURS,
TYPE,
ENTREE,
PLAT_PRINCIPAL,
DESSERT,


COLUMNS
};
    
   void afficher_menu(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[100];
 char plat_principal[50];
 char dessert[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat_principal",renderer,"text",PLAT_PRINCIPAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("Nutritionniste.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("Nutritionniste.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s",jours,type,entree,plat_principal,dessert)!=EOF)
    {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT_PRINCIPAL,plat_principal,DESSERT,dessert, -1);

    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}
}

 void vider(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[100];
 char plat_principal[50];
 char dessert[50];

  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat_principal",renderer,"text",PLAT_PRINCIPAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  gtk_list_store_append(store,&iter);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL(store));
}
void rechercher_menu(GtkWidget *liste, char x1[],char x2[],char x3[],char ce[])
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[100];
 char plat_principal[50];
 char dessert[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat_principal",renderer,"text",PLAT_PRINCIPAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("Nutritionniste.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("Nutritionniste.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s",jours,type,entree,plat_principal,dessert)!=EOF)
    {
   if ((strcmp(jours,ce)==0) && (strcmp(x1,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT_PRINCIPAL,plat_principal,DESSERT,dessert, -1);
}
   if ((strcmp(jours,ce)==0) && (strcmp(x2,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT_PRINCIPAL,plat_principal,DESSERT,dessert, -1);
}
   if ((strcmp(jours,ce)==0) && (strcmp(x3,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT_PRINCIPAL,plat_principal,DESSERT,dessert, -1);
}
    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
   
}
}
enum{
JOUR,
PLAT,
DECHETS,
NB_COLUMNS
};
 void afficher_Dash(GtkWidget *liste,int c)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jour[50];
 char plat[50];
float dechets;

    
    
    int jours , platt,i;
    float dechet,s1,s2,s3,s4;
   float T[50];
    FILE *f2=NULL;

  
    s1=1000.00;
    s2=1000.00;
    s3=1000.00;
    s4=1000.00;

    
    
    
   
    f2=fopen("dechets.txt","r");
     
         while(fscanf(f2,"%d %d %f \n",&jours, &platt , &dechet )!=EOF)
    {
        if (jours<8){
        
        if (dechet<s1){
            s1=dechet;}}
     if ((jours<15)&&(jours>7)){
       
        if (dechet<s2){
            s2=dechet;}}
  if ((jours<22)&&(jours>14)){
        
        if (dechet<s3){
            s3=dechet;}}
     if ((jours<31)&&(jours>21)){
          if (dechet<s4){
            s4=dechet;}}
    }
    fclose(f2);
   T[0]=s1;
T[1]=s2;
T[2]=s3;
T[3]=s4;
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("plat",renderer,"text",PLAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dechets",renderer,"text",DECHETS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   



  }
  store=gtk_list_store_new(NB_COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("dechets.txt", "a");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("dechets.txt", "a+");
   while(fscanf(f,"%s %s %f",jour, plat , &dechets )!=EOF)
    {
    if (( c==1)&& (dechets==T[0])){
  
  
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS, &dechets, -1);}
   if (( c==2)&&(dechets==T[1])) {

   
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS, &dechets, -1);}
   if (( c==3) && (dechets==T[2])){
     gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS, &dechets, -1);}
   if (( c==4)&&(dechets==T[3])) {

  
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS, &dechets, -1);}



    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}
}
