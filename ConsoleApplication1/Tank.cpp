#include <math.h>
#include "console.h"
#include "tank.h"
#include "fire.h"
#include <vector>

using namespace std;


Tank::Tank(COORDINATE BaseIn, int colorIn,Console cIn) : Base(BaseIn) ,color (colorIn), c(cIn) {}

void Tank::Erase(Console& c) {
	Draw(c, ' ', c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
}

void Tank::Draw(Console& c) {
	Draw(c, '.', color);

}

void Tank::Draw(Console& c, char ch, int color)
{
	for (int i = Base.x; i <= Base.x + 2; i++) {
		for (int j = Base.y; j <= Base.y + 1; j++) {
			c.SetColor(i, j, color);
			c.PrintChar(i, j, ch);
	}
}
	}


// To write HP And Bullet Number on the Console
void Tank::WriteYourStats(Console c){

	c.PrintChar(77, 23, 'H');
	c.PrintChar(78, 23, 'P');
	char ch = HP/10 + '0';
	c.PrintChar(79, 23, ch);

	c.PrintChar(77, 24, 'B');
	c.PrintChar(78, 24, 'N');
	char k = Ammo / 10 + '0';
	c.PrintChar(79, 24, k);
}

void Tank::Move(int XMax, char ch, Console& c) {
	if (ch == 'a' && Base.x > 0) {
		Erase(c);
		Base.x--;
		Draw(c);
	}
	else if (ch == 'd' && Base.x < XMax - 2) {
		Erase(c);
		Base.x++;
		Draw(c);
	}
}

//Creating Fire when user presses 'f'
vector<Fire*> Tank::Shoot (char ch , vector<Fire*> MyFireVector) {
	if (ch == 'f' && Ammo != 0) {

		MyFireVector.push_back(new Fire(COORDINATEF(Base.x + 1, Base.y), (1), c.rgb_b(0, 0, 1, 1) | c.rgb_f(0, 0, 1, 1)));
		Ammo--;
		return MyFireVector;

	}
	else
		return MyFireVector;
}


//Decrease in HP due to Bombs
void Tank::DecreaseHP() {
	HP--;
}


//Increase in HP due to Life Bonus
void Tank::IncreaseHP() {
	if(HP<70)
	HP=HP+30;
	if (HP >= 70)
		HP = 99;

}


//Increase in Ammunation due to Ammunation Bonus
void Tank::IncreaseAmmo() {
	if (Ammo<80)
	Ammo=Ammo+20;
	if (Ammo >= 80)
		Ammo = 99;
}


//Increase in Ammunation due to destroying an aircraft
void Tank::IncreaseAmmoLess() {
	if (Ammo<95)
		Ammo = Ammo + 5;
	if (Ammo >= 95)
		Ammo = 99;
}


// Function to Check HP and Ammunation conditions
bool Tank::IsOver() {
	if (Ammo == 0 || HP == 0)
		return true;
	else
		return false;
}

int Tank::getx() {
	return Base.x;
}
int Tank::gety() {
	return Base.y;
}
