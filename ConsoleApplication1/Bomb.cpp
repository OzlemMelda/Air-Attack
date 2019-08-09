#include <math.h>
#include "bomb.h"


Bomb::Bomb(COORDINATEBomb BaseIn, int SpeedIn, int colorIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn)
{
	SpeedCounter = 0;

}

void Bomb::Erase(Console& c) {
	Draw(c, ' ', c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
}

void Bomb::Draw(Console& c) {
	Draw(c, '.', color);
}
bool Bomb::TimeIsUp(double GameSpeed)
{
	if (ceil((double)Speed) / GameSpeed <= SpeedCounter){
	SpeedCounter = 0;
	return true;
		}
		SpeedCounter++;
		return false;
}
void Bomb::Move(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

	Erase(c);
	Base.y++;
	Draw(c);
}

void Bomb::Draw(Console& c, char ch, int color) 
{
	c.SetColor(Base.x, Base.y, color);
	c.PrintChar(Base.x, Base.y, ch);

}

bool Bomb::IsOut(int HMax) {
	if (Base.y == HMax)
		return true;
	else
		return false;
}

bool Bomb::IsHit(Fire* fire) {
	
	if (fire->getx() == Base.x && (fire->gety() == Base.y||fire->gety() == Base.y+1)) 
		return true;
	
	else
		return false;
				
}

