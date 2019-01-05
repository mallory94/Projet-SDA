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

// Cr�er le jeu de taquin avec l'�tat initial
void initialiser(Taquin& t);

// It�ration de l'algorithme de recherche
void jouer(Taquin& t);

// Afficher le contenu des listes � dev et dev
void afficher(Taquin& t);

/* v�rifie si il �xiste un unique �tat de LEAE est de valeur
* g minimale
*
*/

// d�salloue la m�moire du taquin
void detruire_taquin(Taquin& t);

#endif