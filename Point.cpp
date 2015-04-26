/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.2
Zeitaufwand: 1,5h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum
Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
Operatoren "+", "++", "--" und "<<" hinzugefügt | Geckeler | 23.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Klasse Point die das geometrische Objekt Punkt darstellt
---------------------
*/

#include "Ponit.hpp"

// Standart Konstruktor
Point::Point() :x(0), y(0)
{
}

Point::Point(double posX, double posY) : x(posX), y(posY)
{
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
double Point::getX()
{
	return this->x;
}

// Methode um die Y-Koordinade vom Punkt zu setzten.
void Point::setY(double posY)
{
	this->y = posY;
}

// Methode um die Y-Koordinade vom Punkt abzufragen.
double Point::getY()
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
void Point::print(bool newLine)
{
	if (newLine== true)
		cout << "(" << this->x << ", " << this->y << ")"<< endl;
	else
		cout << "(" << this->x << ", " << this->y << ")";
}

// Operator "<<"
ostream & operator<< (ostream & o, Point & pos)
{
	// Inser Point.toString von Aufgabe 3
	return o;
}

// Operator "=" um eine Punkt einem anderen zuweisen zu können (z.B. P2 = P1)
Point Point::operator= (Point pos)
{
	this->setX(pos.getX());
	this->setY(pos.getY());

	return *this;
}


// Operator "++" für prefix increment eines Punktes
Point Point::operator++()
{
	double temp = this->getX();
	temp++;
	this->setX(temp);

	temp = this->getY();
	temp++;
	this->setY(temp);

	return *this;
}

// Operator "++" für postfix increment eines Punktes
Point Point::operator++(int i)
{
	Point temp = *this;
	++*this;

	return temp;
}

// Operator "++" für prefix decrement eines Punktes
Point Point::operator--()
{
	double temp = this->getX();
	temp--;
	this->setX(temp);

	temp = this->getY();
	temp--;
	this->setY(temp);

	return *this;
}

// Operator "++" für postfix decrement eines Punktes
Point Point::operator--(int i)
{
	Point temp = *this;
	--*this;

	return temp;
}

// Operator "+" um Pumkte addieren zu können (z.B. P1 + P2 + P3)
Point Point::operator+(Point p)
{
	p.setX(p.getX() + p.getX());
	p.setY(p.getY() + p.getY());

	return p;
}

// Operator "+" um auf einen Punkt einen Offset aufrechenen zu können
Point operator+ (Point p, double offset)
{
	p.setX(p.getX() + offset);
	p.setY(p.getY() + offset);

	return p;
}

// Operator "+" um auf einen Punkt einen Offset aufrechenen zu können
Point operator+ (double offset, Point p)
{
	p = p + offset;
	return p;
}

// Operator "-" um Punkte subtrahieren zu können (z.B. P1 - P2 - P3)
Point Point::operator-(Point p)
{
	p.setX(p.getX() - p.getX());
	p.setY(p.getY() - p.getY());

	return p;
}

// Operator "-" um einen Punkt negieren zu könnne
Point Point::operator-()
{
	this->setX(this->getX()*(-1));
	this->setY(this->getY()*(-1));

	return *this;
}
