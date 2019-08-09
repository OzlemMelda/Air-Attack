#ifndef BOMB_H
#define BOMB_H
#include "Fire.h"
#include "console.h"



struct COORDINATEBomb {
	int x;
	int y;

	COORDINATEBomb() : x(0), y(0) {}
	COORDINATEBomb(int xIn, int yIn) : x(xIn), y(yIn) {}
};

class Bomb {
	int Speed;
	int SpeedCounter;
	int color;
	void Draw(Console& c, char ch, int color);
	
	COORDINATEBomb Base;

	bool TimeIsUp(double GameSpeed);
	
	public:
		Bomb(COORDINATEBomb BaseIn, int SpeedIn, int colorIn);
		void Move(double GameSpeed, Console& c);
		
		void Draw(Console& c);
		void Erase(Console& c);

		bool IsOut(int BottomL);
		bool IsHit(Fire* a);
		

		
};

#endif 
