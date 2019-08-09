#include "fire.h"
#include <math.h>

Fire::Fire(COORDINATEF BaseIn, int SpeedIn, int colorIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn)
{
	SpeedCounter = 0;

}



void Fire::Erase(Console& c) {
	Draw(c, ' ', c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
}

void Fire::Draw(Console& c) {
	Draw(c, '.', color);
}
bool Fire::TimeIsUp(double GameSpeed)
{
	if (ceil((double)Speed) / GameSpeed <= SpeedCounter){
	SpeedCounter = 0;
	return true;
		}
		SpeedCounter++;
		return false;
}
void Fire::Move(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

		Erase(c);
		Base.y--;
		Draw(c);
}

void Fire::Draw(Console& c, char ch, int color)
{
	c.SetColor(Base.x, Base.y, color);
	c.PrintChar(Base.x, Base.y, ch);

}

bool Fire::IsOut(int HMax) {
	if (Base.y == HMax)
		return true;
	else
		return false;
}

int Fire::getx() {
	return Base.x;
}
int Fire::gety() {
	return Base.y;
}