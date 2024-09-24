#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef enum {
    HUMAIN,
    ELFE,
    NAIN,
} Race;

typedef enum {
    GUERRIER,
    MAGE,
    VOLEUR,
} Classe;

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

void initialisation_joueur(DonneesJoueur * Player);
void afficher_race();
void choisir_race(DonneesJoueur * jeu);
void afficher_classe();
void choisir_classe(DonneesJoueur * jeu);
void afficher_stat(DonneesJoueur Player);


#endif
