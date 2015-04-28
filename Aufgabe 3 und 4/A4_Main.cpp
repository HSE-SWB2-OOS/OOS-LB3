#include <iostream>
#include <string>
#include "Circle.hpp"
#include "Polygonline.hpp"
using namespace std;
// Hauptprogramm
int main(void)
{
	//Point p1(1, 1), p2(2, 2),p3,p4(4,4);

	//p3 = p1 + p2 + p4;

	//p3 = p1 - p2;
	//p3 = p2 - p1;
	//p3 = -p4;

	//p4 = p4 + 4;
	//p4 = 4.5 + p4;

	//p3 = p2++;
	//p4 = ++p1;

	//Polygonline l1(p1), l2(p2), l3(p3), l4;
	//l1 + p2;
	//l1 + l2 + l3;

	//Circle c1(p2, 2);
	//c1.print();
	//cout << c1<< endl;

	//cout << p1 << endl;
	//cout << l1 << endl; 
	//cout << "Test";

	//istringstream is(" (1.1, 2.2) ist ein Punkt.");
	//Point p;
	//is >> p;

	//getchar();
	Point p1(0, 0);
	const Point p2(2, 2);
	const Point p3(3, 3);
	Circle c(p1, 1.1);
	cout << "Circle c: " << c << endl;
	p1 = p1 + 0.5;
	p1 = 0.5 + p1;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	Point p4 = p1 + p2 - p3 + 4.0;
	cout << "p4: " << p4 << endl;
	p1 = -p4;
	cout << "p1: " << p1 << endl;
	cout << "p4: " << p4 << endl;

	Point p5 = p1++;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	p5 = ++++++++p1;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	cout << "p4: " << p4 << endl;
	Polygonline l1;
	cout << "l1: " << l1 << endl;
	(l1 + p1) + p2;
	cout << "l1: " << l1 << endl;
	const Polygonline l2(p4);
	l1 + l2;
	cout << "l1: " << l1 << endl;
	cout << "l2: " << l2 << endl;

	getchar();
	return 0;
}