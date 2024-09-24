#include <ncurses.h>
#include <unistd.h>

#include "player.h"
#include "combat.h"
#include "utils.h"

Monstre monstre[3] = {
        {"Gobelin", 20, 1, 10},
        {"Golem", 20, 2, 15},
        {"Dragon", 20, 3, 20},
    };

void attaquer(DonneesJoueur * player, Monstre monstre) {
    int degats_player = player->force;
    int degats_monstre = monstre.force;
    while(player->pv > 0 && monstre.pv > 0){
        monstre.pv -= degats_player;
        player->pv -= degats_monstre;
        printw("Vous infligez %d points de dégâts au monstre.\n", degats_player);
        printw("Le montre vous inflige %d points de dégâts à la monstre.\n", degats_monstre);
        printw("Il reste %d vie au %s\n", monstre.pv, monstre.nom);
        printw("Vous restez %d vie\n\n", player->pv);
        refresh();
        sleep(2);
    }
}

void mort(DonneesJoueur * player, Monstre monstre){
    clear();
    if(player->pv <= 0)
        printw("Vous etes mort\n");
    else{
        printw("Le %s est mort\n", monstre.nom);
        printw("Vous gagnez %d d'expérience\n", monstre.exp);
        player->exp += monstre.exp;
    }
    refresh();
    sleep(2);
}

void combat(DonneesJoueur * player){

    clear();
    int random_number = random_int(0, 2);
    printw("random = %d\n", random_number);
    printw("\nIl rencontrer un %s !! Il possède %d PV.\n", monstre[random_number].nom, monstre[random_number].pv);
    printw("Il reste %d vie au %s\n", monstre[random_number].pv, monstre[random_number].nom);
    refresh();
    sleep(2);
    clear();

    attaquer(player, monstre[random_number]);

    clear();
    mort(player, monstre[random_number]);
}
