/**
*
*
*/

#include <iostream>
#include "Taquin.h"

using namespace std;

// Cr�er le jeu de taquin avec l'�tat initial
void initialiser(Taquin& t) {
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	t.nbL = nbL;
	t.nbC = nbC;
	initialiser(t.LEAE.taquin, nbL, nbC);
	lire(t.LEAE.taquin);
}

// It�ration de l'algorithme de recherche
void jouer(Taquin& t) {
	bool solutionTrouvee = false;
	
	Tab2D* solutions;
	initialiser_sol(solutions);
	/*  ALGORITHME A*
	while (t.LEAE.capacit� > 0) {

		if ()
		{
			
		}
	} */

}

// Afficher le contenu des listes � dev et dev
void afficher(Taquin& t) {
	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl
		<< "Iteration 0" << endl << "*** LEE - long : 0" << endl << endl;
	afficher(t.LEAE.taquin);
	detruire(t.LEAE.taquin);
}

bool etat_courant_est_final(Taquin& t, ) {
	for () {
		e.damier_resultant ==
	}
}