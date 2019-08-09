#ifndef AMMUNATIONBONUS_H
#define AMMUNATIONBONUS_H

#include "package.h"

using namespace std;

class AmmunationBonus : public Package {


public:
	AmmunationBonus(COORDINATEP BaseIn, int SpeedIn, int colorIn );

	bool IsTaken(Tank* a);

};

#endif


