/**
*
*
*/

#include <iostream>
#include "Taquin.h"

using namespace std;

// Créer le jeu de taquin avec l'état initial
void initialiser(Taquin& t) {
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	t.nbL = nbL;
	t.nbC = nbC;
	initialiser(t.LEAE.taquin, nbL, nbC);
	lire(t.LEAE.taquin);
}

// Itération de l'algorithme de recherche
void jouer(Taquin& t) {
	bool solutionTrouvee = false;

	while (t.LEAE.capacité > 0) {
		unsigned
			for () {

			}
		if ()
		{

		}
	}

}

// Afficher le contenu des listes à dev et dev
void afficher(Taquin& t) {
	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl
		<< "Iteration 0" << endl << "*** LEE - long : 0" << endl << endl;
	afficher(t.LEAE.taquin);
	detruire(t.LEAE.taquin);
}