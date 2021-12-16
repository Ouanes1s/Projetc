#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "fonction.h"

#include "login.c"
int choix = 0 ;
int p;
char x1[20];
char x2[20];
char x3[20];

void
on_Super1_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login_bienvenue;
Login_bienvenue=lookup_widget(button,"Login_bienvenue");
Login_bienvenue=create_Login_bienvenue();
gtk_widget_show(Login_bienvenue);
}


void
on_Super2_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
Acceuil=lookup_widget(button,"Acceuil");
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
Gestion=lookup_widget(button,"Gestion");
Gestion=create_Gestion();
gtk_widget_show(Gestion);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Dashboard2;
Dashboard2=lookup_widget(button,"Dashboard2");
Dashboard2=create_Dashboard2();
gtk_widget_show(Dashboard2);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter;
GtkWidget *Gestion;
Gestion=lookup_widget(button,"Gestion");
gtk_widget_destroy(Gestion);
Ajouter=lookup_widget(button,"Ajouter");
Ajouter=create_Ajouter();
gtk_widget_show(Ajouter);
}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier;
GtkWidget *Gestion;
Gestion=lookup_widget(button,"Gestion");
gtk_widget_destroy(Gestion);
Modifier=lookup_widget(button,"Modifier");
Modifier=create_Modifier();
gtk_widget_show(Modifier);
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *Gestion;
Gestion=lookup_widget(button,"Gestion");
gtk_widget_destroy(Gestion);
supprimer=lookup_widget(button,"supprimer");
supprimer=create_supprimer();
gtk_widget_show(supprimer);
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
GtkWidget *Afficher;
GtkWidget *treeview1;
Gestion=lookup_widget(button,"Gestion");
gtk_widget_destroy(Gestion);
Afficher=lookup_widget(button,"Afficher");
Afficher=create_Afficher();
gtk_widget_show(Afficher);
treeview1=lookup_widget(Afficher,"treeview1");
afficher_menu(treeview1);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Gestion;
Gestion=lookup_widget(button,"Gestion");
gtk_widget_destroy(Gestion);
Acceuil=lookup_widget(button,"Acceuil");
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
GtkWidget *Ajouter;
Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
Gestion=lookup_widget(button,"Gestion");
Gestion=create_Gestion();
gtk_widget_show(Gestion);
}


void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Ajouter;
Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
Acceuil=lookup_widget(button,"Acceuil");
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pp,*pe, *combobox,*pf;
Menus menu;
pe = lookup_widget (button, "entry3");
pp = lookup_widget (button, "entry5"); 
pf = lookup_widget (button, "entry6");
combobox = lookup_widget (button, "comboboxentry1");
 
strcpy(menu.pe , gtk_entry_get_text(GTK_ENTRY(pe)));
strcpy(menu.pp , gtk_entry_get_text(GTK_ENTRY(pp)));
strcpy(menu.pf , gtk_entry_get_text(GTK_ENTRY(pf)));
if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=7;
menu.tp=p;
ajouter(menu);
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=3;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=2;
}


void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
GtkWidget *Modifier;
Modifier=lookup_widget(button,"Modifier");
gtk_widget_destroy(Modifier);
Gestion=lookup_widget(button,"Gestion");
Gestion=create_Gestion();
gtk_widget_show(Gestion);
}


void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil;
GtkWidget *Modifier;
Modifier=lookup_widget(button,"Modifier");
gtk_widget_destroy(Modifier);
Acceuil=lookup_widget(button,"Acceuil");
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil);
}


void
on_button36_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pp,*pe, *combobox,*pf;
Menus new;
pe = lookup_widget (button, "entry7");
pp = lookup_widget (button, "entry8"); 
pf = lookup_widget (button, "entry9");
combobox = lookup_widget (button, "comboboxentry2");
 
strcpy(new.pe , gtk_entry_get_text(GTK_ENTRY(pe)));
strcpy(new.pp , gtk_entry_get_text(GTK_ENTRY(pp)));
strcpy(new.pf , gtk_entry_get_text(GTK_ENTRY(pf)));
if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=7;
new.tp=p;
modifier(new);


}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=1;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=2;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=3;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=1;
}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=2;
}


void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=3;
}


void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox;
Menus R;

combobox = lookup_widget (button, "comboboxentry3");
 

if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=7;
R.tp=p;
Supprimer(R);

}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(button,"Afficher");
Afficher=create_Afficher();
gtk_widget_hide(w1);
treeview1=lookup_widget(Afficher,"treeview1");
afficher_menu(treeview1);
}





void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
strcpy(x2,"2");
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
strcpy(x1,"1");
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
strcpy(x3,"3");
}


void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *c;
GtkWidget *Recherchetr,*w1;
GtkWidget *treeview2;
char ce[20];
char xe1[20];
char xe2[20];
char xe3[20];
strcpy(xe1,x1);
strcpy(xe2,x2);
strcpy(xe3,x3);
c = lookup_widget (button, "entry10");
Recherchetr=lookup_widget(button,"Recherchetr");
Recherchetr=create_Recherchetr();
gtk_widget_show(Recherchetr);
strcpy(ce , gtk_entry_get_text(GTK_ENTRY(c)));

treeview2=lookup_widget(Recherchetr,"treeview2");

rechercher_menu(treeview2,xe1,xe2,xe3,ce);

}


void
on_button48_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Dashboard3,*w1,*spinbutton1;
GtkWidget *treeview3;

int c;

Dashboard3=lookup_widget(button,"Dashboard3");
Dashboard3=create_Dashboard3();
gtk_widget_show(Dashboard3);
spinbutton1=lookup_widget(button,"spinbutton1");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
treeview3=lookup_widget(Dashboard3,"treeview3");

afficher_Dash(treeview3,c);

}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_AKlogin_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  int n=150,check = -1;
     char b[70]="Bienvenue dans l'space de gestion de stock: ";
     char c[50]="mot de passe ou login incorrect";
     GtkWidget *input1;
     GtkWidget *input2;
     GtkWidget *output1;
     GtkWidget *output2;
     GtkWidget *Login_bienvenue;
     GtkWidget *Login_gestionstock;


     Login_bienvenue=create_Login_bienvenue();
     input1=lookup_widget(objet_graphique, "entry_AKusername");
     input2=lookup_widget(objet_graphique, "entry_AKpassword");
     output1=lookup_widget(objet_graphique, "label4");
     Login_gestionstock=lookup_widget(objet_graphique,"Login_gestionstock");
     char nom[20];
     strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
     char pass[20];
     strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input2)));
     check = check_user(nom,pass,n);
     if (check==0){
      gtk_widget_hide(Login_gestionstock);
     strcat(b,nom);
     gtk_widget_show(Login_bienvenue);
     output2=lookup_widget(Login_bienvenue, "label_AKbienvenue");
     gtk_label_set_text(GTK_LABEL(output2),b);
     }else{
     gtk_label_set_text(GTK_LABEL(output1),c);
     }

}


void
on_button_AKquitter1_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button_AKstock_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Login_bienvenue;
  GtkWidget *Ajout_produit;
  Ajout_produit=create_Ajout_produit();
  Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
  gtk_widget_hide(Login_bienvenue);
  gtk_widget_show(Ajout_produit);
}


void
on_button_AKrupture_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *Login_bienvenue;
	GtkWidget *rupture;
	GtkWidget *treeview_AKrupt;
	Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
	gtk_widget_destroy(Login_bienvenue);
	rupture=lookup_widget(objet_graphique,"rupture");
	rupture=create_rupture();
	gtk_widget_show(rupture);
	treeview_AKrupt=lookup_widget(rupture,"treeview_AKrupt");
	visualiser(treeview_AKrupt);



}


void
on_button_AKlogout_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Login_gestionstock;
  GtkWidget *Login_bienvenue;
  Login_gestionstock=create_Login_gestionstock();
  Login_bienvenue=lookup_widget(objet_graphique,"Login_bienvenue");
  gtk_widget_hide(Login_bienvenue);
  gtk_widget_show(Login_gestionstock);
}


void
on_button_AKajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


	Stock c;
	GtkWidget *id,*nom,*quantite,*type,*jour, *mois, *annee, *ajouter ;
	

	id=lookup_widget(objet_graphique,"entry_AKid");
	nom=lookup_widget(objet_graphique,"entry_AKnom");
	quantite=lookup_widget(objet_graphique,"entry_AKquantite");
	type=lookup_widget(objet_graphique, "combobox_AKtype");
	jour=lookup_widget(objet_graphique, "spinbutton_AKjour");
	mois=lookup_widget(objet_graphique, "spinbutton_AKmois");
	annee=lookup_widget(objet_graphique, "spinbutton_AKannee");





	
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	c.dateexp.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	c.dateexp.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	c.dateexp.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));


	AjouterProduit(c);




}









void
on_button_AKafficher_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout_produit;
GtkWidget *Stock;
GtkWidget *treeview_AKstock;
Ajout_produit=lookup_widget(objet_graphique,"Ajout_produit");
gtk_widget_destroy(Ajout_produit);
Stock=lookup_widget(objet_graphique,"Stock");
Stock=create_Stock();
gtk_widget_show(Stock);
treeview_AKstock=lookup_widget(Stock,"treeview_AKstock");
afficher_produit(treeview_AKstock);

}


void
on_button_AKretourajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Ajout_produit;
  GtkWidget *Login_bienvenue;
  Login_bienvenue=create_Login_bienvenue();
  Ajout_produit=lookup_widget(objet_graphique,"Ajout_produit");
  gtk_widget_hide(Ajout_produit);
  gtk_widget_show(Login_bienvenue);
}


void
on_button_AKmodif1_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[50];
  Stock s;
  FILE*f;
  GtkWidget *input;
  GtkWidget *Stock;
  GtkWidget *Modification;
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  GtkWidget *output5;
  GtkWidget *output6;
  GtkWidget *output7;
  



  input=lookup_widget(objet_graphique,"entry_AKidmodif");
  strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
  Modification=create_Modification();
  Stock=lookup_widget(objet_graphique,"Stock");
  gtk_widget_hide(Stock);
  gtk_widget_show(Modification);
  output1=lookup_widget(Modification,"entry_AKid1");
  output2=lookup_widget(Modification,"entry_AKnom1");
  output3=lookup_widget(Modification,"entry_AKquantite1");
  output4=lookup_widget(Modification,"combobox_AKtype1");
  output5=lookup_widget(objet_graphique, "spinbutton_AKjour1");
  output6=lookup_widget(objet_graphique, "spinbutton_AKmois1");
  output7=lookup_widget(objet_graphique, "spinbutton_AKannee1");
  
  f=fopen("stock.txt","a+");
  if(f!=NULL)
  {
  while(fscanf(f,"%s %s %s %s %d %d %d\n",s.id,s.nom,s.quantite,s.type,&s.dateexp.annee,&s.dateexp.mois,&s.dateexp.jour
)!=EOF)
    {
      if(strcmp(id,s.id)==0)
      {
        gtk_entry_set_text(GTK_ENTRY(output1),s.id);
        gtk_entry_set_text(GTK_ENTRY(output2),s.nom);
        gtk_entry_set_text(GTK_ENTRY(output3),s.quantite);
        gtk_combo_box_set_title(GTK_COMBO_BOX(output4),s.type);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),s.dateexp.annee);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),s.dateexp.mois);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),s.dateexp.jour);
        
      }
    }
    fclose(f);
  }



}


void
on_button_AKsuppr_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


  



  GtkWidget *input;
  GtkWidget *treeview_AKstock;
  GtkWidget *Stock;
  GtkWidget *output;
  GtkWidget *confirmer_suppr;

  /*char ref[30];
  input=lookup_widget(objet_graphique,"entry_AKidsuppr");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));  
  confirmer_suppr=create_confirmer_suppr();
  
  
  gtk_widget_show(confirmer_suppr);*/
  
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label_messagesuppr");
  Stock=(objet_graphique,"Stock");
  char ref[30];
  input=lookup_widget(objet_graphique,"entry_AKidsuppr");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
  SupprimerProduit(ref);
  treeview_AKstock=lookup_widget(objet_graphique,"treeview_AKstock");
  afficher_produit(treeview_AKstock);
  gtk_label_set_text(GTK_LABEL(output),c);

}


void
on_treeview_AKstock_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_button_AKretourstock_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Stock;
  GtkWidget *Ajout_produit;
  Ajout_produit=create_Ajout_produit();
  Stock=lookup_widget(objet_graphique,"Stock");
  gtk_widget_hide(Stock);
  gtk_widget_show(Ajout_produit);
}


void
on_button_AKrech_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 


	
	GtkWidget *afficher,*w1,*search, *treeview;
	char ss[30];
	search = lookup_widget(objet_graphique, "entry_AKidrech") ;
	w1=lookup_widget(objet_graphique,"Stock");

	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_Stock();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview_AKstock") ;
	ChercherProduit(treeview,ss);


}


void
on_button_AKmodif2_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*output;
  GtkWidget*input6;
  GtkWidget*input7;
  FILE*f;
  char c[]="modification terminee";
  output=lookup_widget(objet_graphique,"label_messagemodif");
  Stock s;
  input1=lookup_widget(objet_graphique,"entry_AKid1");
  input2=lookup_widget(objet_graphique,"entry_AKnom1");
  input3=lookup_widget(objet_graphique,"entry_AKquantite1");
  input4=lookup_widget(objet_graphique,"combobox_AKtype1");
  input5=lookup_widget(objet_graphique, "spinbutton_AKjour1");
  input6=lookup_widget(objet_graphique, "spinbutton_AKmois1");
  input7=lookup_widget(objet_graphique, "spinbutton_AKannee1");





	

	

  
  strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
  
  s.dateexp.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
  s.dateexp.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
  s.dateexp.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
  
  ModifierProduit(s);
  gtk_label_set_text(GTK_LABEL(output),c);


}


void
on_button_AKannuler_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Stock;
  GtkWidget *Modification;
  GtkWidget *treeview_AKstock;
  Stock=create_Stock();
  Modification=lookup_widget(objet_graphique,"Modification");
  gtk_widget_hide(Modification);
  gtk_widget_show(Stock);
treeview_AKstock=lookup_widget(Stock,"treeview_AKstock");
afficher_produit(treeview_AKstock);
}


void
on_treeview_AKrupt_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_button_AKretourrupt_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *rupture;
  GtkWidget *Login_bienvenue;
  Login_bienvenue=create_Login_bienvenue();
  rupture=lookup_widget(objet_graphique,"rupture");
  gtk_widget_hide(rupture);
  gtk_widget_show(Login_bienvenue);
}



void
on_button_confirmersuppr_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{




/*GtkWidget *Stock, *confirmer_suppr, *treeview_AKstock, *input, *togglebutton1, *togglebutton2, *entry_AKidsuppr;


char ref[30];
confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
togglebutton1 = lookup_widget(objet_graphique,"checkbutton_AKconfirm1");
togglebutton2 = lookup_widget(objet_graphique,"checkbutton_AKconfirm2");

if (choix == 1)
	{
		
confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
gtk_widget_destroy(confirmer_suppr);		
Stock=lookup_widget(objet_graphique,"Stock");
Stock=create_Stock ();
gtk_widget_show(Stock);



entry_AKidsuppr=lookup_widget(objet_graphique,"entry_AKidsuppr");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(entry_AKidsuppr)));
SupprimerProduit(ref);

treeview_AKstock=lookup_widget(treeview_AKstock,"treeview_AKstock");

afficher_produit(treeview_AKstock);
	}

if (choix == 0)
	{
		confirmer_suppr=lookup_widget(objet_graphique,"confirmer_suppr");
gtk_widget_destroy(confirmer_suppr);


	}*/


}




void
on_checkbutton_AKconfirm1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{choix = 1 ;}

}


void
on_checkbutton_AKconfirm2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{choix = 0 ;}

}


void
on_button_AKactualiser_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*Stock, *treeview;
	
	
	Stock=lookup_widget(objet_graphique,"Stock");
	afficher = create_Stock();
	gtk_widget_show (afficher);
	gtk_widget_hide (Stock);

	treeview = lookup_widget(afficher, "treeview_AKstock") ;
	afficher_produit(treeview);

}

