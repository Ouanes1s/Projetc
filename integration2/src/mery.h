#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


struct etudiant_heberge
{
    char nom[30];
    char prenom[30];
    char id[20];
    char paiement[10];
    int etage;
    int numchambre;

};
typedef struct etudiant_heberge eh;
eh e;
void mery_ajout (eh e) ;
void mery_supprimer(eh e);
void mery_modifier(eh e);
void mery_recherche(eh e);
void mery_afficher(GtkTreeView *liste);
