#ifndef JOUEUR_H
#define JOUEUR_H
#define MAX_JOUEURS 4
#define MIN_JOUEURS 2

typedef struct {
    char pseudo[50];
    int est_ordinateur;
    int position_x;
    int position_y;
    int barrieres_restantes;
    int symbole;
    int score;
    int elimine;
} Joueur;

void initialiser_joueurs(int nb_joueurs, Joueur joueurs[]);

int demander_nombre_joueurs();

#endif