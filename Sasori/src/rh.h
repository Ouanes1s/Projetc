#include <gtk/gtk.h>

typedef struct
{
	char id[100];
	char nom[100];
	char email[100];
	char tel[20];
	char probleme[100];
}Hebergement;

void ajouter_RH( Hebergement h);
void afficher_RH( GtkWidget *liste);
void modifier_RH( Hebergement h);
void supprimer_RH( char id[]);
Hebergement find_RH(char id[]);
int rechercher_id_H(char id[]);

