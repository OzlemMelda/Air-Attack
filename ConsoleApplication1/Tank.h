#ifndef TANK_H
#define TANK_H
#include <vector>
#include "console.h"

using namespace std;

class Fire;
class Console;

struct COORDINATE {
	int x;
	int y;

	COORDINATE() : x(0), y(0) {}
	COORDINATE(int xIn, int yIn) : x(xIn), y(yIn) {}
};

class Tank {
	int HP = 99, Ammo = 50;
	void Draw(Console& c, char ch, int color);
	Console c;
	int color;
	COORDINATE Base;

public:
	Tank(COORDINATE Base, int color,Console c);
	
	vector<Fire*> Shoot (char ch, vector<Fire*> MyFireVector);
	
	bool IsOver();
	void WriteYourStats(Console c);
	void DecreaseHP();
	void IncreaseHP();
	void IncreaseAmmo();
	void IncreaseAmmoLess();
	
	void Draw(Console& c);
	void Erase(Console& c);
	void Move(int XMax, char ch, Console& c);
	
	int getx();
	int gety();
	
};

#endif
