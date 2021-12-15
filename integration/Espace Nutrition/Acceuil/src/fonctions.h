#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <gtk/gtk.h>

typedef struct Menus
{
    int jours ;
    int tp;
    char pe[50];
    char pp[50];
    char pf[50];
    
    


}Menus;
void afficher_menu(GtkWidget *liste);
void rechercher_menu(GtkWidget *liste, char x1[],char x2[],char x3[],char ce[]);
void ajouter(Menus menu);
void Supprimer(Menus R);
int rechercher(Menus R);
void afficher(Menus menu);
void modifier(Menus new);
void dashboard(char T[]);
void afficher_Dash(GtkWidget *liste,int c);

#endif
