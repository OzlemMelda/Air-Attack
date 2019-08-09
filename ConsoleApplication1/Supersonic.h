#ifndef SUPERSONIC_H
#define SUPERSONIC_H

#include "aircraft.h"

class Console;

class Supersonic : public Aircraft {
	
public:
	vector<Bomb*> ReleaseBomb(vector<Bomb*> a, Console& c);
	vector<Package*> ReleasePackage(vector<Package*> a, Console& c);
	Supersonic(COORDINATEAIR BaseIn, int SpeedIn, int colorIn,int directionIn);
	bool IsDead(int XMax);
	void Draw(Console& c, char ch, int color);
	int IsHit(Fire* fire);
};

#endif
