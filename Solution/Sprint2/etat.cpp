
#include "Etat.h"
#include <iostream>

using namespace std;

// Afficher un �tat du taquin
void afficher(const Etat& e) {
	if (e.mouvement >= 0 && e.mouvement <= 3)
		cout << e.mouvement;
	afficher(e.damier_resultant);
}
