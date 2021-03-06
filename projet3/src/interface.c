/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_hebergement (void)
{
  GtkWidget *hebergement;
  GtkWidget *fixed2;
  GtkWidget *label1;
  GtkWidget *combobox_hebergement;
  GtkWidget *continuer;

  hebergement = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (hebergement), _("hebergement"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (hebergement), fixed2);

  label1 = gtk_label_new (_("selectionner une tache :"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed2), label1, 96, 32);
  gtk_widget_set_size_request (label1, 208, 72);

  combobox_hebergement = gtk_combo_box_new_text ();
  gtk_widget_show (combobox_hebergement);
  gtk_fixed_put (GTK_FIXED (fixed2), combobox_hebergement, 128, 96);
  gtk_widget_set_size_request (combobox_hebergement, 144, 48);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Ajouter"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Rechercher"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Modifier"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Supprimer"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Afficher"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox_hebergement), _("Quitter"));

  continuer = gtk_button_new_with_mnemonic (_("continuer"));
  gtk_widget_show (continuer);
  gtk_fixed_put (GTK_FIXED (fixed2), continuer, 160, 168);
  gtk_widget_set_size_request (continuer, 88, 32);

  g_signal_connect ((gpointer) continuer, "clicked",
                    G_CALLBACK (on_continuer_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) continuer, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (hebergement));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (hebergement, hebergement, "hebergement");
  GLADE_HOOKUP_OBJECT (hebergement, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (hebergement, label1, "label1");
  GLADE_HOOKUP_OBJECT (hebergement, combobox_hebergement, "combobox_hebergement");
  GLADE_HOOKUP_OBJECT (hebergement, continuer, "continuer");

  return hebergement;
}

GtkWidget*
create_ajouter (void)
{
  GtkWidget *ajouter;
  GtkWidget *fixed3;
  GtkWidget *entry_nom;
  GtkWidget *entry_prenom;
  GtkWidget *entry_id;
  GtkObject *spinbutton_etage_adj;
  GtkWidget *spinbutton_etage;
  GtkObject *spinbutton_numchambre_adj;
  GtkWidget *spinbutton_numchambre;
  GtkWidget *paiementc;
  GSList *paiementc_group = NULL;
  GtkWidget *paiemente;
  GtkWidget *prenom;
  GtkWidget *paiement;
  GtkWidget *nom;
  GtkWidget *m_ajouter;
  GtkWidget *retour_ajouter;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label16;
  GtkWidget *etage;
  GtkWidget *numchambre;
  GtkWidget *id;

  ajouter = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (ajouter), _("ajouter"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (ajouter), fixed3);

  entry_nom = gtk_entry_new ();
  gtk_widget_show (entry_nom);
  gtk_fixed_put (GTK_FIXED (fixed3), entry_nom, 104, 80);
  gtk_widget_set_size_request (entry_nom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_nom), 8226);

  entry_prenom = gtk_entry_new ();
  gtk_widget_show (entry_prenom);
  gtk_fixed_put (GTK_FIXED (fixed3), entry_prenom, 144, 112);
  gtk_widget_set_size_request (entry_prenom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_prenom), 8226);

  entry_id = gtk_entry_new ();
  gtk_widget_show (entry_id);
  gtk_fixed_put (GTK_FIXED (fixed3), entry_id, 256, 144);
  gtk_widget_set_size_request (entry_id, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_id), 8226);

  spinbutton_etage_adj = gtk_adjustment_new (1, 1, 4, 1, 10, 10);
  spinbutton_etage = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_etage_adj), 1, 0);
  gtk_widget_show (spinbutton_etage);
  gtk_fixed_put (GTK_FIXED (fixed3), spinbutton_etage, 200, 208);
  gtk_widget_set_size_request (spinbutton_etage, 48, 24);

  spinbutton_numchambre_adj = gtk_adjustment_new (1, 1, 10, 1, 10, 10);
  spinbutton_numchambre = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_numchambre_adj), 1, 0);
  gtk_widget_show (spinbutton_numchambre);
  gtk_fixed_put (GTK_FIXED (fixed3), spinbutton_numchambre, 216, 240);
  gtk_widget_set_size_request (spinbutton_numchambre, 60, 27);

  paiementc = gtk_radio_button_new_with_mnemonic (NULL, _("par_ch\303\251ques"));
  gtk_widget_show (paiementc);
  gtk_fixed_put (GTK_FIXED (fixed3), paiementc, 296, 176);
  gtk_widget_set_size_request (paiementc, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (paiementc), paiementc_group);
  paiementc_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (paiementc));

  paiemente = gtk_radio_button_new_with_mnemonic (NULL, _("en_especes"));
  gtk_widget_show (paiemente);
  gtk_fixed_put (GTK_FIXED (fixed3), paiemente, 160, 176);
  gtk_widget_set_size_request (paiemente, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (paiemente), paiementc_group);
  paiementc_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (paiemente));

  prenom = gtk_label_new (_("pr\303\251nom :"));
  gtk_widget_show (prenom);
  gtk_fixed_put (GTK_FIXED (fixed3), prenom, 24, 120);
  gtk_widget_set_size_request (prenom, 80, 16);

  paiement = gtk_label_new (_("paiement :"));
  gtk_widget_show (paiement);
  gtk_fixed_put (GTK_FIXED (fixed3), paiement, 32, 176);
  gtk_widget_set_size_request (paiement, 88, 24);

  nom = gtk_label_new (_("nom :"));
  gtk_widget_show (nom);
  gtk_fixed_put (GTK_FIXED (fixed3), nom, 32, 88);
  gtk_widget_set_size_request (nom, 41, 17);

  m_ajouter = gtk_button_new_with_mnemonic (_("AJOUTER"));
  gtk_widget_show (m_ajouter);
  gtk_fixed_put (GTK_FIXED (fixed3), m_ajouter, 304, 280);
  gtk_widget_set_size_request (m_ajouter, 96, 32);

  retour_ajouter = gtk_button_new ();
  gtk_widget_show (retour_ajouter);
  gtk_fixed_put (GTK_FIXED (fixed3), retour_ajouter, 30, 10);
  gtk_widget_set_size_request (retour_ajouter, 100, 40);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (retour_ajouter), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label16 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox4), label16, FALSE, FALSE, 0);

  etage = gtk_label_new (_("num\303\251ro d'etage :"));
  gtk_widget_show (etage);
  gtk_fixed_put (GTK_FIXED (fixed3), etage, 24, 208);
  gtk_widget_set_size_request (etage, 144, 24);

  numchambre = gtk_label_new (_("num\303\251ro de la chambre :"));
  gtk_widget_show (numchambre);
  gtk_fixed_put (GTK_FIXED (fixed3), numchambre, 16, 240);
  gtk_widget_set_size_request (numchambre, 200, 24);

  id = gtk_label_new (_("num\303\251ro de carte d'identit\303\251 :"));
  gtk_widget_show (id);
  gtk_fixed_put (GTK_FIXED (fixed3), id, 24, 144);
  gtk_widget_set_size_request (id, 208, 24);

  g_signal_connect ((gpointer) paiementc, "toggled",
                    G_CALLBACK (on_paiementc_toggled),
                    NULL);
  g_signal_connect ((gpointer) paiemente, "toggled",
                    G_CALLBACK (on_paiemente_toggled),
                    NULL);
  g_signal_connect ((gpointer) m_ajouter, "clicked",
                    G_CALLBACK (on_m_ajouter_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_ajouter, "clicked",
                    G_CALLBACK (on_retour_ajouter_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) retour_ajouter, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (ajouter));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (ajouter, ajouter, "ajouter");
  GLADE_HOOKUP_OBJECT (ajouter, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (ajouter, entry_nom, "entry_nom");
  GLADE_HOOKUP_OBJECT (ajouter, entry_prenom, "entry_prenom");
  GLADE_HOOKUP_OBJECT (ajouter, entry_id, "entry_id");
  GLADE_HOOKUP_OBJECT (ajouter, spinbutton_etage, "spinbutton_etage");
  GLADE_HOOKUP_OBJECT (ajouter, spinbutton_numchambre, "spinbutton_numchambre");
  GLADE_HOOKUP_OBJECT (ajouter, paiementc, "paiementc");
  GLADE_HOOKUP_OBJECT (ajouter, paiemente, "paiemente");
  GLADE_HOOKUP_OBJECT (ajouter, prenom, "prenom");
  GLADE_HOOKUP_OBJECT (ajouter, paiement, "paiement");
  GLADE_HOOKUP_OBJECT (ajouter, nom, "nom");
  GLADE_HOOKUP_OBJECT (ajouter, m_ajouter, "m_ajouter");
  GLADE_HOOKUP_OBJECT (ajouter, retour_ajouter, "retour_ajouter");
  GLADE_HOOKUP_OBJECT (ajouter, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (ajouter, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (ajouter, image4, "image4");
  GLADE_HOOKUP_OBJECT (ajouter, label16, "label16");
  GLADE_HOOKUP_OBJECT (ajouter, etage, "etage");
  GLADE_HOOKUP_OBJECT (ajouter, numchambre, "numchambre");
  GLADE_HOOKUP_OBJECT (ajouter, id, "id");

  return ajouter;
}

GtkWidget*
create_rechercher (void)
{
  GtkWidget *rechercher;
  GtkWidget *fixed4;
  GtkWidget *resultat_recherche;
  GtkWidget *etagerech4;
  GtkWidget *etagerech2;
  GtkWidget *etagerech3;
  GtkWidget *label_recharcher2;
  GtkWidget *m_rechercher;
  GtkObject *spinbutton_rech_adj;
  GtkWidget *spinbutton_rech;
  GtkWidget *etagerech1;
  GtkWidget *label_aff_et1;
  GtkWidget *label_aff_et2;
  GtkWidget *label_aff_et3;
  GtkWidget *label_aff_et4;
  GtkWidget *vseparator1;
  GtkWidget *retour_rechercher;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label17;
  GtkWidget *label_rechercher1;

  rechercher = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (rechercher), _("rechercher"));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (rechercher), fixed4);

  resultat_recherche = gtk_label_new ("");
  gtk_widget_show (resultat_recherche);
  gtk_fixed_put (GTK_FIXED (fixed4), resultat_recherche, 424, 120);
  gtk_widget_set_size_request (resultat_recherche, 208, 72);

  etagerech4 = gtk_check_button_new_with_mnemonic (_("etage 4"));
  gtk_widget_show (etagerech4);
  gtk_fixed_put (GTK_FIXED (fixed4), etagerech4, 240, 256);
  gtk_widget_set_size_request (etagerech4, 118, 24);

  etagerech2 = gtk_check_button_new_with_mnemonic (_("etage 2"));
  gtk_widget_show (etagerech2);
  gtk_fixed_put (GTK_FIXED (fixed4), etagerech2, 56, 256);
  gtk_widget_set_size_request (etagerech2, 118, 24);

  etagerech3 = gtk_check_button_new_with_mnemonic (_("etage 3"));
  gtk_widget_show (etagerech3);
  gtk_fixed_put (GTK_FIXED (fixed4), etagerech3, 240, 216);
  gtk_widget_set_size_request (etagerech3, 118, 24);

  label_recharcher2 = gtk_label_new (_("numero d'etage  \303\240 rechercher :"));
  gtk_widget_show (label_recharcher2);
  gtk_fixed_put (GTK_FIXED (fixed4), label_recharcher2, 56, 168);
  gtk_widget_set_size_request (label_recharcher2, 288, 32);

  m_rechercher = gtk_button_new_with_mnemonic (_("rechercher"));
  gtk_widget_show (m_rechercher);
  gtk_fixed_put (GTK_FIXED (fixed4), m_rechercher, 136, 304);
  gtk_widget_set_size_request (m_rechercher, 114, 32);

  spinbutton_rech_adj = gtk_adjustment_new (1, 1, 10, 1, 10, 10);
  spinbutton_rech = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_rech_adj), 1, 0);
  gtk_widget_show (spinbutton_rech);
  gtk_fixed_put (GTK_FIXED (fixed4), spinbutton_rech, 152, 128);
  gtk_widget_set_size_request (spinbutton_rech, 60, 27);

  etagerech1 = gtk_check_button_new_with_mnemonic (_("etage 1"));
  gtk_widget_show (etagerech1);
  gtk_fixed_put (GTK_FIXED (fixed4), etagerech1, 56, 216);
  gtk_widget_set_size_request (etagerech1, 118, 24);

  label_aff_et1 = gtk_label_new ("");
  gtk_widget_show (label_aff_et1);
  gtk_fixed_put (GTK_FIXED (fixed4), label_aff_et1, 424, 32);
  gtk_widget_set_size_request (label_aff_et1, 560, 80);

  label_aff_et2 = gtk_label_new ("");
  gtk_widget_show (label_aff_et2);
  gtk_fixed_put (GTK_FIXED (fixed4), label_aff_et2, 424, 120);
  gtk_widget_set_size_request (label_aff_et2, 560, 64);

  label_aff_et3 = gtk_label_new ("");
  gtk_widget_show (label_aff_et3);
  gtk_fixed_put (GTK_FIXED (fixed4), label_aff_et3, 432, 184);
  gtk_widget_set_size_request (label_aff_et3, 544, 56);

  label_aff_et4 = gtk_label_new ("");
  gtk_widget_show (label_aff_et4);
  gtk_fixed_put (GTK_FIXED (fixed4), label_aff_et4, 424, 272);
  gtk_widget_set_size_request (label_aff_et4, 560, 64);

  vseparator1 = gtk_vseparator_new ();
  gtk_widget_show (vseparator1);
  gtk_fixed_put (GTK_FIXED (fixed4), vseparator1, 384, 0);
  gtk_widget_set_size_request (vseparator1, 24, 368);

  retour_rechercher = gtk_button_new ();
  gtk_widget_show (retour_rechercher);
  gtk_fixed_put (GTK_FIXED (fixed4), retour_rechercher, 30, 10);
  gtk_widget_set_size_request (retour_rechercher, 100, 40);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (retour_rechercher), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox5), label17, FALSE, FALSE, 0);

  label_rechercher1 = gtk_label_new (_("numero de la chambre \303\240 rechercher :"));
  gtk_widget_show (label_rechercher1);
  gtk_fixed_put (GTK_FIXED (fixed4), label_rechercher1, 32, 72);
  gtk_widget_set_size_request (label_rechercher1, 352, 56);

  g_signal_connect ((gpointer) etagerech4, "toggled",
                    G_CALLBACK (on_etagerech4_toggled),
                    NULL);
  g_signal_connect ((gpointer) etagerech2, "toggled",
                    G_CALLBACK (on_etagerech2_toggled),
                    NULL);
  g_signal_connect ((gpointer) etagerech3, "toggled",
                    G_CALLBACK (on_etagerech3_toggled),
                    NULL);
  g_signal_connect ((gpointer) m_rechercher, "clicked",
                    G_CALLBACK (on_m_rechercher_clicked),
                    NULL);
  g_signal_connect ((gpointer) etagerech1, "toggled",
                    G_CALLBACK (on_etagerech1_toggled),
                    NULL);
  g_signal_connect ((gpointer) retour_rechercher, "clicked",
                    G_CALLBACK (on_retour_rechercher_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) retour_rechercher, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (rechercher));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (rechercher, rechercher, "rechercher");
  GLADE_HOOKUP_OBJECT (rechercher, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (rechercher, resultat_recherche, "resultat_recherche");
  GLADE_HOOKUP_OBJECT (rechercher, etagerech4, "etagerech4");
  GLADE_HOOKUP_OBJECT (rechercher, etagerech2, "etagerech2");
  GLADE_HOOKUP_OBJECT (rechercher, etagerech3, "etagerech3");
  GLADE_HOOKUP_OBJECT (rechercher, label_recharcher2, "label_recharcher2");
  GLADE_HOOKUP_OBJECT (rechercher, m_rechercher, "m_rechercher");
  GLADE_HOOKUP_OBJECT (rechercher, spinbutton_rech, "spinbutton_rech");
  GLADE_HOOKUP_OBJECT (rechercher, etagerech1, "etagerech1");
  GLADE_HOOKUP_OBJECT (rechercher, label_aff_et1, "label_aff_et1");
  GLADE_HOOKUP_OBJECT (rechercher, label_aff_et2, "label_aff_et2");
  GLADE_HOOKUP_OBJECT (rechercher, label_aff_et3, "label_aff_et3");
  GLADE_HOOKUP_OBJECT (rechercher, label_aff_et4, "label_aff_et4");
  GLADE_HOOKUP_OBJECT (rechercher, vseparator1, "vseparator1");
  GLADE_HOOKUP_OBJECT (rechercher, retour_rechercher, "retour_rechercher");
  GLADE_HOOKUP_OBJECT (rechercher, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (rechercher, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (rechercher, image5, "image5");
  GLADE_HOOKUP_OBJECT (rechercher, label17, "label17");
  GLADE_HOOKUP_OBJECT (rechercher, label_rechercher1, "label_rechercher1");

  return rechercher;
}

GtkWidget*
create_modifier (void)
{
  GtkWidget *modifier;
  GtkWidget *fixed5;
  GtkWidget *entry_modifier_id;
  GtkWidget *entry_modifier_nom;
  GtkWidget *entry_modifier_prenom;
  GtkWidget *label_modifier;
  GtkWidget *radiobutton_modifier_c;
  GSList *radiobutton_modifier_c_group = NULL;
  GtkWidget *radiobutton_modifier_e;
  GtkWidget *m_modifier;
  GtkObject *spinbutton_modifier_etage_adj;
  GtkWidget *spinbutton_modifier_etage;
  GtkObject *spinbutton_modifier_numchambre_adj;
  GtkWidget *spinbutton_modifier_numchambre;
  GtkWidget *retour_modifier;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label15;
  GtkWidget *label19;
  GtkWidget *label20;
  GtkWidget *label21;
  GtkWidget *label24;
  GtkWidget *label22;
  GtkWidget *label23;

  modifier = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (modifier), _("modifier"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (modifier), fixed5);

  entry_modifier_id = gtk_entry_new ();
  gtk_widget_show (entry_modifier_id);
  gtk_fixed_put (GTK_FIXED (fixed5), entry_modifier_id, 192, 104);
  gtk_widget_set_size_request (entry_modifier_id, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_modifier_id), 8226);

  entry_modifier_nom = gtk_entry_new ();
  gtk_widget_show (entry_modifier_nom);
  gtk_fixed_put (GTK_FIXED (fixed5), entry_modifier_nom, 192, 144);
  gtk_widget_set_size_request (entry_modifier_nom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_modifier_nom), 8226);

  entry_modifier_prenom = gtk_entry_new ();
  gtk_widget_show (entry_modifier_prenom);
  gtk_fixed_put (GTK_FIXED (fixed5), entry_modifier_prenom, 192, 184);
  gtk_widget_set_size_request (entry_modifier_prenom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_modifier_prenom), 8226);

  label_modifier = gtk_label_new (_("num de carte d'identit\303\251 d'\303\251tudiant \303\240 modifier :"));
  gtk_widget_show (label_modifier);
  gtk_fixed_put (GTK_FIXED (fixed5), label_modifier, 128, 16);
  gtk_widget_set_size_request (label_modifier, 328, 56);

  radiobutton_modifier_c = gtk_radio_button_new_with_mnemonic (NULL, _("par ch\303\251ques"));
  gtk_widget_show (radiobutton_modifier_c);
  gtk_fixed_put (GTK_FIXED (fixed5), radiobutton_modifier_c, 280, 232);
  gtk_widget_set_size_request (radiobutton_modifier_c, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_modifier_c), radiobutton_modifier_c_group);
  radiobutton_modifier_c_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_modifier_c));

  radiobutton_modifier_e = gtk_radio_button_new_with_mnemonic (NULL, _("en especes"));
  gtk_widget_show (radiobutton_modifier_e);
  gtk_fixed_put (GTK_FIXED (fixed5), radiobutton_modifier_e, 144, 232);
  gtk_widget_set_size_request (radiobutton_modifier_e, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_modifier_e), radiobutton_modifier_c_group);
  radiobutton_modifier_c_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_modifier_e));

  m_modifier = gtk_button_new_with_mnemonic (_("modifier"));
  gtk_widget_show (m_modifier);
  gtk_fixed_put (GTK_FIXED (fixed5), m_modifier, 200, 352);
  gtk_widget_set_size_request (m_modifier, 96, 32);

  spinbutton_modifier_etage_adj = gtk_adjustment_new (1, 1, 4, 1, 10, 10);
  spinbutton_modifier_etage = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_modifier_etage_adj), 1, 0);
  gtk_widget_show (spinbutton_modifier_etage);
  gtk_fixed_put (GTK_FIXED (fixed5), spinbutton_modifier_etage, 208, 264);
  gtk_widget_set_size_request (spinbutton_modifier_etage, 60, 27);

  spinbutton_modifier_numchambre_adj = gtk_adjustment_new (1, 1, 10, 1, 10, 10);
  spinbutton_modifier_numchambre = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_modifier_numchambre_adj), 1, 0);
  gtk_widget_show (spinbutton_modifier_numchambre);
  gtk_fixed_put (GTK_FIXED (fixed5), spinbutton_modifier_numchambre, 216, 304);
  gtk_widget_set_size_request (spinbutton_modifier_numchambre, 60, 27);

  retour_modifier = gtk_button_new ();
  gtk_widget_show (retour_modifier);
  gtk_fixed_put (GTK_FIXED (fixed5), retour_modifier, 16, 16);
  gtk_widget_set_size_request (retour_modifier, 100, 40);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (retour_modifier), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label15 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox3), label15, FALSE, FALSE, 0);

  label19 = gtk_label_new (_("nom :"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed5), label19, 64, 152);
  gtk_widget_set_size_request (label19, 65, 16);

  label20 = gtk_label_new (_("prenom :"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed5), label20, 64, 184);
  gtk_widget_set_size_request (label20, 89, 24);

  label21 = gtk_label_new (_("paiement  :"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed5), label21, 40, 232);
  gtk_widget_set_size_request (label21, 96, 24);

  label24 = gtk_label_new (_("num\303\251ro de carte d'identit\303\251 :"));
  gtk_widget_show (label24);
  gtk_fixed_put (GTK_FIXED (fixed5), label24, 24, 96);
  gtk_widget_set_size_request (label24, 160, 48);

  label22 = gtk_label_new (_("num\303\251ro d'etage :"));
  gtk_widget_show (label22);
  gtk_fixed_put (GTK_FIXED (fixed5), label22, 32, 272);
  gtk_widget_set_size_request (label22, 137, 24);

  label23 = gtk_label_new (_("num\303\251ro de la chambre :"));
  gtk_widget_show (label23);
  gtk_fixed_put (GTK_FIXED (fixed5), label23, 16, 304);
  gtk_widget_set_size_request (label23, 169, 24);

  g_signal_connect ((gpointer) radiobutton_modifier_c, "toggled",
                    G_CALLBACK (on_radiobutton_modifier_c_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton_modifier_e, "toggled",
                    G_CALLBACK (on_radiobutton_modifier_e_toggled),
                    NULL);
  g_signal_connect ((gpointer) m_modifier, "clicked",
                    G_CALLBACK (on_m_modifier_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_modifier, "clicked",
                    G_CALLBACK (on_retour_modifier_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) retour_modifier, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (modifier));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (modifier, modifier, "modifier");
  GLADE_HOOKUP_OBJECT (modifier, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (modifier, entry_modifier_id, "entry_modifier_id");
  GLADE_HOOKUP_OBJECT (modifier, entry_modifier_nom, "entry_modifier_nom");
  GLADE_HOOKUP_OBJECT (modifier, entry_modifier_prenom, "entry_modifier_prenom");
  GLADE_HOOKUP_OBJECT (modifier, label_modifier, "label_modifier");
  GLADE_HOOKUP_OBJECT (modifier, radiobutton_modifier_c, "radiobutton_modifier_c");
  GLADE_HOOKUP_OBJECT (modifier, radiobutton_modifier_e, "radiobutton_modifier_e");
  GLADE_HOOKUP_OBJECT (modifier, m_modifier, "m_modifier");
  GLADE_HOOKUP_OBJECT (modifier, spinbutton_modifier_etage, "spinbutton_modifier_etage");
  GLADE_HOOKUP_OBJECT (modifier, spinbutton_modifier_numchambre, "spinbutton_modifier_numchambre");
  GLADE_HOOKUP_OBJECT (modifier, retour_modifier, "retour_modifier");
  GLADE_HOOKUP_OBJECT (modifier, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (modifier, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (modifier, image3, "image3");
  GLADE_HOOKUP_OBJECT (modifier, label15, "label15");
  GLADE_HOOKUP_OBJECT (modifier, label19, "label19");
  GLADE_HOOKUP_OBJECT (modifier, label20, "label20");
  GLADE_HOOKUP_OBJECT (modifier, label21, "label21");
  GLADE_HOOKUP_OBJECT (modifier, label24, "label24");
  GLADE_HOOKUP_OBJECT (modifier, label22, "label22");
  GLADE_HOOKUP_OBJECT (modifier, label23, "label23");

  return modifier;
}

GtkWidget*
create_supprimer (void)
{
  GtkWidget *supprimer;
  GtkWidget *fixed6;
  GtkWidget *entry_supprimer;
  GtkWidget *m_supprimer;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label13;
  GtkWidget *label_supprimer;
  GtkWidget *retour_supprimer;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label14;

  supprimer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (supprimer), _("supprimer"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (supprimer), fixed6);

  entry_supprimer = gtk_entry_new ();
  gtk_widget_show (entry_supprimer);
  gtk_fixed_put (GTK_FIXED (fixed6), entry_supprimer, 112, 112);
  gtk_widget_set_size_request (entry_supprimer, 208, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_supprimer), 8226);

  m_supprimer = gtk_button_new ();
  gtk_widget_show (m_supprimer);
  gtk_fixed_put (GTK_FIXED (fixed6), m_supprimer, 152, 176);
  gtk_widget_set_size_request (m_supprimer, 128, 40);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (m_supprimer), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label13 = gtk_label_new_with_mnemonic (_("supprimer"));
  gtk_widget_show (label13);
  gtk_box_pack_start (GTK_BOX (hbox1), label13, FALSE, FALSE, 0);

  label_supprimer = gtk_label_new (_("num de carte d'identit\303\251 d'\303\251tudiant \303\240 supprimer :"));
  gtk_widget_show (label_supprimer);
  gtk_fixed_put (GTK_FIXED (fixed6), label_supprimer, 32, 48);
  gtk_widget_set_size_request (label_supprimer, 368, 56);

  retour_supprimer = gtk_button_new ();
  gtk_widget_show (retour_supprimer);
  gtk_fixed_put (GTK_FIXED (fixed6), retour_supprimer, 30, 10);
  gtk_widget_set_size_request (retour_supprimer, 100, 40);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (retour_supprimer), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label14 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (hbox2), label14, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) m_supprimer, "clicked",
                    G_CALLBACK (on_m_supprimer_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_supprimer, "clicked",
                    G_CALLBACK (on_retour_supprimer_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) retour_supprimer, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (supprimer));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (supprimer, supprimer, "supprimer");
  GLADE_HOOKUP_OBJECT (supprimer, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (supprimer, entry_supprimer, "entry_supprimer");
  GLADE_HOOKUP_OBJECT (supprimer, m_supprimer, "m_supprimer");
  GLADE_HOOKUP_OBJECT (supprimer, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (supprimer, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (supprimer, image1, "image1");
  GLADE_HOOKUP_OBJECT (supprimer, label13, "label13");
  GLADE_HOOKUP_OBJECT (supprimer, label_supprimer, "label_supprimer");
  GLADE_HOOKUP_OBJECT (supprimer, retour_supprimer, "retour_supprimer");
  GLADE_HOOKUP_OBJECT (supprimer, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (supprimer, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (supprimer, image2, "image2");
  GLADE_HOOKUP_OBJECT (supprimer, label14, "label14");

  return supprimer;
}

GtkWidget*
create_afficher (void)
{
  GtkWidget *afficher;
  GtkWidget *fixed7;
  GtkWidget *retour_afficher;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label18;
  GtkWidget *scrolledwindow1;
  GtkWidget *treeview1;
  GtkWidget *actualiser;

  afficher = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (afficher), _("afficher"));

  fixed7 = gtk_fixed_new ();
  gtk_widget_show (fixed7);
  gtk_container_add (GTK_CONTAINER (afficher), fixed7);

  retour_afficher = gtk_button_new ();
  gtk_widget_show (retour_afficher);
  gtk_fixed_put (GTK_FIXED (fixed7), retour_afficher, 30, 10);
  gtk_widget_set_size_request (retour_afficher, 100, 40);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (retour_afficher), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox6), label18, FALSE, FALSE, 0);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_fixed_put (GTK_FIXED (fixed7), scrolledwindow1, 216, 56);
  gtk_widget_set_size_request (scrolledwindow1, 568, 296);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), treeview1);

  actualiser = gtk_button_new_with_mnemonic (_("actualiser"));
  gtk_widget_show (actualiser);
  gtk_fixed_put (GTK_FIXED (fixed7), actualiser, 864, 368);
  gtk_widget_set_size_request (actualiser, 112, 48);

  g_signal_connect ((gpointer) retour_afficher, "clicked",
                    G_CALLBACK (on_retour_afficher_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) retour_afficher, "clicked",
                            G_CALLBACK (gtk_widget_hide),
                            GTK_OBJECT (affichier));
  g_signal_connect ((gpointer) treeview1, "row_activated",
                    G_CALLBACK (on_treeview1_row_activated),
                    NULL);
  g_signal_connect ((gpointer) actualiser, "clicked",
                    G_CALLBACK (on_actualiser_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (afficher, afficher, "afficher");
  GLADE_HOOKUP_OBJECT (afficher, fixed7, "fixed7");
  GLADE_HOOKUP_OBJECT (afficher, retour_afficher, "retour_afficher");
  GLADE_HOOKUP_OBJECT (afficher, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (afficher, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (afficher, image6, "image6");
  GLADE_HOOKUP_OBJECT (afficher, label18, "label18");
  GLADE_HOOKUP_OBJECT (afficher, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (afficher, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (afficher, actualiser, "actualiser");

  return afficher;
}

