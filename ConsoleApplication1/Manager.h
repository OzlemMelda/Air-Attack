#ifndef MANAGER_H
#define MANAGER_H
#include "console.h"
#include <vector>

using namespace std;

class Aircraft;
class Tank;
class Fire;
class Bomb;
class Package;

class Manager {
	Tank* MyTank;
	Console c;
	Aircraft** MyAircrafts;
	vector<Fire*> FireVector;
	vector<Bomb*> BombVector;
	vector<Package*> PackageVector;
	double Speed;
	void CreateAircrafts(int i);
	
	unsigned int FireCounter = 0;
	unsigned int BombCounter = 0;
	unsigned int PackageCounter = 0;
public:
	Manager();
	~Manager();

	void Run();

};
#endif // !MANAGER_H
