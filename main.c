#include <stdio.h>
#include <string.h>
#include "code.h"

int main(void)
{
    DonneesJeu jeu;
    char nom_fichier[100];

    int choix = lancement_du_jeu();
    jeu = chargement_partie(choix, jeu, nom_fichier);

    /*
    while(1){
        printf("Que voulez vous faire ?\n");
        choix = action();
        switch (choix){
            case 1:
                printf("Vous avez choisi l'option 1.\n");
                afficher_stat(jeu);
                break;

            case 2:
                printf("Vous avez choisi l'option 2.\n");
                jeu.level = 5;
                snprintf(jeu.nom, sizeof(jeu.nom), "Jilal");
                sauvegarder(nom_fichier, &jeu);
                break;

            case 3:
                printf("Vous avez choisi l'option 3.\n");
                break;

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                break;
        }
        break;
    }
    */
    printf("Merci d'avoir jouer :)\n");
    return 0;
}
