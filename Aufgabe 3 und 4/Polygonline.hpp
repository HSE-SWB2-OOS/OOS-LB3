/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 16.04.2015
Version: 1.1
Zeitaufwand: xh

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
Methode toString hinzu, Sie liefert einen String für die Ausgabe, Methode print ruft jetzt toString auf.
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Polygonlinie.
---------------------
*/

#pragma once
#include "PlgElement.hpp"
#include <sstream>
#include <string>

class Polygonline
{
public:
	Polygonline();
	Polygonline(Point pPos);
	Polygonline(string);											// Konvertierkonstruktor wandelt einen String in ein Objekt um.
	~Polygonline();

	void createNewHead(Point pPos);
	void print() const;
	Polygonline & addPoint(Point pPos);
	void appendPolygonline(Polygonline & additionalLine);
	void move(double dx, double dy);
	PlgElement & getList() const;
	string toString() const;										// Wandelt die Infos des Objektes in einen String um
	

private:
	PlgElement *endNode;
	PlgElement *head;
	int elementCounter;

};

