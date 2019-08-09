#include "supersonic.h"
#include "console.h"



Supersonic:: Supersonic (COORDINATEAIR BaseIn, int SpeedIn, int colorIn, int directionIn) :
	Aircraft(BaseIn, SpeedIn, colorIn, directionIn) {}

bool Supersonic::IsDead(int XMax) {
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
	void Supersonic::Draw(Console& c, char ch, int color)
	{
		for (int j = Base.x; j <= Base.x + 2; j++)
			for (int i = Base.y; i <= Base.y ; i++) {
				c.SetColor(j, i, color);
				c.PrintChar(j, i, ch);
			}
	}
	
	/*Supersonic vurulmayacak ama fire yok olsun diye koyduk bu fonksiyonu*/
	int Supersonic::IsHit(Fire* fire) {
		for (int b = Base.y; b <= Base.y ; b++) {
			for (int a = Base.x; a <= Base.x + 1; a++)
			{
				if (fire->getx() == a && fire->gety() == b)
					return 2;
			}
		}


		return 0;
	}


	vector<Bomb*> Supersonic::ReleaseBomb(vector<Bomb*> MyBombs, Console& c) {

		if (rand()%300<1) {

			MyBombs.push_back(new Bomb(COORDINATEBomb(Base.x+1, Base.y + 1), (4), c.rgb_b(1, 1, 1, 0) | c.rgb_f(1, 1, 1, 0)));

			return MyBombs;
		}
		else
			return MyBombs;

	}
	
	
	
	vector<Package*> Supersonic::ReleasePackage(vector<Package*> MyPackages, Console& c) {

			return MyPackages;

	}