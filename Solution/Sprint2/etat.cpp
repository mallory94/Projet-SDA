
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

}

