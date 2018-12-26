#ifndef _TAQUIN_
#define _TAQUIN_

#include "Etat.h"
#include "Liste.h"

struct Taquin {
	Liste LEAE;
	Liste LEE;
	unsigned int nbL;
	unsigned int nbC;
};

// Créer le jeu de taquin avec l'état initial
void initialiser(Taquin& t);

// Itération de l'algorithme de recherche
void jouer(Taquin& t);

// Afficher le contenu des listes à dev et dev
void afficher(Taquin& t);

#endif
