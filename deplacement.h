#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H
#include "joueur.h"
#include "plateau.h"

void jouer_tour(Joueur *joueur, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);

void deplacer_pion(Joueur *pseudo_joueur, Case jeu_plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int direction);

void placer_barriere(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);

#endif
