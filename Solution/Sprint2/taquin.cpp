/**
*
*
*/

#include <iostream>
#include "Taquin.h"
#include "Solution.h"
#include "Liste.h"

using namespace std;

// Cr�er le jeu de taquin avec l'�tat initial
void initialiser(Taquin& t) {
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	t.nbL = nbL;
	t.nbC = nbC;
	initialiser_LEAE(t.LEAE, nbL, nbC);
}

// It�ration de l'algorithme de recherche
void jouer(Taquin& t) {
	bool solutionTrouvee = false;
	Tab2D *solution = new Tab2D[t.nbC];
	initialiser_solution(solution, t.nbL, t.nbC);
	if (etre_solution(solution, t.LEAE.premier_element->damier_resultant)) {
		solutionTrouvee = true;
	}
	afficher_solution(solution, t.nbL, t.nbC);
	detruire_solution(solution, t.nbL, t.nbC);
}

// Afficher le contenu des listes � dev et dev
void afficher(Taquin& t) {
	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl
		<< "Iteration 0" << endl << "*** LEE - long : 0" << endl << endl;
	afficher(t.LEAE.premier_element->damier_resultant);


}

/*
void detruire_taquin(Taquin& t) {
	for (unsigned int i = 0; i < t.LEAE.capacit�; i++) {
		detruire(t.LEAE)
	}
} */

