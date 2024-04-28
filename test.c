#include <stdio.h>

// Structure représentant les données du jeu à sauvegarder
typedef struct {
    // Ajoutez les champs nécessaires pour représenter l'état du jeu
    int niveau;
    char nom[50];
    // ...
} DonneesJeu;

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

int main() {
    DonneesJeu jeu;

    // Exemple de sauvegarde
    jeu.niveau = 4;
    snprintf(jeu.nom, sizeof(jeu.nom), "Joueur1");
    sauvegarder("sauvegarde.dat", &jeu);

    // Exemple de chargement
    DonneesJeu jeuCharge;
    charger("sauvegarde.dat", &jeuCharge);

    // Affichage des données chargées
    printf("Niveau chargé : %d\n", jeuCharge.niveau);
    printf("Nom chargé : %s\n", jeuCharge.nom);

    return 0;
}
