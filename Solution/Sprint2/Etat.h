#ifndef _ETAT_
#define _ETAT_

#include "tableau2D.h"
enum Mouvement { NORD, EST, SUD, OUEST };

struct Etat {
	Tab2D damier_resultant;
	Mouvement mouvement;
	Tab2D damier_précédent;
	Etat *etat_suivant;
};

// Afficher un état du taquin
void afficher(const Etat& e);


#endif