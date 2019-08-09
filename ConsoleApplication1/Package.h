#ifndef PACKAGE_H
#define PACKAGE_H
#include "Tank.h"
#include <vector>
#include "fire.h"
#include "console.h"

using namespace std;

struct COORDINATEP {
public:
	int x;
	int y;

	COORDINATEP() : x(0), y(0) {}
	COORDINATEP(int xIn, int yIn) : x(xIn), y(yIn) {}
};

class Package {

	int Speed;
	int SpeedCounter;
	int color;

protected:
	COORDINATEP Base;
	

	void Draw(Console& c, char ch, int color) ;
	bool TimeIsUp(double GameSpeed);


public:
	Package(COORDINATEP BaseIn, int SpeedIn, int colorIn);

	void Erase(Console& c);
	void Draw(Console& c);
	bool IsOut(int BottomL);
	int IsHit(Fire* b);
	virtual bool IsTaken(Tank* a)=0;
	void Move(double GameSpeed, Console& c);


};

#endif
