#include <stdio.h>
#include "sauvegarde.h"
#include "joueur.h"
#include "plateau.h"

void sauvegarder_partie(Joueur joueurs[], int nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    FILE *fichier = fopen("sauvegarde.bin", "wb");
    if (!fichier) {
        perror("Erreur lors de la sauvegarde de la partie.");
        return;
    }
    fwrite(&nb_joueurs, sizeof(int), 1, fichier);
    fwrite(joueurs, sizeof(Joueur), nb_joueurs, fichier);
    fwrite(plateau, sizeof(Case), TAILLE_PLATEAU * TAILLE_PLATEAU, fichier);
    fclose(fichier);
}

int charger_partie(Joueur joueurs[], int *nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    FILE *fichier = fopen("sauvegarde.bin", "rb");
    if (!fichier) {
        printf("Aucune sauvegarde trouvée.\n");
        return 0;
    }
    fread(nb_joueurs, sizeof(int), 1, fichier);
    fread(joueurs, sizeof(Joueur), *nb_joueurs, fichier);
    fread(plateau, sizeof(Case), TAILLE_PLATEAU * TAILLE_PLATEAU, fichier);
    fclose(fichier);
    return 1;
}