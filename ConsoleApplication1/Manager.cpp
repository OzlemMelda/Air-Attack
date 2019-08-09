#define NumberOfAircrafts 6
#define MaxX 76
#define MaxY 25

#include <iostream>
#include "Manager.h"
#include "Aircraft.h"
#include "Tank.h"
#include "Helicopter.h"
#include "Plane.h"
#include "Supersonic.h"
#include "fire.h"
#include "bomb.h"
#include "Package.h"
#include <vector>


using namespace std;


Manager::Manager() {
	COORDINATE BeginningC(40, 23);
	MyTank = new Tank(BeginningC, c.rgb_b(1, 1, 0, 1) | c.rgb_f(1, 0, 1, 0),c);
	Speed = 1.0;
	MyAircrafts = new Aircraft*[NumberOfAircrafts];
	for (int i = 0; i < NumberOfAircrafts; i++) {
		MyAircrafts[i] = NULL;
	}
	for (int i = 0; i < NumberOfAircrafts; i++) {
		CreateAircrafts (i);
	}

}

Manager::~Manager() {

	for (int i = 0; i < NumberOfAircrafts; i++)
		delete MyAircrafts[i];
	delete[] MyAircrafts;

	for (unsigned int i = 0; i < BombCounter; i++) {
		delete BombVector[i];
	}

	for (unsigned int i = 0; i < FireCounter; i++) {
		delete FireVector[i];
	}

	for (unsigned int i = 0; i < PackageCounter; i++) {
		delete PackageVector[i];
	}

	delete MyTank;

	for (int i = 0; i <= 80; i++) {
		for (int j = 0; j <= 25; j++) {
			c.SetColor(i, j, c.rgb_b(0, 0, 0, 0) | c.rgb_f(0, 0, 0, 0));
			c.PrintChar(i, j, ' ');
		}
	}
}

void Manager::CreateAircrafts(int i)
{
	Aircraft* pAircraft = NULL;
	int k = rand() % 4;
	/*Helicopter*/	if (k <=1) {
		int a = rand() % 2;

		if (a == 0)/*to right*/
			pAircraft = new Helicopter(COORDINATEAIR(0, 0), (8),
				c.rgb_b(1, 0, 1, 1) | c.rgb_f(1, 0, 1, 1), 0);
		else if (a == 1)/*to left*/
			pAircraft = new Helicopter(COORDINATEAIR(MaxX-3, 0), (8),
				c.rgb_b(1, 0, 1, 1) | c.rgb_f(1, 0, 1, 1), 1);
	}
	/*Plane*/	    else if (k >= 3) {
		int b = rand() % 2;

		if (b == 0)/*to right*/
			pAircraft = new Plane(COORDINATEAIR(0, 2), (4),
				c.rgb_b(0, 1, 0, 0) | c.rgb_f(1, 1, 1, 0), 0);
		else if (b == 1)/*to left*/
			pAircraft = new Plane(COORDINATEAIR(MaxX-4, 2), (4),
				c.rgb_b(0, 1, 0, 0) | c.rgb_f(1, 1, 1, 0), 1);
	}
	/*Supersonic*/	else if (k ==2) {
		int d = rand() % 2;

		if (d == 0)/*to right*/
			pAircraft = new Supersonic(COORDINATEAIR(0, 4), (2),
				c.rgb_b(1, 0, 0, 1) | c.rgb_f(1, 0, 1, 0), 0);
		else if (d == 1)/*to left*/
			pAircraft = new Supersonic(COORDINATEAIR(MaxX-3, 4), (2),
				c.rgb_b(1, 0, 0, 1) | c.rgb_f(1, 0, 1, 0), 1);
	}



	if (MyAircrafts[i]) {
		MyAircrafts[i]->Erase(c);
		delete MyAircrafts[i];
	}
	MyAircrafts[i] = pAircraft;
}




void Manager::Run()
{
	while (true) {

		for (int i = 0; i < 10000000; i++) {}

		MyTank->Draw(c);
		MyTank->WriteYourStats(c);

		// Tankýn kullanýcýya baðlý hareketleri
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'a') {
				MyTank->Move(MaxX, 'a', c);
			}
			else if (ch == 'd') {
				MyTank->Move(MaxX, 'd', c);
			}
			else if (ch == 'f') {
				unsigned int b = FireVector.size();
				FireVector = MyTank->Shoot('f', FireVector);
				if (FireVector.size() != b)
					FireCounter++;
			}
			else if (ch == 'e') {
				break;
			}
		}

		// Aircraftlarýn hareketleri ve Sýnýrlarda silinmeleri,yeniden yaratýlmalarý
		for (int i = 0; i < NumberOfAircrafts; i++) {
			MyAircrafts[i]->Move(Speed, c);
			if (MyAircrafts[i]->IsDead(MaxX))
				CreateAircrafts(i);
		}

		// Fire'larýn hareketleri ve sýnýrlarý
		for (int i = 0; i < FireCounter; i++) {
			
			FireVector[i]->Move(Speed, c);

			if (FireVector[i]->IsOut(-1)) {
				delete FireVector[i];
				FireVector.erase(FireVector.begin() + i);
				FireCounter--;
				i--;
			}
		}

		// Bomb'un ilerlemesi ve sýnýrlarda yok olmasý
		for (int i = 0; i < BombCounter; i++) {
			BombVector[i]->Move(Speed, c);

			if (BombVector[i]->IsOut(MaxY)) {
				MyTank->DecreaseHP();
				delete BombVector[i];
				BombVector.erase(BombVector.begin() + i);
				BombCounter--;
				i--;
			}






		}

		// Package ilerlemesi ve sýnýrlarda yok olmasý
		for (int i = 0; i < PackageCounter; i++) {
			PackageVector[i]->Move(Speed, c);

			if (PackageVector[i]->IsOut(MaxY)) {

				delete PackageVector[i];
				PackageVector.erase(PackageVector.begin() + i);
				PackageCounter--;
				i--;
			}






		}

		// Bomb'un oluþturulmasý
		for (int i = 0; i < NumberOfAircrafts; i++) {

			unsigned int a = BombVector.size();
			BombVector = MyAircrafts[i]->ReleaseBomb(BombVector, c);

			if (BombVector.size() != a)
				BombCounter++;
		}

		//Package'ýn alýnmasý
		if (PackageCounter > 0) {
			for (int i = 0; i < PackageCounter; i++) {
				if (PackageVector[i]->IsTaken(MyTank) ) {
					
					PackageVector[i]->Erase(c);
					delete PackageVector[i];
					PackageVector.erase(PackageVector.begin() + i);
					PackageCounter--;
					i--;
				}
			}
		}
	
		// Fire'ýn Bomb'larý vurmasý
		for (unsigned int i = 0; i < BombCounter; i++) {
			for (unsigned int j = 0; j < FireCounter; j++) {
				if (BombVector[i]->IsHit(FireVector[j])) {

					BombVector[i]->Erase(c);
					FireVector[j]->Erase(c);

					delete FireVector[j];
					delete BombVector[i];
					FireVector.erase(FireVector.begin() + j);
					BombVector.erase(BombVector.begin() + i);
					i--;
					BombCounter--;
					FireCounter--;
					break;
				}
			}
		}

		// Fire'larýn Packageý vurmasý
		for (unsigned int i = 0; i < PackageCounter; i++) {
			for (unsigned int j = 0; j < FireCounter; j++) {
				if (PackageVector[i]->IsHit(FireVector[j])) {

					PackageVector[i]->Erase(c);
					FireVector[j]->Erase(c);

					delete FireVector[j];
					delete PackageVector[i];
					FireVector.erase(FireVector.begin() + j);
					PackageVector.erase(PackageVector.begin() + i);
					i--;
					PackageCounter--;
					FireCounter--;
					break;
				}
			}
			;
		}
		
		// Fire'larýn Aircraftý vurmasý ve Package yaratýlmasý
		for (int i = 0; i < NumberOfAircrafts; i++) {
			for (int j = 0; j < FireCounter; j++) {

				if (MyAircrafts[i]->IsHit(FireVector[j]) == 1)
				{
					
					unsigned int a = PackageVector.size();
							PackageVector = MyAircrafts[i]->ReleasePackage(PackageVector, c);

					if (PackageVector.size() != a)
							PackageCounter++;
					
					MyTank->IncreaseAmmoLess();
					
					CreateAircrafts(i);

					FireVector[j]->Erase(c);
					delete FireVector[j];
					FireVector.erase(FireVector.begin() + j);
					FireCounter--;
					j--;
				}

				else if (MyAircrafts[i]->IsHit(FireVector[j]) == 2) {

					FireVector[j]->Erase(c);
					delete FireVector[j];
					FireVector.erase(FireVector.begin() + j);
					FireCounter--;
					j--;
				}
			}
		}

		// Oyunun Bitmesi
		if (MyTank->IsOver() == 1)
			break;






	}
	}
