#ifndef _LISTE_
#define _LISTE_

/**
* @file Liste.h
* @brief Composant de liste
*/

#include "Etat.h"
#include "tableau2D.h"

struct Liste {
	Etat *premier_element;
	Etat *etat_courant;
	unsigned int capacit�;
};


void initialiser_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC);

// Analyse si il existe un unique �tat de LEAE avec une valeur g minimale
/*bool unique_etat_min(Liste& Liste) {
	bool indicateur; //indique si 
	for (unsigned int i = 0; i < Liste.capacit�; i++) {
		
	}
}

*/

#endif
