/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Aenderungsgrund | durchgefuehrte Aenderung | Autor | Datum
Main von Aufgabe 3.2 fordert weiteren Konstruktor |	Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
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

// Standart Konstruktor
Point::Point() :x(0), y(0)
{
}

Point::Point(double posX, double posY) : x(posX), y(posY)
{
}


// Konvertierungskonstruktor, konvertiert einen String zu einem netten Punkt.
Point::Point(string str){
	istringstream(str) >> this;
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
	if (newLine== true)
		cout << "(" << this->x << ", " << this->y << ")"<< endl;
	else
		cout << "(" << this->x << ", " << this->y << ")";
}

string Point::toString() const {
	return ostream << print(false);
}


// Operator >> weist einem Punkt Koordinaten über einen String zu.
	
	// Hinweis: Übergabe des Strings muss in der Form: (" (1.1, 2.2) ist ein Punkt.") als isstream (InputStringStream erfolgen)
	
	int xStart = (int)str.find("(") +1 ;
	int xEnde = (int)str.find(",") - 1;
	int yStart = (int)str.find(",") +2;
	int yEnde = (int)str.find(")") -1;

}
