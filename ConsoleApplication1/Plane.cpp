#include "plane.h"
#include "console.h"



Plane::Plane(COORDINATEAIR BaseIn, int SpeedIn, int colorIn,int directionIn) :
	Aircraft(BaseIn, SpeedIn, colorIn, directionIn ) {}



bool Plane::IsDead(int XMax) {
	if (direction == 0 && Base.x == (XMax)) {
		return true;
	}
	if (direction == 1 && Base.x == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Plane::Draw(Console& c, char ch, int color)
{
	for (int j = Base.x; j <= Base.x + 4; j++)
		for (int i = Base.y; i <= Base.y ; i++) {
			c.SetColor(j, i, color);
			c.PrintChar(j, i, ch);
		}
}

int Plane::IsHit(Fire* fire) {
	for (int b = Base.y; b <= Base.y ; b++) {
		for (int a = Base.x; a <= Base.x + 3; a++)
		{
			if (fire->getx() == a && fire->gety() == b)
				return 1;
		}
	}


	return 0;
}

vector<Bomb*> Plane::ReleaseBomb(vector<Bomb*> MyBombs, Console& c) {

	if (rand()%300<2) {

		MyBombs.push_back(new Bomb(COORDINATEBomb(Base.x+1, Base.y + 1), (4), c.rgb_b(1, 1, 1, 0) | c.rgb_f(1, 1, 1, 0)));

		return MyBombs;
	}
	else
		return MyBombs;

}

vector<Package*> Plane::ReleasePackage(vector<Package*> MyPackages, Console& c) {

	if (rand() % 2 <1) {
		int a = rand() % 2;
		if (a < 1) {
			MyPackages.push_back(new AmmunationBonus(COORDINATEP(Base.x + 1, Base.y + 1), (4), c.rgb_b(1, 0, 1, 0) | c.rgb_f(0, 1, 1, 0)));
		}
		else {
			MyPackages.push_back(new LifeBonus(COORDINATEP(Base.x + 1, Base.y + 1), (4), c.rgb_b(1, 0, 0, 0) | c.rgb_f(0, 1, 0, 0)));
		}
		return MyPackages;
	}
	else
		return MyPackages;

}


