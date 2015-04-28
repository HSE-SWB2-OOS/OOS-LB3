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
Die Klasse Polygonline die eien Linienzug mit einer verkettenten Liste darstellt.
---------------------
*/

#pragma once
#include "Polygonline.hpp" 
#include <string>
#include <ostream>
#include <sstream>
#include "myString.hpp"
#include "Ponit.hpp"

// Default Konstruktor
Polygonline::Polygonline()
{
}

Polygonline::Polygonline(Point pPos)
{
	createNewHead(pPos);
}

Polygonline::Polygonline(string str){
	
	char checkChar;
	char pointBegin = '(';
	char pointEnd = ')';

	str = MyString::trim(str,' ');				
	istringstream strStream(str);					
	
	// Jedes Zeichen durchgehen
	do
	{
		string subStr;							
		strStream >> checkChar;
		if (checkChar == pointBegin)			
		{
			subStr += checkChar;			
			do
			{									
				strStream >> checkChar;
				subStr += checkChar;
			} while (checkChar != pointEnd);
			
			Point p(subStr);						
			this->addPoint(p);				
		}
	} while (strStream);
}

// Destruktor
Polygonline::~Polygonline()
{

	if (head != nullptr)
	{
		do
		{
			endNode = head->next;
			delete head;
			head = endNode;
		} while (endNode != nullptr);

		delete endNode;
	}
}

void Polygonline::createNewHead(Point pPos)
{
	endNode = new PlgElement();
	endNode->point = pPos;
	endNode->next = nullptr;
	this->elementCounter++;

	head = new PlgElement();
	head = endNode;
}

// Ausgabe der Linie
void Polygonline::print() const
{

	cout << this->toString() << endl;


	//PlgElement *temp = head;
	//cout << "|";

	//
	//if (this->elementCounter > 0)
	//{
	//	do
	//	{
	//		cout << "(" << temp->point.getX() << "," << temp->point.getY() << ")" ;
	//		temp = temp->next;

	//		if (this->elementCounter > 1 && temp != nullptr)
	//			cout << "-";
	//				
	//	} while (temp != nullptr);
	//}
	//cout << "|" << endl;
}

// Diese Methode fügt einen neuen Punkt zu Linie hinzu.
Polygonline & Polygonline::addPoint(Point pPos)
{
	PlgElement *temp = new PlgElement;
	temp->point = pPos;
	temp->next = nullptr;

	if (this->elementCounter == 0)
		createNewHead(pPos);
	else
	{
		endNode->next = temp;
		endNode = endNode->next;
		this->elementCounter++;
	}
	
	return *this;
}

// Diese Methode hängt die übergebene Linie an die bestehende Linie hinten an.
void Polygonline::appendPolygonline(Polygonline & additionalLine)
{
	PlgElement *temp = additionalLine.head;

	do
	{
		addPoint(temp->point);
		temp = temp->next;
	} while (temp != nullptr);
		
}

// Diese Methode verschiebt die Linie um den angegebenen offset.
void Polygonline::move(double dx, double dy)
{
	PlgElement *temp = head;

	do
	{
		temp->point.move(dx,dy);
		temp = temp->next;
	} while (temp != nullptr);
}

PlgElement & Polygonline::getList() const
{
	return *this->endNode;
}

string Polygonline::toString() const {
	
	// Variablen deklaration
	
	ostringstream tempstream;
	PlgElement *temp = head;
	tempstream << "|";


	// Start schleife, jeder durchlauf füllt einen Punkt in den Stream

	if (this->elementCounter > 0)
	{
		do
		{
			tempstream << "(" << temp->point.getX() << "," << temp->point.getY() << ")";
			temp = temp->next;

			if (this->elementCounter > 1 && temp != nullptr)
				tempstream << "-";

		} while (temp != nullptr);
	}
	return tempstream.str();

}