#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"
#include "map.h"
#include "combat.h"

int lancement_du_jeu();
int action();

/*
typedef enum {
    Gobelin,
    Golem,
    Dragon,
} Type_Monstre;
*/

void chargement_partie(int choix, DonneesJoueur * jeu);

void printHeader();
void premiere_sauvegarde(const DonneesJoueur* joueur);
void sauvegarder(const DonneesJoueur* jeu);
void charger(DonneesJoueur* jeu);
void boucle_principale();
void ville(int choix, DonneesJoueur * joueur);
void foret(int choix, DonneesJoueur * joueur);
void montagne(int choix, DonneesJoueur * joueur);

#endif
