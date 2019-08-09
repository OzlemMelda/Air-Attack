#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "aircraft.h"

class Console;

class Helicopter : public Aircraft {
	int Armor = 3;

public:
	Helicopter(COORDINATEAIR BaseIn, int SpeedIn, int colorIn, int directionIn);
	bool IsDead(int XMax);
	void Draw(Console& c, char ch, int color);
	int IsHit(Fire* fire);
	vector<Bomb*> ReleaseBomb(vector<Bomb*> a, Console& c);
	vector<Package*> ReleasePackage(vector<Package*> a, Console& c);
};

#endif
