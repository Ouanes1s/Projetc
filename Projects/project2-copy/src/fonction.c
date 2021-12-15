#ifdef HAVE_CONFIG_Hom
#include <config.h>
#endif
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "fonction.h"

enum   
{ 
	NOM,
	PRENOM,
        ID,	
	PASSWORD,
	ROLE,
        NIV,
        JOUR,
        MOIS,
        ANNEE,
	COLUMNS,
};



void ajouter_utilisateur(utilisateur p)
{
  FILE *f;
  f=fopen("utilisateur.txt","a+");
  if(f!=NULL) 
{
  fprintf(f,"%s %s %s %s %s  %s %d %d %d",p.nom,p.prenom,p.id,p.password,p.role,p.niv,&p.jour,&p.mois,&p.annee);
  fclose(f);
}}


void afficher_utilisateur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
        char nom[50];
        char prenom[50];
        char id;
        char password[50];
        char role[50];
        char niv;
        int jour;
	int mois;
	int annee;
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id",renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("password",renderer, "text",PASSWORD, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("role",renderer, "text",ROLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("niveau",renderer, "text",NIV, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);		
		renderer = gtk_cell_renderer_text_new ();

		column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();

		column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();

		column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen("utilsateur1.txt","r");

		if(f==NULL){return;}
		else
		{
			f = fopen("utilisateur1.txt","a+");
			while(fscanf(f,"%s %s %s %s %s  %s %d %d %d\n",nom,prenom,id,password,role,niv,&jour,&mois,&annee)!=EOF)
			{

		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, ID, id, PASSWORD, password, ROLE, role, NIV, niv, JOUR,jour,MOIS,mois,ANNEE,annee);
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}


void modifier_utilisateur(utilisateur p)
{
    FILE*f;
    FILE*c;
    utilisateur e;
    f=fopen("utilisateur.txt","r");
    c=fopen("tmp.txt","w");

    if(f!=NULL)
    { if(c!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee)!=EOF)
        {
            if(strcmp(p.id,e.id)!=0)
            {fprintf(c,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee); }
            else
            { fprintf(c,"%s %s %s %s %s %s %d %d %d\n",p.nom,p.prenom,p.id,p.password,p.role,p.niv,&p.jour,&p.mois,&p.annee);}
        }
        fclose(f);
        fclose(c);
remove("utilisateur.txt");
rename("tmp.txt","utilisateur.txt");

    }
    }

}

void supprimer_utilisateur(utilisateur p)
{
    utilisateur e;
    FILE*f;
    FILE*c;
    f=fopen("utilisateur.txt","r");
    c=fopen("tmp.txt","w");
    if(f==NULL || c==NULL){return;}
    else{

        while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee)!=EOF)
        {

            if(strcmp(p.id,e.id)!=0)
            {fprintf(c,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee);}
    
fclose(f);
fclose(c);
remove("utilisateur.txt");
rename("tmp.txt","utilisateur.txt");
}
}
}


utilisateur rechercher_utilisateur(utilisateur p)
{
    FILE*f;

    utilisateur e;
    

    f=fopen("utilisateur.txt","r");
    if(f!=NULL){
     while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee)!=EOF)
    {
        if(strcmp(p.id,e.id)!=0)
        {
	 return e;
         fclose(f);

	}}}
	    

int nb_niveau( utilisateur p)
{
    FILE*f;
    int pr,d,t,q,c;
    pr=d=t=q=c=0;

    f=fopen("utilisateur.txt","r");
    if(f!=NULL)
    {
     while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",e.nom,e.prenom,e.id,e.password,e.role,e.niv,&e.jour,&e.mois,&e.annee)!=EOF)
    {
        if(strcmp(p.niv,"1")==0){pr+=1;}
        if(strcmp(p.niv,"2")==0){d+=1;}
        if(strcmp(p.niv,"3")==0){t+=1;}
        if(strcmp(p.niv,"4")==0){q+=1;}
        if(strcmp(p.niv,"5")==0){c+=1;}
        fclose(f);
	}}

        printf("le nombre des étudiants en 1ère année est %d",pr);
        printf("le nombre des étudiants en 2ème année est %d",d);
        printf("le nombre des étudiants en 3ème année est %d",t);
        printf("le nombre des étudiants en 4ème année est %d",q);
        printf("le nombre des étudiants en 5ème année est %d",c);

}


