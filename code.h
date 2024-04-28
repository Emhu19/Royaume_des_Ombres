#ifndef __CODE_H__
#define __CODE_H__

int lancement_du_jeu();
int action();

typedef struct
{
    char nom[50];
    int pv;
    int pm;
    int force;
    int level;
}joueur;


typedef struct {
    char nom[50];
    int pv;
    int pm;
    int force;
    int level;
} DonneesJeu;

DonneesJeu chargement_partie(int choix, DonneesJeu jeu, char nom_fichier[]);

void initialisation_joueur(DonneesJeu * Player);
void afficher_stat(DonneesJeu Player);
void sauvegarder(const char* nomFichier, const DonneesJeu* jeu);
void charger(const char* nomFichier, DonneesJeu* jeu);

#endif
