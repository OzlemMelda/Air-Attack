#ifndef FIRE_H
#define FIRE_H
#include "console.h"

struct COORDINATEF {
	int x;
	int y;
	COORDINATEF(int xIn, int yIn) : x(xIn), y(yIn) {}
	COORDINATEF() : x(0), y(0) {}
	
};

class Fire {
	int Speed;
	int SpeedCounter;
	int color;

	COORDINATEF Base;
	
	bool TimeIsUp(double GameSpeed);
	void Draw(Console& c, char ch, int color);


	public:
		Fire(COORDINATEF BaseIn, int SpeedIn, int colorIn);
		void Draw(Console& c);
		void Erase(Console& c);
		void Move(double GameSpeed, Console& c);
		int getx();
		int gety();
		bool IsOut(int HMax);
};


















#endif
