#include "Manager.h"
#include <iostream>

using namespace std;

void main() {
	char ch,k='a';
	cout << "Press S to Start The Game" << endl;
	cin >> ch;
Manager* m= new Manager ();

	if (ch == 's') {
	m->Run();
	}
	
	delete m;

}