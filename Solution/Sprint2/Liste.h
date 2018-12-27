#ifndef _LISTE_
#define _LISTE_

/**
* @file Liste.h
* @dbrief Composant de liste
*/

#include "Etat.h"
#include "tableau2D.h"

struct Liste {
	Tab2D taquin;
	Etat *premier_element;
	unsigned int capacité;
};

#endif
