#include <stdio.h>
#include <time.h>
#include "deplacement.h"
#include "plateau.h"
#include "joueur.h"
#include "header.h"

#define TEMPS_LIMITE 60

void jouer_tour(Joueur *joueur, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    int choix = 0;
    time_t debut = time(NULL);
    while (difftime(time(NULL), debut) < TEMPS_LIMITE) {
        printf("\nTour de %s\n", joueur->pseudo);
        printf("1. Déplacer le pion\n");
        printf("2. Placer une barrière\n");
        printf("Choisissez une action : ");
        scanf("%d", &choix);
        printf("Choix: %d\n", choix);

        if (difftime(time(NULL), debut) >= TEMPS_LIMITE) {
            printf("Temps écoulé ! Tour passé.\n");
            break;
        }
        if (choix == 1) {
            int direction;
            printf("Direction (1=Haut, 2=Bas, 3=Gauche, 4=Droite) : ");
            scanf("%d", &direction);
            printf("Direction choisie: %d\n", direction);
            if (direction >= 1 && direction <= 4) {
                deplacer_pion(joueur, plateau, direction);
                break;
            } else {
                printf("Direction invalide.\n");
            }
        } else if (choix == 2 && joueur->barrieres_restantes > 0) {
            printf("Placement d'une barrière.\n");1
            joueur->barrieres_restantes--;
            break;
        } else {
            printf("Action invalide ou plus de barrières disponibles. Réessayez.\n");
        }
    }
    if (difftime(time(NULL), debut) >= TEMPS_LIMITE) {
        printf("Temps écoulé ! Tour passé.\n");
    }
}

void deplacer_pion(Joueur *joueur, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int direction) {
    int x = joueur->position_x;
    int y = joueur->position_y;
    int nouveau_x = x, nouveau_y = y;
    printf("Position actuelle du joueur (%d, %d)\n", x, y);
    switch (direction) {
        case 1: nouveau_x = x - 1; break;
        case 2: nouveau_x = x + 1; break;
        case 3: nouveau_y = y - 1; break;
        case 4: nouveau_y = y + 1; break;
        default: printf("Direction invalide.\n"); return;
    }
    printf("Nouvelle position (%d, %d)\n", nouveau_x, nouveau_y); // Debug log
    if (nouveau_x >= 0 && nouveau_x < TAILLE_PLATEAU && nouveau_y >= 0 && nouveau_y < TAILLE_PLATEAU) {
        if (plateau[nouveau_x][nouveau_y].symbole == ' ') {
            plateau[x][y].symbole = ' ';
            plateau[nouveau_x][nouveau_y].symbole = joueur->symbole;
            joueur->position_x = nouveau_x;
            joueur->position_y = nouveau_y;
        } else {
            printf("Déplacement impossible, il y a une barrière !\n");
        }
    } else {
        printf("Déplacement hors des limites !\n");
    }
}