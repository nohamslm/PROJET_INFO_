#include <stdio.h>
#include "aide.h"

void afficher_aide() {
    printf("\n--- Aide du jeu Quoridor ---\n");
    printf("Objectif du jeu : Atteindre la ligne opposée à votre position de départ.\n");
    printf("Chaque joueur peut avancer son pion d'une case (verticalement ou horizontalement) ou placer une barrière.\n");
    printf("Les barrières bloquent temporairement le chemin des adversaires, mais il doit toujours rester un chemin possible.\n");
    printf("Nombre de joueurs : 2 ou 4. Si un nombre impair est choisi, un ordinateur complète le groupe.\n");
    printf("Bon jeu !\n");
}