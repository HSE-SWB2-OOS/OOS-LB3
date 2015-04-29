#include <iostream>
#include "Fahrzeug.hpp"
using namespace std;

int main() {
	Fahrzeug f1("ES - H 1234");
	cout << f1 << endl;
	f1.fahren(101.5);
	cout << f1 << endl;
	Fahrzeug f2("ES - M 4711");
	f2.fahren(10.57);
	cout << f2 << endl;
	cout << Fahrzeug::getSummeKm() << endl;
	Fahrzeug *f3 = new Fahrzeug("RW - TG 6969");
	f3->fahren(100.0);
	cout << *f3 << endl;
	cout << Fahrzeug::getSummeKm() << endl;
	delete(f3);
	cout << Fahrzeug::getSummeKm() << endl;
	cin.get();
	return 0;
}