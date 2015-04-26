/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum
Operator "<<" hinzugefügt | Geckeler | 23.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Circle die das geometrische Objekt für Kreis darstellt.
---------------------
*/

#pragma once

#include "Ponit.hpp"

class Circle
{
public:
	Circle();
	Circle(Point pos);
	~Circle();

	void setCentre(Point pos);
	Point getCentre();
	void setRadius(double r);
	double getRadius();

	void move(double dx, double dy);
	void print(bool newLine = true);

	// Operatoren
	friend ostream & operator<< (ostream & o, Circle & circle);
private:
	Point centre;
	double radius;
	

};
