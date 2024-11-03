#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 9

typedef struct {
    char symbole;
} Case;

void initialiser_plateau(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int nb_joueurs);

void afficher_plateau(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);

#endif
