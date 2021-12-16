#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "rh.h"
#include "rr.h"

//////////////////////////////////////////////////////////////////////////////////////////
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview1;

	window1 = lookup_widget(button,"acceuil");
	window2 = create_RH (); //RH
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview1=lookup_widget(window2,"treeview1");
	afficher_RH(treeview1);
	
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview2;
	window1 = lookup_widget(button,"acceuil");
	window2 = create_RR (); //RR
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview2=lookup_widget(window2,"treeview2");
	afficher_RR(treeview2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RH");
	window2 = create_acceuil ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RR");
	window2 = create_acceuil ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Modifier_RH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RH");
	window2 = create_M_RH ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Modifier_RR_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RR");
	window2 = create_M_RR ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Retour_M_RH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview1;
	window1 = lookup_widget(button,"M_RH");
	window2 = create_RH (); //RH
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview1=lookup_widget(window2,"treeview1");
	afficher_RH(treeview1);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Retour_M_RR_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview2;
	window1 = lookup_widget(button,"M_RR");
	window2 = create_RR (); //RR
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview2=lookup_widget(window2,"treeview2");
	afficher_RR(treeview2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Ajouter_RH_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RH");
	window2 = create_A_RH (); //A_RH
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Ajouter_RR_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"RR");
	window2 = create_A_RR (); //A_RR
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Retour_A_RH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview1;
	window1 = lookup_widget(button,"A_RH");
	window2 = create_RH (); //RH
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview1=lookup_widget(window2,"treeview1");
	afficher_RH(treeview1);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_Retour_A_RR_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview2;
	window1 = lookup_widget(button,"A_RR");
	window2 = create_RR (); //RR
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview2=lookup_widget(window2,"treeview2");
	afficher_RR(treeview2);
}

//////////////////////////////////////////////////////////////////////////////////////////

void
on_reclamer_RH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	Hebergement h;

	GtkWidget *entry1,*entry2,*entry3,*entry4,*entry5;
	GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(button,"A_RH");

	entry1 = lookup_widget(button,"entry1");
	entry2 = lookup_widget(button,"entry2");
	entry3 = lookup_widget(button,"entry3");
	entry4 = lookup_widget(button,"entry4");
	entry5 = lookup_widget(button,"entry5");

	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
	strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(entry2)));
	strcpy(h.email,gtk_entry_get_text(GTK_ENTRY(entry3)));
	strcpy(h.tel,gtk_entry_get_text(GTK_ENTRY(entry4)));
	strcpy(h.probleme,gtk_entry_get_text(GTK_ENTRY(entry5)));

	ajouter_RH(h);


	window2=lookup_widget(button,"f_OKH");

	window2=create_f_OKH ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);


}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_OKH_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview1;
	window1 = lookup_widget(button,"f_OKH");
	window2 = create_RH (); //RH
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview1=lookup_widget(window2,"treeview1");
	afficher_RH(treeview1);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_OKF_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview2;
	window1 = lookup_widget(button,"f_OKR");
	window2 = create_RR (); //RR
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

		
	treeview2=lookup_widget(window2,"treeview2");
	afficher_RR(treeview2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_reclamer_RR_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	Restauration r;

	GtkWidget *entry6,*entry7,*entry8,*entry9,*entry10;
	GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(button,"A_RR");

	entry6 = lookup_widget(button,"entry6");
	entry7 = lookup_widget(button,"entry7");
	entry8 = lookup_widget(button,"entry8");
	entry9 = lookup_widget(button,"entry9");
	entry10 = lookup_widget(button,"entry10");

	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(entry6)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entry7)));
	strcpy(r.email,gtk_entry_get_text(GTK_ENTRY(entry8)));
	strcpy(r.tel,gtk_entry_get_text(GTK_ENTRY(entry9)));
	strcpy(r.probleme,gtk_entry_get_text(GTK_ENTRY(entry10)));

	ajouter_RR(r);


	window2=lookup_widget(button,"f_OKR");

	window2=create_f_OKR ();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* email;
	gchar* tel;
	gchar* probleme;
	Hebergement h;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter , path)) {
	//obtention des valuers de la ligne selectionée

	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1,&nom, 2,&email, 3,&tel, 4,&probleme, -1);
	strcpy(h.id,id);
	strcpy(h.nom,nom);
	strcpy(h.email,email);
	strcpy(h.tel,tel);
	strcpy(h.probleme,probleme);
	supprimer_RH( h.id);
	afficher_RH( treeview);

	}
}

//////////////////////////////////////////////////////////////////////////////////////////
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* email;
	gchar* tel;
	gchar* probleme;
	Restauration h;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter , path)) {
	//obtention des valuers de la ligne selectionée

	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1,&nom, 2,&email, 3,&tel, 4,&probleme, -1);
	strcpy(h.id,id);
	strcpy(h.nom,nom);
	strcpy(h.email,email);
	strcpy(h.tel,tel);
	strcpy(h.probleme,probleme);
	supprimer_RR( h.id);
	afficher_RR( treeview);

	}
}


void
on_modifier_RH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	Hebergement h;
	char x[100];

	GtkWidget *entry11,*entry12,*entry13,*entry14,*entry15;
	GtkWidget *window1;
	GtkWidget *label24;

	window1=lookup_widget(button,"M_RH");

	entry11 = lookup_widget(button,"entry11");
	entry12 = lookup_widget(button,"entry12");
	entry13 = lookup_widget(button,"entry13");
	entry14 = lookup_widget(button,"entry14");
	entry15 = lookup_widget(button,"entry15");
	label24 = lookup_widget(button,"label24");
	
	strcpy(x,gtk_entry_get_text(GTK_ENTRY(entry11)));

	if (rechercher_id_H(x)==1){
		strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(entry11)));
		strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(entry12)));
		strcpy(h.email,gtk_entry_get_text(GTK_ENTRY(entry13)));
		strcpy(h.tel,gtk_entry_get_text(GTK_ENTRY(entry14)));
		strcpy(h.probleme,gtk_entry_get_text(GTK_ENTRY(entry15)));

		modifier_RH(h);	
	}

	if (rechercher_id_H(x)==0){
		strcpy(label24,"non");
	}

}


void
on_modifier_RR_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	/*Restauration r;
	char x[100];

	GtkWidget *entry16,*entry17,*entry18,*entry19,*entry20;
	GtkWidget *window1;
	GtkWidget *label30;

	window1=lookup_widget(button,"M_RR");

	entry16 = lookup_widget(button,"entry16");
	entry17 = lookup_widget(button,"entry17");
	entry18 = lookup_widget(button,"entry18");
	entry19 = lookup_widget(button,"entry19");
	entry20 = lookup_widget(button,"entry20");
	label30 = lookup_widget(button,"label30");
	
	strcpy(x,gtk_entry_get_text(GTK_ENTRY(entry16)));

	if (rechercher_id_R(x)==1){
		strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(entry16)));
		strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entry17)));
		strcpy(r.email,gtk_entry_get_text(GTK_ENTRY(entry18)));
		strcpy(r.tel,gtk_entry_get_text(GTK_ENTRY(entry19)));
		strcpy(r.probleme,gtk_entry_get_text(GTK_ENTRY(entry20)));

		modifier_RR(r);	
	}

	if (rechercher_id_R(x)==0){
		strcpy(label30,"non");
	}*/
}

