#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "fonction.h"


enum
{
NOM,
ID,
MARQUE,
PRIX,
TYPE,
NBCAPT,
ETAT,
DATE,
COLUMN};


//ajouter le capteur 
void ajouter_capteur(capteur c){
FILE *f;
f=fopen("capteur.txt","a+");
if (f!=NULL)
{ 
fprintf(f,"%s %s %d %s %s %s %s %s \n",c.nom,c.id,c.nbcapt,c.type,c.prix,c.marque,c.etat,c.date);
fclose(f);
}
}

//modifier le capteur 
void modifier_capteur (capteur c )
{

char id;
FILE *f1,*f2;
capteur c2;
f1=fopen("capteur.txt","r");
f2=fopen("capteur1.txt","w+");
while(fscanf(f1,"%s%s%s%s%s%s%d%s\n",c2.id,c2.nom,c2.marque,c2.prix,c2.type,c2.etat,c2.nbcapt,c2.date)!=EOF)
{
if( c2.id!=c.id)
 fprintf(f2,"%s%s%s%s%s%s%d%s\n",c2.id,c2.nom,c2.marque,c2.prix,c2.type,c2.etat,c2.nbcapt,c2.date);
 else 

 fprintf(f2,"%s%s%s%s%s%d%s\n",c.id,c.nom,c.marque,c.prix,c.type,c.etat,c.nbcapt,c.date);
}
fclose(f1);
fclose(f2);
remove("capteur.txt");
rename("capteur1.txt","capteur.txt");
}




int chercher(char id)
{ 
 FILE *f;
 capteur c;
 f=fopen("capteur.txt","r");
 while(fscanf(f,"%s%s%s%s%s%d%s%s\n",c.id,c.nom,c.marque,c.date,c.prix,c.nbcapt,c.etat,c.type))
 {
  if(strcmp(id,c.id)==0)
return 1 ;
 fclose(f);
}
}

void supprimer_capteur (char id[20] )
{
 char ko;
  FILE *f;
  FILE *k;
 capteur c;
  printf("donner le id du capteur a supprimer \n");
  scanf("%s",id);
  k=fopen("capteur1.txt","a");
  f=fopen("capteur.txt","r+"); 
  if(f!=NULL){ while(fscanf(f,"%s %s %s %s %s %d %s %s\n",c.nom,c.marque,c.id,c.date,c.prix,c.nbcapt,c.type,c.etat))
if(strcmp(c.id,id)!=0)
  fprintf(k,"%s %s %s %s %s %d %s %s\n",c.nom,c.marque,c.id,c.date,c.prix,c.nbcapt,c.type,c.etat); 
}
  fclose(f);
  fclose(k);
  remove("capteur.txt");
  rename("capteur1.txt","capteur.txt");
 }  
  
 


void afficher_capteur (GtkWidget* list)
{
  
  FILE *f;
  GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
    	capteur c;
	
  char nom[50] ;
  char id[10] ;
  int nbcapt ;
  char type[50] ;
  char prix[20] ;
  char date [20];
  char marque[50] ;
  char etat [20] ;

   store = NULL;
 
   store = gtk_tree_view_get_model(list);
   if (store==NULL)
{
	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("nbcapt",renderer,"text",NBCAPT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


store =gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("capteur.txt","r");
    if (f==NULL)
    {
      return;
    }
    else {
  while(fscanf(f,"%s %s %d %s %s %s %s %s\n" ,c.id,c.nom,&c.nbcapt,c.marque,c.etat,c.type,c.date,c.prix)!=EOF) {
gtk_list_store_append(store,&iter);
gtk_list_store_set (store,&iter,ID,id,NOM,nom,MARQUE,marque,ETAT,etat,TYPE,type,NBCAPT,nbcapt,DATE,date,PRIX,prix,-1);
} 
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (list), GTK_TREE_MODEL (store));
g_object_unref(store);
}
}
}
 

//// vider tree view
void vider(GtkWidget *list) {
      
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char id[20];
  char nom[50];
  char type[50];
  int nbcapt;
  char marque[20];
  char etat[50];
  char prix[20];
 store=NULL;
 FILE *f;

 store = gtk_tree_view_get_model(list);
 if(store==NULL)
 {    
    
	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("nbcapt",renderer,"text",NBCAPT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);



	renderer = gtk_cell_renderer_text_new();
	   column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

store  =gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
}
}
