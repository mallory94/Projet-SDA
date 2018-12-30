/**
*
*
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
void jouer(Taquin& t) {
	bool solutionTrouvee = false;
	Tab2D *solution = new Tab2D[t.nbC];
	initialiser_solution(solution, t.nbL, t.nbC);
	afficher_solution(solution, t.nbL, t.nbC);
	if (etre_solution(solution, t.LEAE.premier_element->damier_resultant)) {
		solutionTrouvee = true;
		cout << "le taquin est resolu" << endl; //A RETIRER
	}
	else
		cout << "le taquin n'est pas resolu" << endl;
	//afficher_solution(solution, t.nbL, t.nbC);
	detruire(t.LEAE.premier_element->damier_resultant);
	detruire_solution(solution, t.nbL, t.nbC);
	//if (solutionTrouvee = true ) POUR 
}

// Afficher le contenu des listes à dev et dev
void afficher(Taquin& t) {
	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl
		<< "Iteration 0" << endl << "*** LEE - long : 0" << endl << endl;
	afficher(t.LEAE.premier_element->damier_resultant);


}

/*
void detruire_taquin(Taquin& t) {
	for (unsigned int i = 0; i < t.LEAE.capacité; i++) {
		detruire(t.LEAE)
	}
} */

