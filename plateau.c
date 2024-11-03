#include <stdio.h>
#include "plateau.h"

void afficher_plateau(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    printf("   ");
    for (int j = 0; j < TAILLE_PLATEAU; j++) {
        printf(" %d  ", j);
    }
    printf("\n");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf(" %d ", i);
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            char symbole = plateau[i][j].symbole;
            switch (symbole) {
                case '1': printf("\x1B[31m│ %c \x1B[0m", symbole); break;
                case '2': printf("\x1B[32m│ %c \x1B[0m", symbole); break;
                case '3': printf("\x1B[34m│ %c \x1B[0m", symbole); break;
                case '4': printf("\x1B[33m│ %c \x1B[0m", symbole); break;
                default:  printf("│ %c ", symbole); break;
            }
        }
        printf("│\n");
        if (i < TAILLE_PLATEAU - 1) {
            printf("   ");
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                printf("├───");
            }
            printf("┤\n");
        }
    }
}

void initialiser_plateau(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int nb_joueurs) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            plateau[i][j].symbole = ' ';
        }
    }
    plateau[0][TAILLE_PLATEAU / 2].symbole = '1';
    plateau[TAILLE_PLATEAU - 1][TAILLE_PLATEAU / 2].symbole = '2';
    if (nb_joueurs > 2) plateau[TAILLE_PLATEAU / 2][0].symbole = '3';
    if (nb_joueurs > 3) plateau[TAILLE_PLATEAU / 2][TAILLE_PLATEAU - 1].symbole = '4';
}

