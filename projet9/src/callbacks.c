#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include  "fonction.h"


int w;
int x;

// bouton affichage
void
on_button2_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
 GtkWidget *ajouter_un_capteur;
 GtkWidget *affichage_et_recherche; 
 GtkWidget *treeview1;

ajouter_un_capteur=lookup_widget(objet,"ajouter_un_capteur");      
gtk_widget_destroy(ajouter_un_capteur);        

affichage_et_recherche =lookup_widget(objet,"affichage_et_recherche");
affichage_et_recherche =create_affichage_et_recherche ();
gtk_widget_show(affichage_et_recherche);
treeview1=lookup_widget(affichage_et_recherche ,"treeview1"); 
}

// bouton ajout
void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ capteur c;
  GtkWidget *nom,*id,*nbcapt,*type,*prix,*date,*marque,*etat;
  GtkWidget  *ajouter_un_capteur ;
  GtkWidget *combobox1;

char texte1[20]="température" ;
char texte2[20]="débit d eau";
char texte3[20]="mouvement";
char texte4[20]="fumée";

ajouter_un_capteur =lookup_widget(objet_graphique,"ajouter_un_capteur ");

 nom=lookup_widget(objet_graphique,"entry2");
 id=lookup_widget(objet_graphique,"entry1");
 date=lookup_widget(objet_graphique,"entry5");
prix=lookup_widget(objet_graphique,"entry4");
 marque=lookup_widget(objet_graphique,"entry3");

 nbcapt=lookup_widget(objet_graphique,"spinbutton1");
 type=lookup_widget(objet_graphique,"comboboxentry1");
 etat=lookup_widget(objet_graphique,"radiobutton1");

 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
 strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));

 //strcpy(c.type,gtk_combo_box_get_active_text(GTK_ENTRY(type)));
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
 strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
 strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(date)));

 if (strcmp(texte1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
  strcpy(c.type,texte1);
 if (strcmp(texte2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
  strcpy(c.type,texte2);
if (strcmp(texte3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
 strcpy(c.type,texte3);
if (strcmp(texte4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
 strcpy(c.type,texte4);

nbcapt =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbcapt));

  ajouter_capteur(c);
}





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkTreeIter iter;
  capteur c;
  
gchar *nom;
gchar *id;
gchar *marque;
gchar *type;
gchar *prix;
gchar *date;
gint *nbcapt;
gchar *etat;

char fichier[]=("capteur.txt");

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&id,2,&marque,3,&type,4,&prix,5,&etat,6,&date,7,&nbcapt,8,&etat,-1);
strcpy(c.id,id);
strcpy(c.nom,nom);
strcpy(c.marque,marque);
strcpy(c.type,type);
c.nbcapt=nbcapt;
strcpy(c.etat,etat);
strcpy(c.prix,prix);
strcpy(c.date,date);

afficher_capteur(treeview); 

}
}



//// page 3
// bouton actualiser
void
on_button3_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{ 
 GtkWidget *affichage_et_recherche,*w1;
   GtkWidget *treeview1;

   w1=lookup_widget(objet,"affichage_et_recherche"); 
   affichage_et_recherche = create_affichage_et_recherche; 

   gtk_widget_show(affichage_et_recherche);
   gtk_widget_hide(w1); 

   treeview1=lookup_widget(affichage_et_recherche,"treeview1");
   vider(treeview1); 
   afficher_capteur (treeview1);
   //afficher_capteur (list, fichier[]);
}

//bouton chercher
void
on_button4_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{	
GtkWidget *window_ajouter,*input2,*treeview1;

char fichier[]={"test.txt"};
char fich[]={"capteur.txt"};
char id[20] ;
capteur c;
int k;
GtkWidget *input,*input1;
FILE *f;
window_ajouter=lookup_widget(objet,"window1");
input2=lookup_widget(objet,"entry9");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
k= chercher(id,fich[20]);

f = fopen(fichier,"a+");
if ( f != NULL )
fprintf(f,"%s %s %s %s %s %s %d %s\n",c.nom,c.id,c.prix,c.marque,c.etat,c.type,c.nbcapt,c.date);

input=lookup_widget(objet,"window1");
input=create_affichage_et_recherche (); 
gtk_widget_show(input);
input1=lookup_widget(objet,"window1");
gtk_widget_destroy(input1);
gtk_widget_show(input);
treeview1=lookup_widget(input,"treeview1");
afficher_capteur(treeview1);
remove(fichier);



}

//bouton retour
void
on_button5_clicked                     (GtkWidget     *objet,
                                        gpointer         user_data)
{GtkWidget * ajouter_un_capteur,*affichage_et_recherche;
 
 affichage_et_recherche=lookup_widget(affichage_et_recherche,"affichage_et_recherche");
 ajouter_un_capteur=create_ajouter_un_capteur();
 gtk_widget_show(ajouter_un_capteur);

}

//bouton modif
void
on_button6_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *capteur;
GtkWidget *modifier;

 
 modifier=create_modifier_capteur();
 capteur=lookup_widget(objet,"capteur");
 gtk_widget_hide(capteur);
 gtk_widget_show(modifier);

}





void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
   x= 1;


}

//// page 2
///bouton valider 
void
on_button7_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{               

GtkWidget *combobox2;                                  
GtkWidget *nom;
GtkWidget *id;
GtkWidget *type;
GtkWidget *marque;
GtkWidget *etat;
char texte1[20]="température" ;
char texte2[20]="débit d eau";
char texte3[20]="mouvement";
char texte4[20]="fumée";


capteur c;

id=lookup_widget(objet_graphique,"entry6");
nom=lookup_widget(objet_graphique,"entry7");
type=lookup_widget(objet_graphique,"comboboxentry2");
marque=lookup_widget(objet_graphique,"entry8");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
//strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
if(w==1)
strcpy(c.etat,"defectueux");
if(w==0)
strcpy(c.etat,"non defectueux");

if (strcmp(texte1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
  strcpy(c.type,texte1);
 if (strcmp(texte2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
  strcpy(c.type,texte2);
if (strcmp(texte3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 strcpy(c.type,texte3);
if (strcmp(texte4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 strcpy(c.type,texte4);

modifier_capteur (c);

}                  


void
on_checkbutton1_toggled                (GtkToggleButton  *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{w=1;}
else
{w=0;}

}


void
on_checkbutton2_toggled                (GtkToggleButton  *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
{w=1;}
else
{w=0;}

}




//// bouton annuler
void
on_button8_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *modifier_capteur;
 modifier_capteur=create_modifier_capteur;
 gtk_widget_show(modifier_capteur);
 gtk_widget_hide(modifier_capteur);
}









