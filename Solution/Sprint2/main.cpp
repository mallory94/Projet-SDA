/**
*
*
*/


#include <iostream>
#include "tableau2D.h"
#include "Taquin.h"

using namespace std;

int main() {
	Tab2D taquin;
	Taquin t;
	initialiser(t);
	lire(taquin);
	afficher(taquin);
	detruire(taquin);
	system("pause");
	return(0);
}