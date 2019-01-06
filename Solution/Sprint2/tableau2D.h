/**
 * @file tableau2D.h
 * @brief Structuration de Tab2D et prototypage des fonctions associées
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 26/12/2018
 */
#ifndef _TABLEAU2D_
#define _TABLEAU2D_
#include "Item.h"

struct Tab2D {
	Item** tab; // adresse du tableau bidimensionnel
							// en mémoire dynamique
	unsigned int nbL; // nombre de lignes de la matrice
	unsigned int nbC; // nombre de colonnes de la matrice
};

// Allouer en mémoire dynamique un Tableau2D
void initialiser(Tab2D& m, unsigned int nbL, unsigned int nbC);
// Desallouer un Tableau2D
void detruire(Tab2D& m);
// Lire un Tableau2D
void lire(Tab2D& m);
// Afficher un Tableau2D
void afficher(const Tab2D& m);

#endif 