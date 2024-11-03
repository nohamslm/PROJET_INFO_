#include <stdio.h>
#include "menu.h"
#include "joueur.h"

void afficher_menu() {
    printf("Bienvenue dans le jeu Quoridor !\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger une partie\n");
    printf("3. Afficher l'aide\n");
    printf("4. Afficher les scores des joueurs\n");
    printf("5. Quitter le jeu\n");
    printf("Veuillez choisir une option : ");
}

void gerer_choix_menu(int choix) {
    switch (choix) {
        case 1:
            printf("Nouvelle partie sélectionnée.\n");
                int nb_joueurs;
                Joueur joueurs[MAX_JOUEURS];
                printf("Nouvelle partie commencée.\n");
                nb_joueurs = demander_nombre_joueurs();
                initialiser_joueurs(nb_joueurs, joueurs);
                printf("La partie commence avec %d joueurs :\n", nb_joueurs);
                for (int i = 0; i < nb_joueurs; i++) {
                    printf("- %s %s\n", joueurs[i].pseudo, joueurs[i].est_ordinateur ? "(Ordinateur)" : "");
                }
        break;
        case 2:
            printf("Charger une partie sélectionné.\n");
        break;
        case 3:
            printf("Affichage de l'aide.\n");
        break;
        case 4:
            printf("Affichage des scores.\n");
        break;
        case 5:
            printf("Quitter le jeu.\n");
        break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        break;
    }
}