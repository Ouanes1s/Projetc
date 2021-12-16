#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mery.h"
#include <gtk/gtk.h>
void mery_ajout (eh e)
{
    FILE *f;
    

    // ouvrir le fichier :
f=fopen("etudiant_heberge.txt","a+");
if (f!=NULL)
{
// ecrire dans le ficher
fprintf(f,"%s %s %s %s %d %d \n",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
fclose(f);
}
else
printf("\n not found");


}


 void mery_supprimer(eh e)
{
FILE *f;
FILE *f1;
eh tab;

// ouvrir le fichier :
f1=fopen("modif.txt","a+");
f=fopen("etudiant_heberge.txt","a+");

if (f!=NULL)
    while(fscanf(f,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,&tab.etage,&tab.numchambre)!=EOF)
{
    if (strcmp(tab.id,e.id)!=0)
   {
   fprintf(f1,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,tab.etage,tab.numchambre);
   }
}
fclose(f1);
fclose(f);
remove("etudiant_heberge.txt");
rename("modif.txt","etudiant_heberge.txt");
}


    void mery_modifier(eh e)
{
FILE *f;
FILE *f1;
eh tab;
// ouvrir le fichier :
f1=fopen("modif.txt","a+");

f=fopen("etudiant_heberge.txt","a+");

if (f!=NULL)
while(fscanf(f,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,&tab.etage,&tab.numchambre)!=EOF)
{
     if (strcmp(tab.id,e.id)==0)
   {
    fprintf(f1,"%s %s %s %s %d %d \n",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
   }
else
    {
    fprintf(f1,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,tab.etage,tab.numchambre);}

}
fclose(f1);
fclose(f);
remove("etudiant_heberge.txt");
rename("modif.txt","etudiant_heberge.txt");
}


void mery_recherche(eh e)
{
FILE *f;
eh tab;
f=fopen("etudiant_heberge.txt","a+");


while(fscanf(f,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,&tab.etage,&tab.numchambre)!=EOF)
{
     if ((tab.etage==e.etage) && (tab.numchambre==e.numchambre))
   { 
        strcpy(e.nom,tab.nom);
	strcpy(e.prenom,tab.prenom);
	strcpy(e.id,tab.id);	
 	strcpy(e.paiement,tab.paiement);
   }
}
fclose(f);
}


enum
{
	nom,
	prenom,
	id,
	paiement,
	etage,
	numchambre,
	COLUMNO

};

void mery_afficher(GtkTreeView *liste)
{

eh tab;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=gtk_tree_view_get_model(liste);

FILE *f;
if(store==NULL)
	{

		renderer = gtk_cell_renderer_text_new();	
		column = gtk_tree_view_column_new_with_attributes("id",renderer, "text",id, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",nom, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",prenom, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("paiement",renderer, "text",paiement, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text",etage, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("numchambre",renderer, "text",numchambre, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		


		
	store=gtk_list_store_new(COLUMNO, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING );

f=fopen("etudiant_heberge.txt","a+");

if (f==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %d %d \n",tab.nom,tab.prenom,tab.id,tab.paiement,&tab.etage,&tab.numchambre)!=EOF)
{
gtk_list_store_append(store, &iter);
       gtk_list_store_set(store,&iter, nom,tab.nom,prenom,tab.prenom,id,tab.id,paiement,tab.paiement,etage, tab.etage,numchambre,tab.numchambre,-1);  
}

fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}
}
}
