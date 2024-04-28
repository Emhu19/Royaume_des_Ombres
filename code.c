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
     int choix;
    do {
        printf("Nouvelle partie (1)\n"
            "Charger une partie (2)\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                break;

            case 2:
                break;

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n");
                break;
        }
    } while (choix != 1 && choix != 2);

    return choix;
}

DonneesJeu chargement_partie(int choix, DonneesJeu jeu, char nom_fichier[]){

    DonneesJeu jeuCharge;

    if(choix == 1){
        initialisation_joueur(&jeu, nom_fichier);
        sauvegarder(nom_fichier, &jeu);
        return jeu;
    }
    else
    {
        printf("\nQuel était votre pseudo ?\n");
        scanf("%s", nom_fichier);
        sprintf(nom_fichier, "%s.dat", nom_fichier);

        charger(nom_fichier, &jeuCharge);
        printf("Bon retour parmi nous %s !!!\n", jeuCharge.nom);
        afficher_stat(jeuCharge);
        return  jeuCharge;
    }
    return jeu;
}

void sauvegarder(const char* nomFichier, const DonneesJeu* jeu) {
    FILE* fichier = fopen(nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(jeu, sizeof(DonneesJeu), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
}

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

void initialisation_joueur(DonneesJeu * jeu, char nom_fichier[])
{
    printf("\n[Création du personnage]\n"
    "\nQuel est votre pseudo ?\n"
    );
    scanf("%s", jeu->nom);
    printf("\nBienvenue %s\n\n", jeu->nom);
    sprintf(nom_fichier, "%s.dat", jeu->nom);
    jeu->level = 10;
    jeu->pv = 10;
    jeu->force = 10;
    jeu->pm = 10;
    choisir_race(jeu);
    afficher_stat(*jeu);
}

void afficher_race(){
    printf("Liste des races disponibles :\n\n"
        "(1) [Humain] ==> [Force] + 1\n"
        "         ==> [PV] + 1\n"
        "         ==> [PM] - 1 \n\n"
        "(2) [Elfe]   ==> [Force] - 1\n"
        "         ==> [PV] + 1\n"
        "         ==> [PM] + 2\n\n"
        "(3) [Nain]   ==> [Force] + 2\n"
        "         ==> [PV] + 1\n"
        "         ==> [PM] - 1\n\n"
    );
}

void choisir_race(DonneesJeu * jeu){
    printf("[Choix de la Race]\n");
    afficher_race();
    int choix;
    scanf("%d", &choix);

    switch (choix) {
        case 1: //Humain
            jeu->pv += 1;
            jeu->pm += 1;
            jeu->force +=1;
            break;
        case 2: //Elfe
            jeu->pv += 1;
            jeu->pm += 2;
            jeu->force -=1;
            break;
        case 3: //Nain
            jeu->pv += 1;
            jeu->pm -= 1;
            jeu->force += 2;
            break;
        default:
            printf("Choix indisponible");
            break;
    }
}

void afficher_stat(DonneesJeu Player)
{
    printf("-%s\n", Player.nom);
    printf("-Level : %d\n", Player.level);
    printf("-%d PV\n", Player.pv);
    printf("-%d PM\n", Player.pm);
    printf("-%d FORCE\n", Player.force);
}
