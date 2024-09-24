#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#include "game.h"
#include "player.h"

/*********************************************************************************************************************************************************************************/
void initialisation_joueur(DonneesJoueur * joueur)
{
    char nom_fichier[100];
    clear();
    printw("[Création du personnage]\n"
    "\nQuel est votre pseudo ?\n"
    );
    scanw("%s", joueur->nom);
    printw("\nBienvenue %s\n\n", joueur->nom);
    sprintf(nom_fichier, "%s.dat", joueur->nom);

    joueur->pv = 10;
    joueur->force = 10;
    joueur->pm = 10;
    joueur->level = 10;
    joueur->exp = 0;
    joueur->emplacement = 0;
    strcpy(joueur->nomFichier, nom_fichier);

//     sleep(1);
    clear();
    choisir_race(joueur);
//     sleep(1);
    clear();
    choisir_classe(joueur);
//     sleep(1);
    clear();
    afficher_stat(*joueur);
    clear();
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void afficher_race(){

    printw("Liste des races disponibles :\n\n"
        "(1) [Humain] ==> [Force] + 1\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] - 1 \n\n"
        "(2) [Elfe]   ==> [Force] - 1\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] + 2\n\n"
        "(3) [Nain]   ==> [Force] + 2\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] - 1\n\n"
    );
    refresh();
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void choisir_race(DonneesJoueur * joueur){
    printw("[Choix de la Race]\n");
    refresh();
    afficher_race();
    int choix;
    scanw("%d", &choix);

    switch (choix) {
        case 1: //Humain
            joueur->pv += 1;
            joueur->pm += 1;
            joueur->force +=1;
            joueur->race = HUMAIN;
            break;
        case 2: //Elfe
            joueur->pv += 1;
            joueur->pm += 2;
            joueur->force -=1;
            joueur->race = ELFE;
            break;
        case 3: //Nain
            joueur->pv += 1;
            joueur->pm -= 1;
            joueur->force += 2;
            joueur->race = NAIN;
            break;
        default:
            printw("Choix indisponible");
            break;
    }
    refresh();
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void afficher_classe(){
    printw("Liste des races disponibles :\n\n"
        "(1) [Guerrier] ==> [Force] + 1\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] - 1 \n\n"
        "(2) [Mage]   ==> [Force] - 1\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] + 2\n\n"
        "(3) [Voleur]   ==> [Force] + 2\n"
        "             ==> [PV] + 1\n"
        "             ==> [PM] - 1\n\n"
    );
    refresh();
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void choisir_classe(DonneesJoueur * joueur){
    printw("[Choix de la Classe]\n");
    afficher_classe();
    int choix;
    scanw("%d", &choix);

    switch (choix) {
        case 1: //Guerrier
            joueur->pv += 1;
            joueur->pm += 1;
            joueur->force +=1;
            joueur->classe = GUERRIER;
            break;
        case 2: //Mage
            joueur->pv += 1;
            joueur->pm += 2;
            joueur->force -=1;
            joueur->classe = MAGE;
            break;
        case 3: //Voleur
            joueur->pv += 1;
            joueur->pm -= 1;
            joueur->force += 2;
            joueur->classe = VOLEUR;
            break;
        default:
            printw("Choix indisponible");
            break;
    }
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void afficher_stat(DonneesJoueur joueur)
{
    printw("Voici vos stats : \n");
    switch (joueur.race) {
        case HUMAIN:
            printw("[Race] : Humain\n");
            break;
        case ELFE:
            printw("[Race] : Elfe\n");
            break;
        case NAIN:
            printw("[Race] : Nain\n");
            break;
        default:
            printw("[Race] : Inconnu\n");
            break;
    }

    switch (joueur.classe) {
        case GUERRIER:
            printw("[Classe] : Guerrier\n");
            break;
        case VOLEUR:
            printw("[Classe] : Voleur\n");
            break;
        case MAGE:
            printw("[Classe] : Mage\n");
            break;
        default:
            printw("[Classe] : Inconnu\n");
            break;
    }

    printw("[Niveau] : %d\n", joueur.level);
    printw("[Expérience] : %d\n", joueur.exp);
    printw("[PV] : %d\n", joueur.pv);
    printw("[PM] : %d\n", joueur.pm);
    printw("[FORCE] : %d\n", joueur.force);
    printw("\n\nPress enter to continue");
    refresh();
    getch();
}
/*********************************************************************************************************************************************************************************/
