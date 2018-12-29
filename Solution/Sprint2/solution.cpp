
#include "Solution.h"
#include "tableau2D.h"
#include "Item.h"
#include <iostream>
#include "Etat.h"
#include <assert.h>

using namespace std;

void initialiser_solution(Tab2D* solution, unsigned int nbL, unsigned int nbC) {
	unsigned int compteur; // permet d'initialiser les différentes cases du tableau
	for (unsigned int k = 0; k < nbC; k++) {
		solution[k].tab = new Item*[nbL]; // alloue la mémoire au double pointeur se déplaçant sur les différents tableaux 1D
		for (unsigned int i = 0; i < nbL; i++) {
			solution[k].tab[i] = new Item[nbC]; //alloue la mémoire à chaque tableau 1D qui constituent le tableau 2D
		}
		solution[k].nbL = nbL;
		solution[k].nbC = nbC;
		compteur = 1;
		for (unsigned int i = 0; i < solution[k].nbL; i++) {
			for (unsigned int c = 0, j = (0 + k) % nbC; c < solution[k].nbC; c++) {
				if (compteur != nbL * nbC) {
					solution[k].tab[i][j] = compteur;
				}
				else
					solution[k].tab[i][j] = 0;
				compteur++;
				j = ((++j) % nbC);
			}
		}
		solution[k].nbL = nbL;
		solution[k].nbC = nbC;
	}
}

void detruire_solution(Tab2D *solution, unsigned int nbL, unsigned int nbC) {
	for (unsigned int k = 0; k < nbC; k++) {
		for (unsigned int i = 0; i < nbL; i++) {
			delete[] solution[k].tab[i];
		}
		delete[] solution[k].tab;
	}
}

void afficher_solution(Tab2D *solution, unsigned int nbL, unsigned int nbC) {
	for (unsigned int k = 0; k < nbC; k++) {
		unsigned int nb_lu;
		for (unsigned int i = 0; i < solution[k].nbL; i++) {
			cout << "  ";
			for (unsigned int j = 0; j < solution[k].nbC; j++) {
				nb_lu = solution[k].tab[i][j];
				if (nb_lu == 0)
					cout << '#' << " ";
				else
					cout << nb_lu << " ";
			}
			cout << endl;
		}
	}
}

bool etre_solution(Tab2D* solution, Tab2D &taquin) {
	for (unsigned int k = 0; k < taquin.nbC; k++) {
		for (unsigned int i = 0; i < taquin.nbL; i++) {
			for (unsigned int j = 0; j < taquin.nbC; j++) {
				if (solution[k].tab[i][j] != taquin.tab[i][j])
					return (false);
			}
		}
	}
	return(true);
}