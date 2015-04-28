/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,25h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
Methode toString und Konvertierungskonstruktor hinzu. Die Methode Print greift nun auf die Methode toString zu. Tommel 24.4.15
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
	Circle(string);								// Legt aus einem String im Format ("<(5.5, 6.6), 10.1>") einen Kreis an.
	~Circle();

	void setCentre(Point pos);
	Point getCentre() const;
	void setRadius(double r);
	double getRadius() const;

	void move(double dx, double dy);
	void print(bool newLine = true) const;

	string toString()const;							// Erzeugt eine Ausgabe in einem string outputstream 

private:
	Point centre;
	double radius;
	

};
