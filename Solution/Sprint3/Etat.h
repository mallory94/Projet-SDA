#ifndef _ETAT_
#define _ETAT_

#include "tableau2D.h"
enum Mouvement { NORD, EST, SUD, OUEST };

struct Position_du_trou {
	unsigned int ligne, colonne, nb_mouv_possible = 0;
	bool nord = false, ouest = false, sud = false, est = false;
};

struct Etat {
	Etat *etat_precedent;
	Tab2D damier_resultant;
	Mouvement mouvement;
	Tab2D damier_précédent;
	Etat *etat_suivant;
};

// Afficher un état du taquin
void afficher(const Etat& e);

void initialiser_etat(Etat &e, unsigned int &nbL, unsigned int &nbC);

void scan_mouvement_possible(Etat &e, Position_du_trou &position);

#endif