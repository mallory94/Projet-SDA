#infdef _PILE_
#define _PILE_

/**
* @file Pile.h
* @brief Composant de pile
*/
#include Item.h

struct Pile {
	unsigned int capacite; // capacité de la pile (c>0) 
	Item* tab; // tableau des éléments de pile en mémoire dynamique
	int sommet; // indice de sommet de pile dans tab
};

void initialiser(Pile& p, unsigned int c);
void detruire(Pile& p);
bool estPleine(const Pile& p);
bool estVide(const Pile& p);
Item sommet(constPile &p);
void empiler(Pile& p, const Item& it);
void depiler(Pile& p);
#endif