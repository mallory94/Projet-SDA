/**
 * @file main.cpp
 * @brief Fichier main du projet
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 26/12/2018
 */
#include <iostream>
#include "tableau2D.h"

using namespace std;

int main() {
	Tab2D taquin;
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;
	initialiser(taquin,nbL,nbC);
	lire(taquin);
	afficher(taquin);
	detruire(taquin);
	system("pause");
	return(0);
}

