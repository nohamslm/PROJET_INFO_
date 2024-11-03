#ifndef HEADER_H
#define HEADER_H
#include "joueur.h"
#include "plateau.h"
// Constantes globales
#define TAILLE_PLATEAU 9


// Déclarations des fonctions du jeu et des modules
void afficher_menu();
void initialiser_joueurs(int nb_joueurs, Joueur joueurs[]);
void initialiser_plateau(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int nb_joueurs);
void deplacer_pion(Joueur *pseudo_joueur, Case jeu_plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], int direction);
void placer_barriere(Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void afficher_resultats(Joueur joueurs[], int nb_joueurs);
void sauvegarder_partie(Joueur joueurs[], int nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
int charger_partie(Joueur joueurs[], int *nb_joueurs, Case plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void afficher_aide();

#endif