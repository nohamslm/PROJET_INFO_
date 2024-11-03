#include <stdio.h>
#include "menu.h"
#include "score.h"
#include "aide.h"
#include "sauvegarde.h"
#include "joueur.h"
#include "plateau.h"
#include "deplacement.h"

int main() {
    int choix;
    int nb_joueurs = 0;
    int partie_chargee = 0;
    Joueur joueurs[4];
    do {
        afficher_menu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Entrez le nombre de joueurs: ");
            scanf("%d", &nb_joueurs);
            initialiser_joueurs(nb_joueurs, joueurs);
            Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
            initialiser_plateau(plateau, nb_joueurs);
            afficher_plateau(plateau);
            partie_chargee = 1;
            int partie_terminee = 0;
            while (!partie_terminee) {
                for (int i = 0; i < nb_joueurs; i++) {
                    if (joueurs[i].elimine == 0) {
                        jouer_tour(&joueurs[i], plateau);
                        afficher_plateau(plateau);
                        if (verifier_victoire(&joueurs[i])) {
                            partie_terminee = 1;
                            break;
                        }
                    }
                }
            }
            afficher_resultats(joueurs, nb_joueurs);
            break;
            case 2:
                if (charger_partie(joueurs, &nb_joueurs, plateau)) {
                    printf("Partie chargée avec succès.\n");
                    partie_chargee = 1;
                } else {
                    printf("Échec du chargement de la partie.\n");
                }
            break;
            case 3:
                afficher_aide();
            break;
            case 4:
                if (partie_chargee) {
                    afficher_resultats(joueurs, nb_joueurs);
                } else {
                    printf("Aucune partie en cours.\n");
                }
            break;
            case 5:
                printf("Merci d'avoir joué à Quoridor ! À bientôt.\n");
            break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
            break;
        }
    } while (choix != 5);

    return 0;
}