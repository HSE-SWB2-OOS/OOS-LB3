/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.2
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum
Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
Operatoren "+", "++", "--" und "<<" hinzugefügt | Geckeler | 23.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Point die das geometrische Objekt Punkt darstellt.
---------------------
*/

#pragma once

#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(double posX, double posY);
	~Point();

	void setX(double posX);
	double getX();
	void setY(double posY);
	double getY();

	void move(double dx, double dy);
	void print(bool newLine = true);

	// Operatoren
	friend ostream & operator<< (ostream & o, Point & pos);
	Point operator= (Point p);
	
	friend Point operator+ (Point p, double offset);
	friend Point operator+ (double offset, Point p);
	Point operator+ (Point p);
	Point operator- (Point p);
	Point operator- ();

	Point operator++ ();
	Point operator++ (int);
	Point operator--();
	Point operator--(int);

private:
	double x;
	double y;
};


