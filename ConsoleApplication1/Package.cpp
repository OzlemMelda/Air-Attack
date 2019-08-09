#include "Package.h"


Package::Package(COORDINATEP BaseIn, int SpeedIn, int colorIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn)
{
	SpeedCounter = 0;

}

void Package::Erase(Console& c) {
	Draw(c, ' ', c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
}

void Package::Draw(Console& c, char ch, int color)
{
	c.SetColor(Base.x, Base.y, color);
	c.PrintChar(Base.x, Base.y, ch);

}

void Package::Draw(Console& c) {
	Draw(c, '.', color);
}
bool Package::TimeIsUp(double GameSpeed)
{
	if (ceil((double)Speed) / GameSpeed <= SpeedCounter) {
		SpeedCounter = 0;
		return true;
	}
	SpeedCounter++;
	return false;
}
void Package::Move(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

	Erase(c);
	Base.y++;
	Draw(c);
}
bool Package::IsOut(int YMax) {
	if (Base.y == YMax)
		return true;
	else
		return false;
}

int Package::IsHit(Fire* fire) {

	if (fire->getx() == Base.x && (fire->gety() == Base.y || fire->gety() == Base.y + 1))
		return 1;
	else
		return 0;
}




