#include <stdio.h>
#include "code.h"
#include <string.h>

int lancement_du_jeu()
{
    printf("\n\n"
            "--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
           "| ######    #####   ##  ##     ##     ##   ##  ##   ##  #######           #####    #######   #####             #####   ##   ##  ######   ######   #######   #####  |\n"
           "|  ##  ##  ##   ##  ##  ##    ####    ##   ##  ### ###   ##   #            ## ##    ##   #  ##   ##           ##   ##  ### ###   ##  ##   ##  ##   ##   #  ##   ## |\n"
           "|  ##  ##  ##   ##  ##  ##   ##  ##   ##   ##  #######   ## #              ##  ##   ## #    #                 ##   ##  #######   ##  ##   ##  ##   ## #    #       |\n"
           "|  #####   ##   ##   ####    ##  ##   ##   ##  #######   ####              ##  ##   ####     #####            ##   ##  #######   #####    #####    ####     #####  |\n"
           "|  ## ##   ##   ##    ##     ######   ##   ##  ## # ##   ## #              ##  ##   ## #         ##           ##   ##  ## # ##   ##  ##   ## ##    ## #         ## |\n"
           "|  ##  ##  ##   ##    ##     ##  ##   ##   ##  ##   ##   ##   #            ## ##    ##   #  ##   ##           ##   ##  ##   ##   ##  ##   ##  ##   ##   #  ##   ## |\n"
           "| #### ##   #####    ####    ##  ##    #####   ##   ##  #######           #####    #######   #####             #####   ##   ##  ######   #### ##  #######   #####  |\n"
           "--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    printf("Bonjour !!! Que veut tu faire ?\n");
     int choix = 0;
    while(choix == 0 ){
        printf("Nouvelle partie (1)\n"
            "Charger une partie (2)\n"
        );
        scanf("%d", &choix);
        switch (choix){
            case 1:
                printf("Vous avez choisi l'option 1.\n");
                break;

            case 2:
                break;

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                choix = 0;
                break;
        }
    }
    return choix;
}

DonneesJeu chargement_partie(int choix, DonneesJeu jeu, char nom_fichier[]){

    DonneesJeu jeuCharge;

    if(choix == 1){
        printf("Création du personnage en cour\n");
        printf(
                "Quel est votre pseudo ?"
            );
        scanf("%s", jeu.nom);
        sprintf(nom_fichier, "%s.dat", jeu.nom);
        printf("%s\n", nom_fichier);
        initialisation_joueur(&jeu);
        afficher_stat(jeu);
        sauvegarder(nom_fichier, &jeu);
        return jeu;
    }
    else
    {
        printf("\nQuel était votre pseudo ?\n");
        scanf("%s", nom_fichier);
        //Merci chatGPG, j'avais rien compris au problème, ici ça venant d'un danger de dépassement de tampon. Donc désormais personne peut me hacker :)
        /*
        if (strlen(nom_fichier) + 4 >= sizeof(nom_fichier)) {
            fprintf(stderr, "Erreur : Nom de fichier trop long.\n");
        } else {
            sprintf(nom_fichier, "%s.dat", nom_fichier);
        }*/
        sprintf(nom_fichier, "%s.dat", nom_fichier);

        //printf("%s\n", nom_fichier);
        charger(nom_fichier, &jeuCharge);
        printf("Bon retour parmi nous %s !!!\n", jeuCharge.nom);
        return  jeuCharge;
    }
    return;
}

// Fonction pour sauvegarder les données du jeu dans un fichier
void sauvegarder(const char* nomFichier, const DonneesJeu* jeu) {
    FILE* fichier = fopen(nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(jeu, sizeof(DonneesJeu), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
}

// Fonction pour charger les données du jeu à partir d'un fichier
void charger(const char* nomFichier, DonneesJeu* jeu) {
    FILE* fichier = fopen(nomFichier, "rb");
    if (fichier != NULL) {
        fread(jeu, sizeof(DonneesJeu), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
}

int action() {
    printf("Afficher stat (1)\n");
    printf("Sauvegarder (2)\n");
    printf("Quitter le jeu (3)\n");
    int choix;
    scanf("%d", &choix);
    return choix;
}

void initialisation_joueur(DonneesJeu * Player)
{
    Player->level = 1;
    Player->pv = 1;
    Player->force = 1;
    Player->pm = 0;
}

void afficher_stat(DonneesJeu Player)
{
    printf("-%s\n", Player.nom);
    printf("-Level : %d\n", Player.level);
    printf("-%d PV\n", Player.pv);
    printf("-%d PM\n", Player.pm);
    printf("-%d FORCE\n", Player.force);
}
