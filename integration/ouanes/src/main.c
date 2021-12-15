/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *Acceuil;
  GtkWidget *Gestion;
  GtkWidget *Ajouter;
  GtkWidget *Modifier;
  GtkWidget *Afficher;
  GtkWidget *supprimer;
  GtkWidget *Recherchetr;
  GtkWidget *Dashboard2;
  GtkWidget *Dashboard3;
  GtkWidget *Login_gestionstock;
  GtkWidget *Login_bienvenue;
  GtkWidget *Ajout_produit;
  GtkWidget *Stock;
  GtkWidget *Modification;
  GtkWidget *rupture;
  GtkWidget *confirmer_suppr;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  Acceuil = create_Acceuil ();
  gtk_widget_show (Acceuil);
  Gestion = create_Gestion ();
  gtk_widget_show (Gestion);
  Ajouter = create_Ajouter ();
  gtk_widget_show (Ajouter);
  Modifier = create_Modifier ();
  gtk_widget_show (Modifier);
  Afficher = create_Afficher ();
  gtk_widget_show (Afficher);
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);
  Recherchetr = create_Recherchetr ();
  gtk_widget_show (Recherchetr);
  Dashboard2 = create_Dashboard2 ();
  gtk_widget_show (Dashboard2);
  Dashboard3 = create_Dashboard3 ();
  gtk_widget_show (Dashboard3);
  Login_gestionstock = create_Login_gestionstock ();
  gtk_widget_show (Login_gestionstock);
  Login_bienvenue = create_Login_bienvenue ();
  gtk_widget_show (Login_bienvenue);
  Ajout_produit = create_Ajout_produit ();
  gtk_widget_show (Ajout_produit);
  Stock = create_Stock ();
  gtk_widget_show (Stock);
  Modification = create_Modification ();
  gtk_widget_show (Modification);
  rupture = create_rupture ();
  gtk_widget_show (rupture);
  confirmer_suppr = create_confirmer_suppr ();
  gtk_widget_show (confirmer_suppr);

  gtk_main ();
  return 0;
}
