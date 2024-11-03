#include <stdio.h>
#include "joueur.h"
#include "header.h"
#define MIN_JOUEURS 2
#define MAX_JOUEURS 4
#define NOMBRE_BARRIERES 10

int demander_nombre_joueurs() {
    int nb_joueurs;
    do {
        printf("Combien de joueurs ? (%d ou %d) : ", MIN_JOUEURS, MAX_JOUEURS);
        scanf("%d", &nb_joueurs);
        if (nb_joueurs != MIN_JOUEURS && nb_joueurs != MAX_JOUEURS) {
            printf("Nombre invalide. Choisissez %d ou %d joueurs.\n", MIN_JOUEURS, MAX_JOUEURS);
        }
    } while (nb_joueurs != MIN_JOUEURS && nb_joueurs != MAX_JOUEURS);
    return nb_joueurs;
}

void initialiser_joueurs(int nb_joueurs, Joueur joueurs[]) {
    for (int i = 0; i < nb_joueurs; i++) {
        printf("Entrez le pseudo du joueur %d : ", i + 1);
        scanf("%s", joueurs[i].pseudo);
        joueurs[i].position_x = (i % 2) ? TAILLE_PLATEAU - 1 : 0;
        joueurs[i].position_y = (i < 2) ? TAILLE_PLATEAU / 2 : 0;
        joueurs[i].barrieres_restantes = NOMBRE_BARRIERES;
        joueurs[i].symbole = '1' + i;
    }
}