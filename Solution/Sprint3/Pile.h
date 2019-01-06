/**
 * @file Pile.h
 * @brief Composant de pile
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 06/01/2019
 */
#ifndef _PILE_
#define _PILE_

#include "Item.h"

struct Pile {
	unsigned int capacite; // capacité de la pile (c>0) 
	Item* tab; // tableau des éléments de pile en mémoire dynamique
	int sommet; // indice de sommet de pile dans tab
};

void initialiser(Pile& p, unsigned int c);
void detruire(Pile& p);
bool estPleine(const Pile& p);
bool estVide(const Pile& p);
Item sommet(const Pile &p);
void empiler(Pile& p, const Item& it);
void depiler(Pile& p);
#endif