#include <gtk/gtk.h>


void
on_sign_up_button_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modif_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_recherche_utilisateur_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_supprimer_utilisateur_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_utilisateur_clicked (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_login_button_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radioetudiant_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioprofesseur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioparent_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_uradiobutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_uradiobutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_uradiobutton3_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ucheckbutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ucheckbutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ucheckbutton3_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficher_utilisateur_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_utreeview1_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retur_login_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_actualiser_utilisateur_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_return_login_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radioprofesseur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioenseignant_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
