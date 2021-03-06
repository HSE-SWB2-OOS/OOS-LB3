/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,75h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum
Operator "<<" hinzugefügt | Geckeler | 23.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Klasse Circle die das geometrische Objekt Kreis darstellt
---------------------
*/

#include "Circle.hpp"

// Standart Konstruktor
Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(Point pos)
{
	this->centre = pos;
	this->radius = 0;
}

// Destruktor
Circle::~Circle()
{
}

// Methode um den Mittelpunkt von dem Kreis zu setzten.
void Circle::setCentre(Point pos)
{
	this->centre = pos;
}

// Methode um den Mittelpunkt von dem Kreis abzufragen.
Point Circle::getCentre()
{
	return this->centre;
}

// Methde um den Radius von dem Kreis zu bestimmer.
void Circle::setRadius(double r)
{
	this->radius = r;
}

// Methode um den Radius von dem Kreis abzufragen.
double Circle::getRadius()
{
	return this->radius;
}

// Methode um den Mittelpunkt an die neuen Koordinaten zu verschieben.
// Die neue Koordinaten werden mit den alten addiert.
void Circle::move(double dx, double dy)
{
	this->centre.move(dx, dy);
}

// Methode um den Mittelpuntes und den Radius des Kreises auszugeben.
void Circle::print(bool newLine)
{
	cout << "<";

	if (newLine == true)
	{
		// Audgabe der Koordinaten des Mittelpunks ohne NewLine
		this->centre.print(false);
		cout << "," << this->radius << ">" << endl;
	}
		
	else
	{
		this->centre.print(false);
		cout << "," << this->radius << ">";
	}
}

// Operator "<<"
ostream & operator<< (ostream & o, Circle & circle)
{
	// insert Circle.toString von Aufgabe 3
	return o;
}