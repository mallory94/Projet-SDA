/**
*
*
*/


#include <iostream>
#include "tableau2D.h"
#include "Taquin.h"
#include "Solution.h"

int main() {
	Taquin t;
	initialiser(t);
	afficher(t);
	jouer(t);
	system("pause");
	return(0);
}