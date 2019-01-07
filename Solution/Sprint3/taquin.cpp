/**
 * @file taquin.cpp
 * @brief Codage des fonctions associées au type Taquin
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#include <iostream>
#include "Taquin.h"
#include "Solution.h"
#include "Liste.h"

using namespace std;

// Créer le jeu de taquin avec l'état initial
void initialiser(Taquin& t) {
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	t.nbL = nbL;
	t.nbC = nbC;
	initialiser_LEAE(t.LEAE, t.nbL, t.nbC);
	initialiser_LEE(t.LEE, t.nbL, t.nbC);
}

// Itération de l'algorithme de recherche
bool jouer(Taquin& t) {
	bool solutionTrouvee = false;
	Tab2D *solution = new Tab2D[t.nbC];
	unsigned int nb_iteration = 1;
	Position_du_trou position;
	initialiser_solution(solution, t.nbL, t.nbC);
	//afficher_solution(solution, t.nbL, t.nbC);
	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl;
	for (unsigned int i = 0; i < nb_iteration + 1; i++) {
		if (but(solution, t.LEAE.premier_element->damier_resultant)) {
			solutionTrouvee = true;
			break;
		}
		else {
			cout << "Iteration " << i << endl;
			afficher(t);
			cout << "Fin iteration " << i << endl << endl << endl;
			if (i == 0) {
				inserer_LEAE_vers_LEE(t.LEAE, t.LEE);
				supprimer_etat_courant_de_LEAE(t.LEAE);
				scan_mouvement_possible(*t.LEE.etat_courant, position);
				if (position.nord == true) {
					ajouter_etat(t, t.LEAE, *t.LEE.etat_courant, position, 0);
				}
				if (position.est == true) {
					ajouter_etat(t, t.LEAE, *t.LEE.etat_courant, position, 3);
				}
				if (position.sud == true) {
					ajouter_etat(t, t.LEAE, *t.LEE.etat_courant, position, 2);
				}
				if (position.ouest == true) {
					ajouter_etat(t, t.LEAE, *t.LEE.etat_courant, position, 1);
				}
			}
		}
	}

	//afficher_solution(solution, t.nbL, t.nbC);
	detruire_solution(solution, t.nbL, t.nbC);
	return(solutionTrouvee);
}

// Afficher le contenu des listes à dev et dev
void afficher(Taquin& t) {
	cout << "*** LEE - long : " << t.LEE.capacité << endl;
	if (t.LEE.capacité > 0)
		afficher_liste(t.LEE);
	cout << endl << "*** LEAE - long : " << t.LEAE.capacité << endl;
	if (t.LEAE.capacité > 0)
		afficher_liste(t.LEAE);
}


bool appartient(const Etat& ef, Taquin& t) {
	unsigned int compteur= t.nbC*t.nbL;
	for (unsigned int indice_cap; indice_cap < t.LEAE.capacité; indice_cap++) {
		t.LEAE.etat_courant = t.LEAE.premier_element;
		 
		for (unsigned int i = 0; i < t.nbL; i++) {
			for (unsigned int j = 0; j < t.nbC; j++) {
				if (ef.damier_resultant.tab[i][j] == t.LEAE.etat_courant->damier_resultant.tab[i][j] )
					compteur++;
			}
		}
		if (compteur == t.nbC*t.nbL)
			return(true);
		
		
	}
}

/*bool but(Tab2D* solution, Tab2D &taquin) {
	unsigned int compteur = 0;
	for (unsigned int k = 0; k < taquin.nbC; k++) {
		for (unsigned int i = 0; i < taquin.nbL; i++) {
			for (unsigned int j = 0; j < taquin.nbC; j++) {
				if (solution[k].tab[i][j] == taquin.tab[i][j])
					compteur++;
			}
		}
		if (compteur == solution->nbC*solution->nbL)
			return(true);
		else
			compteur = 0;
	}
	return(false);
}*/

void detruire_taquin(Taquin &t, unsigned int &nbL, unsigned int &nbC) {
	detruire(t.LEAE.premier_element->damier_resultant);
	detruire_liste(t.LEAE, nbL, nbC);
	detruire_liste(t.LEE, nbL, nbC);
}
