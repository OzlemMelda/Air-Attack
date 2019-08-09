#ifndef LIFEBONUS_H
#define LIFEBONUS_H

#include "package.h"

using namespace std;

class LifeBonus : public Package {
	

public:
	LifeBonus(COORDINATEP BaseIn, int SpeedIn, int colorIn);
	bool IsTaken(Tank* a);
	
};

#endif

