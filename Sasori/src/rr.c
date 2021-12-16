#include <stdio.h>
#include <string.h>
#include "rr.h"
#include <gtk/gtk.h>

enum{
        EID,
        ENOM,
        EMAIL,
	ETEL,
	EPROBLEME,
        ECOLUMNS,
    };
///////////////////////////////////////////////////////////////////////////
void ajouter_RR(Restauration c)
{
FILE *f;
f= fopen("Restauration.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",c.id,c.nom,c.email,c.tel,c.probleme);
fclose(f);
}
}
///////////////////////////////////////////////////////////////////////////
void supprimer_RR(char id[])
{
Restauration c;
FILE *f, *g;
	f=fopen("Restauration.txt","r");
	g=fopen("Restauration2.txt","a");

	if(f==NULL || g==NULL)
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s \n",c.id,c.nom,c.email,c.tel,c.probleme)!=EOF)
	{
	if (strcmp(id,c.id)!=0 ){
		fprintf(g,"%s %s %s %s %s \n",c.id,c.nom,c.email,c.tel,c.probleme);}
	}
	fclose(f);
	fclose(g);
	remove("Restauration.txt");
	rename("Restauration2.txt","Restauration.txt");
	}
}
///////////////////////////////////////////////////////////////////////////
void modifier_RR( Restauration c)
{
	Restauration h;
	FILE *f, *g;
	f=fopen("Restauration.txt","r");
	g=fopen("Restauration2.txt","a");
	if (f!=NULL && g!=NULL) {
		while(fscanf(f,"%s %s %s %s %s \n",h.id,h.nom,h.email,h.tel,h.probleme)!=EOF)
			{ if(strcmp(c.id,h.id)==0){
				fprintf(g,"%s %s %s %s %s \n",c.id,c.nom,c.email,c.tel,c.probleme);}
			else{
				fprintf(g,"%s %s %s %s %s \n",h.id,h.nom,h.email,h.tel,h.probleme);}
			}
		}
	fclose(f);
	fclose(g);
	remove("Restauration.txt");
	rename("Restauration2.txt","Restauration.txt");
}
///////////////////////////////////////////////////////////////////////////
void afficher_RR(GtkWidget *liste)
{
GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
       
        char id[100];
	char nom[100];
	char email[100];
	char tel[20];
	char probleme[100];
     
        FILE *f;
        store = NULL;
        store = gtk_tree_view_get_model(liste);

        if(store == NULL){

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("mail",renderer,"text",EMAIL,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	    renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",ETEL,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer = gtk_cell_renderer_text_new();
            column = gtk_tree_view_column_new_with_attributes("probleme",renderer,"text",EPROBLEME,NULL);
            column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        }
    store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
       
       
        f = fopen("Restauration.txt","r");
    if(f == NULL){
            return;
        }
    else{
            while(fscanf(f,"%s %s %s %s %s \n",id,nom,email,tel,probleme) != EOF){            
    gtk_list_store_append(store,&iter);
                gtk_list_store_set(store,&iter,EID,id,ENOM,nom,EMAIL,email,ETEL,tel,EPROBLEME,probleme,-1);
               
            }
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
            fclose(f);
        }
       
    }
///////////////////////////////////////////////////////////////////////////
int rechercher_id(char id[]){
    Restauration y;
    FILE *f;
    f = fopen("Restauration.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s \n",y.id,y.nom,y.email,y.tel,y.probleme) != EOF){
        	if(strcmp(y.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
    

}
///////////////////////////////////////////////////////////////////////////


