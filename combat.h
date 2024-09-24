#ifndef COMBAT_H
#define COMBAT_H

#include "player.h"


typedef struct {
    char nom[30];
    int pv;
    int force;
    int exp;
} Monstre;

void attaquer(DonneesJoueur * player, Monstre monstre);
void mort(DonneesJoueur * player, Monstre monstre);
void combat(DonneesJoueur * player);

#endif
