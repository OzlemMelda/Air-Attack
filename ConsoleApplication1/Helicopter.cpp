#include "Helicopter.h"
#include "console.h"



using namespace std;

Helicopter::Helicopter(COORDINATEAIR BaseIn, int SpeedIn, int colorIn,int directionIn) :
	Aircraft(BaseIn, SpeedIn, colorIn, directionIn) {}

bool Helicopter::IsDead(int XMax) {
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
	void Helicopter::Draw (Console& c, char ch, int color)
{
	for (int j = Base.x; j <= Base.x + 2; j++)
		for (int i = Base.y; i <= Base.y + 1; i++) {
			c.SetColor(j, i, color);
			c.PrintChar(j, i, ch);
		}
}
int Helicopter::IsHit(Fire* fire) {
	
		for (int b = Base.y; b <= Base.y+1 ; b++) {
			for (int a = Base.x; a <= Base.x + 2; a++)
			{	
				if (fire->getx() == a && fire->gety() == b) {
					Armor--;

					if (Armor < 1)
					{
						return 1;
					}
					else 
					{
						return 2;
					}

				}
			}
		}

		return 0;
	}// Armor ý yeni bi sayýya eþitlesek de olmuyo. Her seferinde fonksiyona yeni girmiþ gibi oluyo. sanýrým fonksiyon deðiþçek. 

vector<Bomb*> Helicopter::ReleaseBomb (vector<Bomb*> MyBombs,  Console& c) {

	if (rand()%300<3) {

			MyBombs.push_back(new Bomb(COORDINATEBomb(Base.x+1, Base.y + 1), (4), c.rgb_b(1, 1, 1, 0) | c.rgb_f(1, 1, 1, 0)));

		return MyBombs;
	}
	else
		return MyBombs;

}
vector<Package*> Helicopter::ReleasePackage(vector<Package*> MyPackages, Console& c) {

	if (rand() % 2<1) {
		int a = rand() % 2;
		if (a < 1) {
			MyPackages.push_back(new AmmunationBonus(COORDINATEP(Base.x + 1, Base.y + 1), (4), c.rgb_b(1, 0, 1, 0) | c.rgb_f(0, 1, 1, 0)));
		}
		else
		{
			MyPackages.push_back(new LifeBonus(COORDINATEP(Base.x + 1, Base.y + 1), (4), c.rgb_b(1, 0, 0, 0) | c.rgb_f(0, 1, 0, 0)));
		}

		return MyPackages;
	}

	else
		return MyPackages;

}