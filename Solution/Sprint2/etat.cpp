/**
 * @file etat.cpp
 * @brief Codage des fonctions associées au type Etat
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#include "Etat.h"
#include <iostream>

using namespace std;

// Afficher un état du taquin

void afficher(const Etat& e) {
	if (e.mouvement >= 0 && e.mouvement <= 3)
		cout << e.mouvement;
	afficher(e.damier_resultant);
	unsigned int nb_lu;
	for (unsigned int i = 0; i < e.damier_resultant.nbL; i++) {
		cout << "  ";
		for (unsigned int j = 0; j < e.damier_resultant.nbC; j++) {
			nb_lu = e.damier_resultant.tab[i][j];
			if (nb_lu == 0)
				cout << '#' << " ";
			else
				cout << nb_lu << " ";
		}
		cout << endl;
	}
}


void initialiser_etat(Etat &e, unsigned int &nbL, unsigned int &nbC) {
	initialiser(e.damier_précédent, nbL, nbC);
	initialiser(e.damier_resultant, nbL, nbC);
	e.etat_suivant = NULL;
	e.etat_precedent = NULL;
}

void scan_mouvement_possible(Etat &e, Position_du_trou &position) {
	for (unsigned int i = 0; i < e.damier_resultant.nbL; i++) {
		for (unsigned int j = 0; j < e.damier_resultant.nbC; j++) {
			if (e.damier_resultant.tab[i][j] == 0) {
				position.ligne = i;
				position.colonne = j;
				if (i != 0) {
					position.nord = true;
					position.nb_mouv_possible++;
				}
				if (i != e.damier_resultant.nbL - 1) {
					position.sud = true;
					position.nb_mouv_possible++;
				}
				if (j != 0) {
					position.ouest = true;
					position.nb_mouv_possible++;
				}
				if (j != e.damier_resultant.nbC - 1) {
					position.est = true;
					position.nb_mouv_possible++;
				}
			}
		}
	}
}

//void detruire_etat(Etat &e, unsigned);