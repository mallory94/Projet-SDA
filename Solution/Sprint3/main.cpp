/**
 * @file main.cpp
 * @brief Fichier main du projet
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */

#include <iostream>
#include "tableau2D.h"
#include "Taquin.h"
#include "Solution.h"

int main() {
	Taquin t;
	initialiser(t);
	jouer(t);
	system("pause");
	return(0);
}