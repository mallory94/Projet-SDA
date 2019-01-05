
#include "Liste.h"
#include <cstdio>
#include "Etat.h"
#include <algorithm>
#include <iostream>
#include "tableau2D.h"

using namespace std;

void initialiser_LEAE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacit� = 1;
	liste.etat_courant = new Etat;
	liste.dernier_element = liste.etat_courant;
	liste.premier_element = liste.etat_courant;
	initialiser(liste.premier_element->damier_resultant, nbL, nbC);
	initialiser(liste.premier_element->damier_pr�c�dent, nbL, nbC);
	liste.premier_element->etat_suivant;
	lire(liste.premier_element->damier_resultant);
}

void initialiser_LEE(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	liste.capacit� = 0;
	liste.etat_courant = new Etat;
	initialiser(liste.etat_courant->damier_resultant, nbL, nbC);
	initialiser(liste.etat_courant->damier_pr�c�dent, nbL, nbC);
	liste.premier_element = liste.etat_courant;
	liste.dernier_element = liste.etat_courant;
}


void inserer_LEAE_vers_LEE(Liste &LEAE, Liste &LEE) {
	LEE.capacit�++;
	swap(LEE.etat_courant, LEAE.etat_courant);
	swap(LEE.dernier_element, LEAE.dernier_element);
	swap(LEE.premier_element, LEAE.premier_element);
}

//pas besoin de delete les etats car on a swap� LEE.etat_courant (vide) avec 
void supprimer_etat_courant_de_LEAE(Liste &LEAE) {
	LEAE.capacit�--;
	delete LEAE.etat_courant;
}

void supprimer_etat_courant(Liste &liste) {
	if (liste.premier_element == liste.etat_courant && (liste.etat_courant->etat_suivant != NULL)) {
		liste.premier_element = liste.etat_courant->etat_suivant;
	}
	else if (liste.dernier_element == liste.etat_courant && (liste.etat_courant != liste.premier_element)) {
		liste.dernier_element = liste.etat_courant->etat_precedent;
	}
	liste.capacit�--;

	detruire(liste.etat_courant->damier_resultant);
	detruire(liste.etat_courant->damier_pr�c�dent);
}

/*ajoute a la liste (LEAE) des etats en fonctions des mouvements possibles
* et de l'�tat de d�part
* Etat e �tant l'�tat pr�c�dent
*
*
*/
void ajouter_etat(Liste &liste, Etat &e, Position_du_trou &position,
	unsigned int mouvement) {
	unsigned int tmp;
	liste.capacit�++;
	liste.dernier_element = new Etat;
	liste.dernier_element->etat_precedent = liste.etat_courant;
	liste.etat_courant->etat_suivant = liste.dernier_element;
	liste.etat_courant = liste.dernier_element;
	if (liste.capacit� == 1) {
		liste.premier_element = liste.etat_courant;
	}
	initialiser_etat(*liste.dernier_element, e.damier_resultant.nbL,
		e.damier_resultant.nbC);
	recopie_tableau(liste.dernier_element->damier_resultant, e.damier_resultant);
	liste.dernier_element->damier_pr�c�dent = e.damier_resultant;
	switch (mouvement)
	{
	case 0: //nord
		swap
		(liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne],
			liste.dernier_element->damier_resultant.
			tab[position.ligne - 1][position.colonne]);
		liste.dernier_element->mouvement = NORD;
		break;
	case 1: //ouest
		swap
		(liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne],
			liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne-1]);
		liste.dernier_element->mouvement = OUEST;
		break;
	case 2: //sud
		swap(liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne],
			liste.dernier_element->damier_resultant.
			tab[position.ligne+1][position.colonne]);
		liste.dernier_element->mouvement = SUD;
		break;
	case 3: //est
		swap
		(liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne],
			liste.dernier_element->damier_resultant.
			tab[position.ligne][position.colonne+1]);
		liste.dernier_element->mouvement = EST;
		break;
	default:
		break;
	}
	liste.dernier_element = liste.dernier_element->etat_suivant;
}

void detruire_liste(Liste &liste, unsigned int &nbL, unsigned int &nbC) {
	for (unsigned int i = 0; i < liste.capacit�; i++) {
		supprimer_etat_courant(liste);
	}
}

void afficher_liste(Liste &liste) {
	unsigned int i;
	liste.etat_courant = liste.premier_element;
	for (i = 0; i < liste.capacit�; i++) {
		if (liste.etat_courant->mouvement >= 0 && liste.etat_courant->mouvement <= 3) {
			switch (liste.etat_courant->mouvement) {
			case 0:
				cout << "NORD" << endl;
				break;
			case 1:
				cout << "EST" << endl;
				break;
			case 2:
				cout << "SUD" << endl;
				break;
			case 3:
				cout << "OUEST" << endl;
				break;
			default:
				break;
			}
		}
		afficher(liste.etat_courant->damier_resultant);
		if (liste.capacit� > 1) {
			liste.etat_courant = liste.etat_courant->etat_suivant;
		}
	}
	if (i < 0)
		liste.etat_courant = NULL;
}