#include <gtk/gtk.h>

/*typedef struct Date
{
int jour;
int mois;
int annee;
}date;
*/
typedef struct Utilisateur
{
char nom[50];
char prenom[50];
char id;
char password[50];
char role[50];
char niv;
int jour;
int mois;
int annee;
}utilisateur;



void ajouter_utilisateur(utilisateur p);
void afficher_utilisateur();
void modifier_utilisateur(utilisateur p);
void supprimer_utilisateur(utilisateur p);
utilisateur rechercher_utilisateur(utilisateur p);
int nb_niveau(utilisateur p);
//void role(int choix,utilisateur p);
