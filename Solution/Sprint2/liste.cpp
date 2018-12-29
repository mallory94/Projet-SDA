
#include "Liste.h"


void initialiser_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacité = 1;
	initialiser(liste.premier_element->damier_resultant, nbL, nbC);
	lire(liste.etat_courant->damier_resultant);
	liste.premier_element = liste.etat_courant;
}

