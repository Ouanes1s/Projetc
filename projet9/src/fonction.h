#include <gtk/gtk.h>



typedef struct Capteur
{
char nom[50] ;
char id[10] ;
int nbcapt ;
char type[50] ;
char prix[20] ;
char date [20] ;
char marque[50] ;
char etat[50] ;// 1 si non défectueux , -1 si défectueux
}capteur 
;


void ajouter_capteur(capteur c);
void modifier_capteur (capteur c);
void supprimer_capteur (char id );
void afficher_capteur (GtkWidget* list);
int chercher(char id,char fich[20]);
void vider(GtkWidget *list);
