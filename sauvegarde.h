#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
#include "joueur.h"
#include "plateau.h"

void sauvegarder_partie(Joueur joueurs[], int nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);

int charger_partie(Joueur joueurs[], int *nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);

#endif