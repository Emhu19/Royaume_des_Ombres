#ifndef __CODE_H__
#define __CODE_H__

int lancement_du_jeu();
int action();

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
} DonneesJoueur;
/*
typedef enum {
    Gobelin,
    Golem,
    Dragon,
} Type_Monstre;
*/
typedef struct {
    char nom[30];
    int pv;
    int force;
} Monstre;

typedef struct {
    char nom[50];
    char description[100];
} Lieu;

DonneesJoueur chargement_partie(int choix, DonneesJoueur jeu, char nom_fichier[]);

void initialisation_joueur(DonneesJoueur * Player, char nom_fichier[]);
void afficher_stat(DonneesJoueur Player);
void sauvegarder(const char* nomFichier, const DonneesJoueur* jeu);
void charger(const char* nomFichier, DonneesJoueur* jeu);
void afficher_race();
void choisir_race(DonneesJoueur * jeu);
void afficher_classe();
void choisir_classe(DonneesJoueur * jeu);
void afficher_lieu(Lieu * lieu, int n);
int changer_lieu(Lieu * lieu);
void attaquer(DonneesJoueur *attaquant, Monstre *cible);

#endif
