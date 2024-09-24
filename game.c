#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

#include "game.h"
#include "player.h"
#include "graphique.h"

/*********************************************************************************************************************************************************************************/
int lancement_du_jeu()
{
    printw("Bonjour !!! Que veut tu faire ?\n");
     int choix;
    do {
        printw("Nouvelle partie (1)\n"
            "Charger une partie (2)\n");
        refresh();
        scanw("%d", &choix);

        switch (choix) {
            case 1:
                break;

            case 2:
                break;

            default:
                printw("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n");
                refresh();
                break;
        }
    } while (choix != 1 && choix != 2);
    return choix;
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void chargement_partie(int choix, DonneesJoueur * joueur){
    DonneesJoueur old_joueur;
    char nom_fichier[100];

    if(choix == 1){
        initialisation_joueur(joueur);
        premiere_sauvegarde(joueur);
    }

    else
    {

        printw("\nQuel était votre pseudo ?\n");
        refresh();
        scanw("%s", joueur->nom);
        sprintf(nom_fichier, "%s.dat", joueur->nom);
        strcpy(old_joueur.nomFichier, (char*)nom_fichier);
        charger(&old_joueur);
        printw("Bon retour parmi nous %s !!!\n\n", old_joueur.nom);
        clear();
        printw("Pour rappel 2:\n");
        afficher_stat(old_joueur);
        refresh();
        clear();
        printw("Pour rappel 2:\n");
        refresh();
    }
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
/*
void sauvegarder(const DonneesJoueur* joueur) {
    FILE* fichier = fopen(joueur->nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printw("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
    printw("\nSauvegarde en Cour....\n"
                    "...\n"
                    "Sauvegarde Réussi !!!\n\n"
                    "Voulez vous quitter le jeu (1) ? Ou voulez vous continuez (2) ?\n"
                );
}*/
typedef struct {
    char nom[50];
    Race race;
    Classe classe;
    int pv;
    int pm;
    int force;
    int level;
    int exp;
    int emplacement;
    char nomFichier[100];
} DonneesJoueur;

void save_game(Player *player, const char *save_file) {
    FILE *file = fopen(save_file, "w");
    if (file == NULL) {
        perror("Error opening save file");
        return;
    }

    // Write the player's data to the file
    fprintf(file, "Name: %s\n", joueur->nom);
    fprintf(file, "Health: %d\n", joueur->pv);
    fprintf(file, "Level: %d\n", joueur->level);
    fprintf(file, "Experience: %d\n", joueur->exp);
    fprintf(file, "emplacement: %d\n", joueur->emplacement);

    fclose(file);
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void premiere_sauvegarde(const DonneesJoueur* joueur) {
    FILE* fichier = fopen(joueur->nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printw("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
    printw("\nSauvegarde du personnage...\n"
                    "...\n"
                    "Sauvegarde Réussi !!!\n\n"
                    "Avec votre pseudo vous pourrez vous reconnectez !\n"
                );
    sleep(1);
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void charger(DonneesJoueur* joueur) {
    FILE* fichier = fopen(joueur->nomFichier, "rb");
    if (fichier != NULL) {
        fread(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printw("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
int action() {
    printw("Changer de lieu (1)\n");
    printw("Attaquer monstre (2)\n");
    printw("Afficher stats (3)\n");
    printw("Sauvegarder (4)\n");
    printw("Quitter le jeu (5)\n");
//     box();
    int choix;
    scanw("%d", &choix);
    return choix;
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void ville(int choix, DonneesJoueur * joueur){

    switch (choix){
            case 1:
                changer_lieu(joueur);
                break;

            case 2:
                combat(joueur);
                break;

            case 3:
                afficher_stat(*joueur);
                break;

            case 4:
                sauvegarder(joueur);
                int answer;
                scanw("%d", &answer);
                if(answer == 1){
                    printf("\nProgression mit en pause\nMerci d'avoir jouer :)\n");
                }
                break;
            case 5  :
                printw("Progression mis en pause\nMerci d'avoir jouer :)\n");
                refresh();
                sleep(0);
                exit(1);

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                break;
        }
    return;
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void foret(int choix, DonneesJoueur * joueur){

    switch (choix){
            case 1:
                changer_lieu(joueur);
                break;

            case 2:
                combat(joueur);
                break;

            case 3:
                afficher_stat(*joueur);
                break;

            case 4:
                sauvegarder(joueur);
                int answer;
                scanw("%d", &answer);
                if(answer == 1){
                    printf("\nProgression mit en pause\nMerci d'avoir jouer :)\n");
                }
                break;
            case 5  :
                printw("Progression mis en pause\nMerci d'avoir jouer :)\n");
                refresh();
                sleep(0);
                exit(1);

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                break;
        }
    return;
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void montagne(int choix, DonneesJoueur * joueur){

    switch (choix){
            case 1:
                changer_lieu(joueur);
                break;

            case 2:
                combat(joueur);
                break;

            case 3:
                afficher_stat(*joueur);
                break;

            case 4:
                sauvegarder(joueur);
                int answer;
                scanw("%d", &answer);
                if(answer == 1){
                    printf("\nProgression mit en pause\nMerci d'avoir jouer :)\n");
                }
                break;
            case 5  :
                printw("Progression mis en pause\nMerci d'avoir jouer :)\n");
                refresh();
                sleep(0);
                exit(1);

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                break;
        }
    return;
}
/*********************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************/
void boucle_principale(){

    DonneesJoueur joueur;

    int choix = lancement_du_jeu();

    chargement_partie(choix, &joueur);
//     printw("Vous etes actuellement en %d", joueur.emplacement);
    refresh();
    sleep(1);

    while(1){

         printw("Vous etes actuellement en : ");
//         refresh();
         afficher_lieu(&joueur);
         printw("\nQue voulez vous faire ?\n\n");
        choix = action();
        clear();

        if(joueur.emplacement == 0){
             ville(choix, &joueur);
        }
        else if(joueur.emplacement == 1){
             ville(choix, &joueur);
        }
        else if(joueur.emplacement == 2){
            ville(choix, &joueur);
        }
    }
}
/*********************************************************************************************************************************************************************************/
