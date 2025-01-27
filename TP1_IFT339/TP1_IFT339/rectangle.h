#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygone.h"

class Rectangle : public Polygone {

public:
	// constructeurs
	Rectangle(Point, Point, Point, Point);

	// calcul de l'aire
	float calculerAire();

protected:

};



#endif