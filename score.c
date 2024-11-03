#include <stdio.h>
#include "score.h"
#include "plateau.h"
#include "joueur.h"

int verifier_victoire(const Joueur *joueur) {
    if ((joueur->symbole == '1' && joueur->position_x == TAILLE_PLATEAU - 1) ||
        (joueur->symbole == '2' && joueur->position_x == 0) ||
        (joueur->symbole == '3' && joueur->position_y == TAILLE_PLATEAU - 1) ||
        (joueur->symbole == '4' && joueur->position_y == 0)) {
        return 1;
        }
    return 0;
}

void afficher_resultats(Joueur joueurs[], int nb_joueurs) {
    int gagnant = -1;
    printf("\n--- Résultats finaux ---\n");

    for (int i = 0; i < nb_joueurs; i++) {
        joueurs[i].score = joueurs[i].barrieres_restantes * 5;  // Exemple : chaque barrière restante vaut 5 points
        printf("%s (Joueur %c) - Score : %d\n", joueurs[i].pseudo, joueurs[i].symbole, joueurs[i].score);
        if (verifier_victoire(&joueurs[i])) {
            gagnant = i;
        }
    }
    if (gagnant != -1) {
        printf("\n>>> Félicitations à %s, le gagnant de la partie ! <<<\n", joueurs[gagnant].pseudo);
    } else {
        printf("La partie se termine sans gagnant.\n");
    }
}
