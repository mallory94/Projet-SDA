/**
 * @file liste.cpp
 * @brief Codage des fonctions associées au TAD Liste
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#include "Liste.h"
#include <cstdio>
#include "Etat.h"
#include <algorithm>
#include <iostream>
#include "tableau2D.h"

using namespace std;

void initialiser_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacité = 1;
	liste.etat_courant = new Etat;
	liste.dernier_element = liste.etat_courant;
	liste.premier_element = liste.etat_courant;
	initialiser(liste.premier_element->damier_resultant, nbL, nbC);
	initialiser(liste.premier_element->damier_précédent, nbL, nbC);
	liste.premier_element->etat_suivant;
	lire(liste.premier_element->damier_resultant);
}

void initialiser_LEE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacité = 0;
	liste.etat_courant = new Etat;
	initialiser(liste.etat_courant->damier_resultant, nbL, nbC);
	initialiser(liste.etat_courant->damier_précédent, nbL, nbC);
	liste.premier_element = liste.etat_courant;
	liste.dernier_element = liste.etat_courant;
}


void inserer_LEAE_vers_LEE(Liste &LEAE, Liste &LEE) {
	LEE.capacité++;
	swap(LEE.etat_courant, LEAE.etat_courant);
	swap(LEE.dernier_element, LEAE.dernier_element);
	swap(LEE.premier_element, LEAE.premier_element);
}

//pas besoin de delete les etats car on a swapé LEE.etat_courant (vide) avec 
void supprimer_etat_courant_de_LEAE(Liste &LEAE) {
	LEAE.capacité--;
	delete LEAE.etat_courant;
}

void supprimer_etat_courant(Liste &liste) {
	if (liste.premier_element == liste.etat_courant && (liste.etat_courant->etat_suivant != NULL)) {
		liste.premier_element = liste.etat_courant->etat_suivant;
	}
	else if (liste.dernier_element == liste.etat_courant && (liste.etat_courant != liste.premier_element)) {
		liste.dernier_element = liste.etat_courant->etat_precedent;
	}
	liste.capacité--;

	detruire(liste.etat_courant->damier_resultant);
	detruire(liste.etat_courant->damier_précédent);
}



void detruire_liste(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	for (unsigned int i = 0; i < liste.capacité; i++) {
		supprimer_etat_courant(liste);
	}
}

void afficher_liste(Liste &liste) {
	unsigned int i;
	liste.etat_courant = liste.premier_element;
	for (i = 0; i < liste.capacité; i++) {
		afficher_etat(*liste.etat_courant);
		if (liste.capacité > 1) {
			liste.etat_courant = liste.etat_courant->etat_suivant;
		}
	}
}
