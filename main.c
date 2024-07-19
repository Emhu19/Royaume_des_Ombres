#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"

int main(void)
{

    srand(time(NULL));
    DonneesJoueur joueur;
    char nom_fichier[100];
    int choix = lancement_du_jeu();
    joueur = chargement_partie(choix, joueur, nom_fichier);

    Lieu lieux[3] = {
        {"Ville", "Une grande ville pleine d'activité."},
        {"Forêt", "Une forêt sombre et mystérieuse."},
        {"Montagne", "Des sommets enneigés et majestueux."},
    };

    Monstre monstre[3] = {
        {"Gobelin", 20, 20},
        {"Golem", 20, 20},
        {"Dragon", 20, 20},
    };

    int emplacement_joueur = 0;

    while(1){
        printf("\n\nVous etes actuellement en ");
         afficher_lieu(&lieux, emplacement_joueur);
         printf("\nQue voulez vous faire ?\n\n");
        choix = action();

        switch (choix){
            case 1:
                emplacement_joueur = changer_lieu(&lieux);
                break;

            case 2:
                int random_number = rand() % 3;
//                 printf("random = %d\n", random_number);
                printf("\nIl rencontrer un %s !! Il possède %d PV.\n", monstre[random_number].nom, monstre[random_number].pv);
                printf("Il reste %d vie au %s\n", monstre[random_number].pv, monstre[random_number].nom);
                while( joueur.pv > 0 && monstre[random_number].pv > 0){
                    attaquer(&joueur, &monstre[random_number]);
                }
                break;

            case 3:
                afficher_stat(joueur);
                break;

            case 4:
                joueur.level = 1;
                sauvegarder(nom_fichier, &joueur);
                int answer;
                scanf("%d", &answer);
                if(answer == 1){
                    printf("\nProgression mit en pause\nMerci d'avoir jouer :)\n");
                    return 0;
                }
                break;
            case 5  :
                printf("\nProgression mit en pause\nMerci d'avoir jouer :)\n");
                return 0;

            default:
                printf("\nChoix invalide.\n"
                    "Veuillez rentrer une réponse correcte !!!\n\n"
                );
                break;
        }
    }
    printf("\nMerci d'avoir jouer :)\n");
    return 0;
}
