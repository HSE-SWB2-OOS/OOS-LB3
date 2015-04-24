/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.2
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Aenderungsgrund | durchgefuehrte Aenderung | Autor | Datum
Main von Aufgabe 3.2 fordert weiteren Konstruktor |	Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
Methode toString, operator >> hinzugefügt, Methode Print nutzt jetzt toString für seine Ausgabe. | Tommel | 24.4.15
-------------------------------------------------------
Programmbeschreibung:
Die Klasse Point die das geometrische Objekt Punkt darstellt
---------------------
*/

#pragma once
#include "Ponit.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include "MyString.hpp"

// Standart Konstruktor
Point::Point() :x(0), y(0)
{
}

Point::Point(double posX, double posY) : x(posX), y(posY)
{
}


// Konvertierungskonstruktor, konvertiert einen String zu einem netten Punkt.
Point::Point(string str){
	// istringstream(str) >> this;

	// Hinweis: Übergabe des Strings muss zwischen "(" und ")" mit Punkten durch komma getrennt, als isstream (InputStringStream erfolgen)
	// Leerzeichen entfernen
	str = MyString::trim(str, ' ');

	int xStart = (int)str.find("(") + 1;
	int xEnde = (int)str.find(",") - 1;
	int yStart = (int)str.find(",") + 1;
	int yEnde = (int)str.find(")") - 1;

	this->setX(stod(str.substr(xStart, xEnde)));
	this->setY(stod(str.substr(yStart, yEnde)));
}

// Destruktor
Point::~Point()
{
}

// Methode um die X-Koordinade vom Punkt zu setzten.
void Point::setX(double posX)
{
	this->x = posX;
}

// // Methode um die X-Koordinade vom Punkt abzufragen.
double Point::getX() const
{
	return this->x;
}

// Methode um die Y-Koordinade vom Punkt zu setzten.
void Point::setY(double posY)
{
	this->y = posY;
}

// Methode um die Y-Koordinade vom Punkt abzufragen.
double Point::getY() const
{
	return this->y;
}

// Methode um den Punkt an die neuen Koordinaten zu verschieben.
// Die neue Koordinaten werden mit den alten addiert.
void Point::move(double dx, double dy)
{
	this->x += dx;
	this->y += dy;
}

// Methode um die Koordinaten des Punktes auszugeben.
void Point::print(bool newLine) const
{
	if (newLine == true)
		cout << this->toString() << endl;
	else
		cout << this->toString();
}

string Point::toString() const{
	ostringstream temp;
	temp << "(" << this->x << ", " << this->y << ")";
	return temp.str();
	}


// Operator >> weist einem Punkt Koordinaten über einen String zu.
void operator>>(Point pt, istringstream strStream) {    // Ändern zu istream -> könnte das Problem beheben.

	string str = strStream.str();
	// Hinweis: Übergabe des Strings muss zwischen "(" und ")" mit Punkten durch komma getrennt, als isstream (InputStringStream erfolgen)

	// Leerzeichen entfernen
	str = MyString::trim(str, ' ');

	int xStart = (int)str.find("(") + 1;
	int xEnde = (int)str.find(",") - 1;
	int yStart = (int)str.find(",") + 1;
	int yEnde = (int)str.find(")") - 1;

	pt.setX(stod(str.substr(xStart,xEnde)));
	pt.setY(stod(str.substr(yStart,yEnde)));
}
