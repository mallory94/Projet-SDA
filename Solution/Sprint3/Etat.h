/**
 * @file Etat.h
 * @brief Structuration des types Etat (du damier) et Poisition_du_trou et type �num�r� Mouvement
 * @author Mallory GACK 101 Nicolas ORVAIN 101
 * @version 1.0 02/01/2019
 */
#ifndef _ETAT_
#define _ETAT_

#include "tableau2D.h"

enum Mouvement { NORD, EST, SUD, OUEST };

struct Position_du_trou {
	unsigned int ligne, colonne, nb_mouv_possible = 0;
	bool nord = false, ouest = false, sud = false, est = false;
};

struct Etat {
	Etat *etat_precedent;
	Tab2D damier_resultant;
	Mouvement mouvement;
	Tab2D damier_pr�c�dent;
	Etat *etat_suivant;
	unsigned int g = 0;
	unsigned int h = 0;
};

// Afficher un �tat du taquin
void afficher_etat(const Etat& e);

void initialiser_etat(Etat &e, unsigned int &nbL, unsigned int &nbC);

void scan_mouvement_possible(Etat &e, Position_du_trou &position);

#endif