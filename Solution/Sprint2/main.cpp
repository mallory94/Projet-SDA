#include <iostream>
#include "tableau2D.h"

using namespace std;

int main() {
	Tab2D taquin;
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	initialiser(taquin, nbL, nbC);
	lire(taquin);
	afficher(taquin);
	detruire(taquin);
	system("pause");
	return(0);
}

