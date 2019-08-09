#ifndef PLANE_H
#define PLANE_H

#include "aircraft.h"

class Console;

class Plane : public Aircraft {

public:
	vector<Bomb*> ReleaseBomb(vector<Bomb*> a, Console& c);
	vector<Package*> ReleasePackage(vector<Package*> a, Console& c);
	Plane (COORDINATEAIR BaseIn, int SpeedIn, int colorIn, int directionIn);
	bool IsDead(int XMax);
	void Draw(Console& c, char ch, int color);
	int IsHit(Fire* fire);
};

#endif