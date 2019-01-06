/**
 * @file tableau2D.cpp
 * @brief Codage des fonctions associées à Tab2D
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.1 02/01/2019
 */
#include "tableau2D.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Allouer en mémoire dynamique un Tableau2D
void initialiser(Tab2D &m, unsigned int nbL, unsigned int nbC) {
	m.tab = new Item*[nbL]; // alloue la mémoire au double pointeur se déplaçant sur les différents tableaux 1D
	for (unsigned int i = 0; i < nbL; i++) {
		m.tab[i] = new Item[nbC]; //alloue la mémoire à chaque tableau 1D qui constituent le tableau 2D
	}
	m.nbL = nbL;
	m.nbC = nbC;
}

// Desallouer un Tableau2D
void detruire(Tab2D& m) {
	for (unsigned int i = 0; i < m.nbL; i++) {
		delete[] m.tab[i];
	}
	delete[] m.tab;
}
// Lire un Tableau2D
void lire(Tab2D& m) {
	char element_lu[255];
	for (unsigned int i = 0; i < m.nbL; i++) {
		for (unsigned int j = 0; j < m.nbC; j++) {
			cin >> element_lu;
			if (element_lu[0] == '#')
				m.tab[i][j] = 0;
			else
				m.tab[i][j] = atoi(element_lu);
		}
	}
}

void recopie_tableau(Tab2D &destination, Tab2D &source) {
	destination.nbC = source.nbC;
	destination.nbL = source.nbL;
	for (unsigned int i = 0; i < destination.nbL; i++) {
		for (unsigned int j = 0; j < destination.nbC; j++) {
			destination.tab[i][j] = source.tab[i][j];
		}
	}
}

// Afficher un Tableau2D
void afficher(const Tab2D& m) {
	unsigned int nb_lu;
	for (unsigned int i = 0; i < m.nbL; i++) {
		cout << "  ";
		for (unsigned int j = 0; j < m.nbC; j++) {
			nb_lu = m.tab[i][j];
			if (nb_lu == 0)
				cout << '#' << "  ";
			else
				cout << nb_lu << "  ";
		}
		cout << endl;
	}
}