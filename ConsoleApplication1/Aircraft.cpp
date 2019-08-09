
#include "console.h"
#include "aircraft.h"


Aircraft::Aircraft(COORDINATEAIR BaseIn, int SpeedIn, int colorIn, int directionIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn), direction(directionIn)
{
	SpeedCounter = 0;

}

void Aircraft::Erase(Console& c) {
	Draw(c, ' ', c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
}

void Aircraft::Draw(Console& c) {
	Draw(c, '.', color);
}
bool Aircraft::TimeIsUp(double GameSpeed)
{
	if (ceil((double)Speed) / GameSpeed <= SpeedCounter){
		SpeedCounter = 0;
	return true;
		}
		SpeedCounter++;
		return false;
}

void Aircraft::Move(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

	if (direction == 0) /*move right*/ {
		Erase(c);
		Base.x++;
		Draw(c);
	}

	if (direction == 1)/*move left*/ {
		Erase(c);
		Base.x--;
		Draw(c);
	}
}


