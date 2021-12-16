#include <gtk/gtk.h>

typedef struct
{
	char id[100];
	char nom[100];
	char email[100];
	char tel[20];
	char probleme[100];
}Restauration;

void ajouter_RR( Restauration r);
void afficher_RR( GtkWidget *liste);
void modifier_RR( Restauration r);
void supprimer_RR( char id[]);
//Restauration find_RR(char id[]);
int rechercher_id_R(char id[]);
