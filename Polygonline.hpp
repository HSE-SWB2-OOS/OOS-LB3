/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 16.04.2015
Version: 1.1
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum
Operator "<<" und "+" hinzugefügt | Geckeler | 24.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Polygonlinie.
---------------------
*/

#pragma once

#include "PlgElement.hpp"


class Polygonline
{
public:
	Polygonline();
	Polygonline(Point pPos);
	~Polygonline();

	void createNewHead(Point pPos);
	void print();
	Polygonline & addPoint(Point pPos);
	Polygonline & appendPolygonline(Polygonline & additionalLine);
	void move(double dx, double dy);

	PlgElement & getList();

	// Operatoren
	friend ostream & operator<< (ostream & o, Polygonline & line);
	Polygonline & operator+ (Point p);
	Polygonline & operator+ (Polygonline & l);

private:
	PlgElement *endNode;
	PlgElement *head;
	int elementCounter;

};

