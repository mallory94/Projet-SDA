#ifndef _ETAT_
#define _ETAT_

#include "tableau2D.h"

struct Etat {
	Tab2D damier_resultant;
	enum etat {NORD, EST, SUD, OUEST};
	Tab2D damier_précédent;
};

// Afficher un état du taquin
void afficher(const Etat& e);
	
#endif