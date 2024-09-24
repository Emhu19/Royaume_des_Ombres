#ifndef MAP_H
#define MAP_H

#include <ncurses.h>

typedef struct {
    char nom[50];
    char description[100];
} Lieu;

void afficher_lieu(DonneesJoueur * joueur);
void changer_lieu(DonneesJoueur * joueur);

#endif
