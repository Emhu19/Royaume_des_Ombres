#include <ncurses.h>

#include "player.h"
#include "game.h"
#include "ncurses_helper.h"
#include "utils.h"
#include "combat.h"
#include "map.h"

extern DonneesJoueur joueur;
extern char nom_fichier;

Lieu lieux[3] = {
        {"Ville", "Une grande ville pleine d'activité."},
        {"Forêt", "Une forêt sombre et mystérieuse."},
        {"Montagne", "Des sommets enneigés et majestueux."},
    };

void afficher_lieu(DonneesJoueur * joueur) {
    printw("%s", lieux[joueur->emplacement].nom);
}

void changer_lieu(DonneesJoueur * joueur){

    printw("\n");
    int emplacement_joueur;
    for(int i = 0; i < 3; i++){
        printw("%d. %s - %s\n", i + 1, lieux[i].nom, lieux[i].description);
    }
    scanw("%d", &emplacement_joueur);
    joueur->emplacement = emplacement_joueur - 1;
}
