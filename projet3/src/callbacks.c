#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "mery.h"



int t=1;

void
on_paiemente_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
t=1;
}


void
on_paiementc_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
t=2;
}




void
on_continuer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox_hebergement;
GtkWidget  *windowhebergement;
combobox_hebergement=lookup_widget(objet_graphique,"combobox_hebergement");
if (strcmp("Ajouter",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_hebergement)))==0)
{
windowhebergement=create_ajouter();
gtk_widget_show(windowhebergement);}
else if (strcmp("Rechercher",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_hebergement)))==0)
{
windowhebergement=create_rechercher();
gtk_widget_show(windowhebergement);}
else if (strcmp("Modifier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_hebergement)))==0)
{
windowhebergement=create_modifier();
gtk_widget_show(windowhebergement);}
else if (strcmp("Supprimer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_hebergement)))==0)
{
windowhebergement=create_supprimer();
gtk_widget_show(windowhebergement);}
else if (strcmp("Afficher",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_hebergement)))==0)
{
windowhebergement=create_afficher();
gtk_widget_show(windowhebergement);}
}

int et1=0;
int et2=0;
int et3=0;
int et4=0;
void
on_etagerech4_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
et4=1;
}


void
on_etagerech3_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
et3=1;
}


void
on_etagerech2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
et2=1;
}


void
on_etagerech1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
et1=1;
}


void
on_m_rechercher_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
eh e;


GtkWidget *combobox1,*msg1,*msg2,*msg3,*msg4;
combobox1=lookup_widget(button,"spinbutton_rech");
e.numchambre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(combobox1));
msg1=lookup_widget(button,"label_aff_et1");
msg2=lookup_widget(button,"label_aff_et2");
msg3=lookup_widget(button,"label_aff_et3");
msg4=lookup_widget(button,"label_aff_et4");

char *ch1[100];
char *ch2[100];
char *ch3[100];
char *ch4[100];
 
if (et1==1)
{
e.etage=1;
recherche(e);
sprintf(ch1,"%s %s %s %s %d %d",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
gtk_label_set_text(GTK_LABEL(msg1),ch1);
}


if (et2==1)
{
e.etage=2;
recherche(e);
sprintf(ch2,"%s  %s  %s  %s  %d %d",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
gtk_label_set_text(GTK_LABEL(msg2),ch2);
}



if (et3==1)
{
e.etage=3;
recherche(e);
sprintf(ch3,"%s  %s  %s  %s  %d %d",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
gtk_label_set_text(GTK_LABEL(msg3),ch3);
}


if (et4==1)
{
e.etage=4;
recherche(e);
sprintf(ch4,"%s  %s  %s  %s  %d %d",e.nom,e.prenom,e.id,e.paiement,e.etage,e.numchambre);
gtk_label_set_text(GTK_LABEL(msg4),ch4);
}

}





int a=1;

void
on_m_modifier_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
eh e;
GtkWidget  *windowajouter;
GtkWidget *nom1;
GtkWidget *prenom1;
GtkWidget *id1;
GtkWidget *etage1;
GtkWidget *numchambre1;

    
nom1=lookup_widget(button ,"entry_modifier_nom");
prenom1=lookup_widget(button,"entry_modifier_prenom");
id1=lookup_widget(button,"entry_modifier_id");

etage1=lookup_widget(button,"spinbutton_modifier_etage");
numchambre1=lookup_widget(button,"spinbutton_modifier_numchambre");

if (a==1)
strcpy(e.paiement,"especes");
else if (a==2)
strcpy(e.paiement,"chéques");

e.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(etage1));
e.numchambre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numchambre1));

strcpy(e.nom, gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(e.prenom, gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(e.id, gtk_entry_get_text(GTK_ENTRY(id1)));

modifier(e);

}


void
on_m_supprimer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
eh e;
GtkWidget *identifiant;

identifiant = lookup_widget(button,"entry_supprimer");
strcpy(e.id, gtk_entry_get_text(GTK_ENTRY(identifiant)));
supprimer(e);
}


void
on_retour_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter;
windowajouter=create_hebergement();
gtk_widget_show(windowajouter);
}


void
on_retour_rechercher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrech;
windowrech=create_hebergement();
gtk_widget_show(windowrech);
}


void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmod;
windowmod=create_hebergement();
gtk_widget_show(windowmod);
}


void
on_retour_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup;
windowsup=create_hebergement();
gtk_widget_show(windowsup);
}


void
on_retour_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowaff;
windowaff=create_hebergement();
gtk_widget_show(windowaff);
}


void
on_radiobutton_modifier_c_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
a=1;
}


void
on_radiobutton_modifier_e_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
a=2;
}




void
on_m_ajouter_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *windowajouter;
GtkWidget *nom1;
GtkWidget *prenom1;
GtkWidget *id1;
GtkWidget *etage1;
GtkWidget *numchambre1;

eh e;
    
nom1=lookup_widget(button ,"entry_nom");
prenom1=lookup_widget(button,"entry_prenom");
id1=lookup_widget(button,"entry_id");

etage1=lookup_widget(button,"spinbutton_etage");
numchambre1=lookup_widget(button,"spinbutton_numchambre");
if (t==1)
strcpy(e.paiement,"especes");
else if (t==2)
strcpy(e.paiement,"chéques");

e.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(etage1));
e.numchambre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numchambre1));

strcpy(e.nom, gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(e.prenom, gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(e.id, gtk_entry_get_text(GTK_ENTRY(id1)));
ajout(e);

}








void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
treeview=lookup_widget(button,"treeview1");
afficher(treeview);
}




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
eh e;
GtkTreeIter iter;

gchar *nom;
gchar*prenom;
gchar *id;
gint *numchambre;
gint *etage;
gchar *paiement;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&id,3,&paiement,4,&etage,5,&numchambre,-1);
strcpy(e.id,id);
strcpy(e.nom,nom);                      
strcpy(e.prenom,prenom);
strcpy(e.paiement,paiement);
e.etage=etage;
e.numchambre=numchambre;
afficher(treeview);
}
}

