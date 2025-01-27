/**
* \ file polygone.cpp
* \ author Aida Ouangraoua
* \ brief Ce fichier contient l'implementation
* des operations du type Polygone
*/

#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
	nb_sommets = 4;
	sommets[0] = p1;
	sommets[1] = p2;
	sommets[2] = p3;
	sommets[3] = p4;
}

float Rectangle::calculerAire(void) {
	float hauteur = 0.0;
	float largeur = 0.0;
	float aire = 0.0;

	hauteur = sommets[0].calculerDistance(sommets[1]);
	largeur = sommets[1].calculerDistance(sommets[2]);

	aire = hauteur * largeur;

	return aire;
}