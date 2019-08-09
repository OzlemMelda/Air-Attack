#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <vector>
#include "bomb.h"
#include "Fire.h"
#include "Package.h"
#include"AmmunationBonus.h"
#include"LifeBonus.h"

using namespace std;

class Console;
class Fire;
class Bomb;
class Package;
class COORDINATEAIR {
public:
	int x;
	int y;

	COORDINATEAIR(): x(0), y(0) {}
	COORDINATEAIR(int xIn, int yIn) : x(xIn), y(yIn) {}
};

class Aircraft {
	
	int Speed;
	int SpeedCounter;
	int color;

protected:
	COORDINATEAIR Base;
	int direction;

	virtual void Draw(Console& c, char ch, int color) = 0;
	bool TimeIsUp(double GameSpeed);


public:
	Aircraft(COORDINATEAIR BaseIn, int SpeedIn, int colorIn,int direction);
	
	void Erase(Console& c);
	void Draw(Console& c);
	void Move(double GameSpeed, Console& c);

	virtual vector<Bomb*> ReleaseBomb(vector<Bomb*> a,  Console& c) = 0;
	virtual vector<Package*> ReleasePackage(vector<Package*> a, Console& c) = 0;
	virtual bool IsDead(int Xmax) = 0;
	virtual int IsHit(Fire* fire) = 0;
	
	

};

#endif