#ifndef _LISTE_
#define _LISTE_

/**
* @file Liste.h
* @dbrief Composant de liste
*/

#include "tableau2D.h"

struct Liste {
	Tab2D taquin;

	Liste& element_suivant;
	unsigned int capacité;
};

#endif
