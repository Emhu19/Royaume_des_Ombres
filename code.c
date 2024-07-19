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

DonneesJoueur chargement_partie(int choix, DonneesJoueur joueur, char nom_fichier[]){

    DonneesJoueur old_joueur;

    if(choix == 1){
        initialisation_joueur(&joueur, nom_fichier);
        premiere_sauvegarde(nom_fichier, &joueur);
        return joueur;
    }
    else
    {
        printf("\nQuel était votre pseudo ?\n");
        scanf("%s", nom_fichier);
        sprintf(nom_fichier, "%s.dat", nom_fichier);

        charger(nom_fichier, &old_joueur);
        printf("Bon retour parmi nous %s !!!\n\n", old_joueur.nom);
        printf("Pour rappel voici vos stats :\n");
        afficher_stat(old_joueur);
        return  old_joueur;
    }
    return joueur;
}

void sauvegarder(const char* nomFichier, const DonneesJoueur* joueur) {
    FILE* fichier = fopen(nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
    printf("\nSauvegarde en Cour....\n"
                    "...\n"
                    "Sauvegarde Réussi !!!\n\n"
                    "Voulez vous quitter le jeu (1) ? Ou voulez vous continuez (2) ?\n"
                );
}

void premiere_sauvegarde(const char* nomFichier, const DonneesJoueur* joueur) {
    FILE* fichier = fopen(nomFichier, "wb");
    if (fichier != NULL) {
        fwrite(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
    printf("\nSauvegarde du personnage...\n"
                    "...\n"
                    "Sauvegarde Réussi !!!\n\n"
                    "Avec votre pseudo vous pourrez vous reconnectez !\n"
                );
}

void charger(const char* nomFichier, DonneesJoueur* joueur) {
    FILE* fichier = fopen(nomFichier, "rb");
    if (fichier != NULL) {
        fread(joueur, sizeof(DonneesJoueur), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde.\n");
    }
}

int action() {
    printf("Changer de lieu (1)\n");
    printf("Attaquer monstre (2)\n");
    printf("Afficher stats (3)\n");
    printf("Sauvegarder (4)\n");
    printf("Quitter le jeu (5)\n");
    int choix;
    scanf("%d", &choix);
    return choix;
}

void afficher_lieu(Lieu * lieu, int n) {
    printf("%s", lieu[n].nom);
}

int changer_lieu(Lieu * lieux){
    printf("\n");
    int emplacement_joueur;
    for(int i = 0; i < 3; i++){
        printf("%d. %s - %s\n", i + 1, lieux[i].nom, lieux[i].description);
    }
    scanf("%d", &emplacement_joueur);
    return emplacement_joueur - 1;
}

void initialisation_joueur(DonneesJoueur * joueur, char nom_fichier[])
{
    printf("\n[Création du personnage]\n"
    "\nQuel est votre pseudo ?\n"
    );
    scanf("%s", joueur->nom);
    printf("\nBienvenue %s\n\n", joueur->nom);
    sprintf(nom_fichier, "%s.dat", joueur->nom);
    joueur->level = 10;
    joueur->pv = 10;
    joueur->force = 10;
    joueur->pm = 10;
    choisir_race(joueur);
    choisir_classe(joueur);
    afficher_stat(*joueur);
}

void afficher_race(){
    printf("Liste des races disponibles :\n\n"
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
}

void choisir_race(DonneesJoueur * joueur){
    printf("[Choix de la Race]\n");
    afficher_race();
    int choix;
    scanf("%d", &choix);

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
            printf("Choix indisponible");
            break;
    }
}

void afficher_classe(){
    printf("Liste des races disponibles :\n\n"
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
}

void choisir_classe(DonneesJoueur * joueur){
    printf("[Choix de la Classe]\n");
    afficher_classe();
    int choix;
    scanf("%d", &choix);

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
            printf("Choix indisponible");
            break;
    }
}

void afficher_stat(DonneesJoueur joueur)
{
    printf("\nVoici vos stats : \n");
    switch (joueur.race) {
        case HUMAIN:
            printf("[Race] : Humain\n");
            break;
        case ELFE:
            printf("[Race] : Elfe\n");
            break;
        case NAIN:
            printf("[Race] : Nain\n");
            break;
        default:
            printf("[Race] : Inconnu\n");
            break;
    }

    switch (joueur.classe) {
        case GUERRIER:
            printf("[Classe] : Guerrier\n");
            break;
        case VOLEUR:
            printf("[Classe] : Voleur\n");
            break;
        case MAGE:
            printf("[Classe] : Mage\n");
            break;
        default:
            printf("[Classe] : Inconnu\n");
            break;
    }

    printf("[Niveau] : %d\n", joueur.level);
    printf("[PV] : %d\n", joueur.pv);
    printf("[PM] : %d\n", joueur.pm);
    printf("[FORCE] : %d\n", joueur.force);
}

void attaquer(DonneesJoueur * attaquant, Monstre * cible) {
    int degats = attaquant->force;
    cible->pv -= degats;
    printf("Le personnage inflige %d points de dégâts à la cible.\n", degats);
    printf("Il reste %d vie au %s", cible->pv, cible->nom);
}
