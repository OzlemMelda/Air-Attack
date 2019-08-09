#include "LifeBonus.h"


LifeBonus::LifeBonus(COORDINATEP BaseIn, int SpeedIn, int colorIn) :
	Package(BaseIn, SpeedIn, colorIn) {}

bool LifeBonus::IsTaken(Tank * a)
{
	int x = a->getx();
	int y = a->gety();

	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 1; j++) {
			if (i == Base.x&&j == Base.y) {
				a->IncreaseHP();
				return true;
			}
		}
	}
	
	return false;
}










