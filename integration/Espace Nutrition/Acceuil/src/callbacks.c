#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"

int p;
char x1[20];
char x2[20];
char x3[20];

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

