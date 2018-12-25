#ifndef _LISTE_
#define _LISTE_

/**
* @file Liste.h
* @dbrief Composant de liste
*/

#include "tableau2D.h"

struct Liste {
	Tab2D& tete;
	Tab2D& courant;
	Tab2D& queue;
	unsigned int capacité;

};

#endif
