
#include "Liste.h"
#include <cstdio>
#include "Etat.h"

void initialiser_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacité = 1;
	liste.premier_element = new Etat;
	initialiser(liste.premier_element->damier_resultant, nbL, nbC);
	lire(liste.premier_element->damier_resultant);
	liste.etat_courant = liste.premier_element;
}

void initialiser_LEE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacité = 0;
	liste.etat_courant = NULL;
	liste.premier_element = liste.etat_courant;
}

/*
void ajouter_etat(Liste &liste, Etat &e) {
	initialiser()
	liste.etat_courant;
} */

void detruire_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	for (unsigned int i = 0; i < liste.capacité; i++) {
		Etat *ptr_temporaire = new Etat;
		liste.etat_courant = liste.etat_courant->etat_suivant;
	}
}