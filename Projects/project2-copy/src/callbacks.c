#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
//#include "fonction.h"
#include "fonction.c"

utilisateur p1;
utilisateur p2;
int choix1;
int choix2;

void
on_radioetudiant_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix1=1;}
}

void
on_radioenseignant_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix1=2;}
}

void
on_radioparent_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix1=3;}
}





void
on_sign_up_button_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Nom,*Prenom,*ID,*Password,*Niveau,*Jour,*Mois,*Annee;
GtkWidget *ajout_utilisateur ();
utilisateur p1;

Nom=lookup_widget(objet_graphique,"uentry3");
Prenom=lookup_widget(objet_graphique,"uentry4");
ID=lookup_widget(objet_graphique,"uentry5");

Jour=lookup_widget(objet_graphique,"uspinbutton1");
Mois=lookup_widget(objet_graphique,"uspinbutton2");
Annee=lookup_widget(objet_graphique,"uspinbutton3");
Password=lookup_widget(objet_graphique,"uentry8");

Niveau=lookup_widget(objet_graphique,"ucomboboxentry1");
strcpy(p1.nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
strcpy(p1.prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
strcpy(p1.id,gtk_entry_get_text(GTK_ENTRY(ID)));
p1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
strcpy(p1.password,gtk_entry_get_text(GTK_ENTRY(Password)));
strcpy(p1.niv,gtk_entry_get_text(GTK_ENTRY(Niveau)));
if(choix1==1){strcpy(p1.role,"étudiant");}	 
else if(choix1==2){strcpy(p1.role,"enseignant");} 
else if(choix1==3){strcpy(p1.role,"parent");}  

ajouter_utilisateur(p1);

}



void
on_ucheckbutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix2=1;}
}


void
on_ucheckbutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix2=2;}
}


void
on_ucheckbutton3_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {choix2=3;}
}






void
on_button_modif_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *Nom2,*Prenom2,*ID2,*Password2,*Niveau2;

utilisateur p2;

Nom2=lookup_widget(objet_graphique,"entry_nom");
Prenom2=lookup_widget(objet_graphique,"entry_prenom");
ID2=lookup_widget(objet_graphique,"entry_uid");
Password2=lookup_widget(objet_graphique,"entry_mdp");

Niveau2=lookup_widget(objet_graphique,"ucomboboxentry2");
strcpy(p2.nom,gtk_entry_get_text(GTK_ENTRY(Nom2)));
strcpy(p2.prenom,gtk_entry_get_text(GTK_ENTRY(Prenom2)));
strcpy(p1.id,gtk_entry_get_text(GTK_ENTRY(ID2)));
strcpy(p1.password,gtk_entry_get_text(GTK_ENTRY(Password2)));
strcpy(p1.niv,gtk_entry_get_text(GTK_ENTRY(Niveau2)));
if(choix2==1){strcpy(p2.role,"étudiant");}	 
else if(choix2==2){strcpy(p2.role,"enseignant");} 
else if(choix2==3){strcpy(p2.role,"parent");}  

modifier_utilisateur(p2);
}


void
on_button_recherche_utilisateur_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *Id3;
 char id3;

Id3=lookup_widget(objet_graphique,"uentry8");
strcpy(p1.id,gtk_entry_get_text(GTK_ENTRY(Id3)));
rechercher_utilisateur(p1);
}


void
on_button_modifier_utilisateur_clicked (GtkButton       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *windowmodification;
windowmodification=create_modification ();
gtk_widget_show(windowmodification);
}












void
on_afficher_utilisateur_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *ajout_utilisateur;
GtkWidget *affichage_et_recherche;
GtkWidget *treeview1;
ajout_utilisateur=lookup_widget(objet_graphique,"ajout_utilisateur");
gtk_widget_destroy(ajout_utilisateur);
affichage_et_recherche=lookup(objet_graphique,"affichage_et_recherche");
affichage_et_recherche=create_affichage_et_recherche ();
gtk_widget_show(affichage_et_recherche);
treeview1=lookup_widget(affichage_et_recherche,"treeview1");
afficher_utilisateur(treeview1);
}


void
on_utreeview1_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
GtkTreeIter iter;
utilisateur p;
gchar *nom;
gchar *prenom;
gchar *id;
gchar *password;
gchar *role;
gchar *niv;
gint *jour;
gint *mois;
gint *annee;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,nom,1,prenom,2,id,3,password,4,role,5,niv,6,jour,7,mois,8,annee,-1);
supprimer_utilisateur(p);
afficher_utilisateur(treeview);
create_affichage_et_recherche ;
}
}




void
on_button_actualiser_utilisateur_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage_et_recherche,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"affichage_et_recherche");
affichage_et_recherche=create_affichage_et_recherche ();
gtk_widget_show(affichage_et_recherche);
gtk_widget_hide(w1);
treeview1=lookup_widget(affichage_et_recherche,"treeview1");
vider(treeview1);
afficher_utilisateur(treeview1);
}


void
on_return_login_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout_utilisateur ,*affichage_et_recherche;
affichage_et_recherche=lookup_widget(affichage_et_recherche,"affichage_et_recherche");
gtk_widget_destroy(affichage_et_recherche);
ajout_utilisateur=create_ajout_utilisateur ();
gtk_widget_show(ajout_utilisateur);
}}






