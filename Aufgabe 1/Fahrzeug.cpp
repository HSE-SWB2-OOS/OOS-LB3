/* Uebungen zu OOP, Aufgabe 5.0
Erstersteller: Thomas Günter
E-Mail: Thomas.Guenter@stud.hs-esslinge.de

Datum: 22.04.2015
Version: 1.1
Zeitaufwand: xh

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
Gesamtkilometer Aufgabe Labor 1 hinzu	Tommel am 28.4.15
-------------------------------------------------------
Programmbeschreibung:
Die Klasse Fahrzeug.
---------------------
*/

// Includes
#include "Fahrzeug.hpp"
#include <iostream>
#include "MyString.hpp"
#include <string>

// Statische Klassenvariablen
unsigned int Fahrzeug::lastVin = 0;
double Fahrzeug::summeKm = 0.0;

// Methoden

void Fahrzeug::fahren(double km){			// Erhöht den Kilometerzähler um das Argument km
	this->km+=km;
	Fahrzeug::summeKm += km;
}

unsigned int Fahrzeug::useVin(){			// Liefert eine neue Seriennummer und speichert Klassengültig die letzte Seriennummer
	return ++lastVin;
}

double Fahrzeug::getSummeKm(){return summeKm;}		// Getmethode liefert die gesamt KM zurück.

//void Fahrzeug::initVin(){
//	// Statische Klassenvariablen
//	static unsigned int lastVin = 0;
//}

	// Konstruktoren + Destruktoren

Fahrzeug::Fahrzeug(char *kennzeichen){
	this->kz = MyString(kennzeichen); 
	this->km = 0.0;
	this->vin = useVin();
}

Fahrzeug::~Fahrzeug(){
	Fahrzeug::summeKm -= this->km;
}

	// Operatoren

std::ostream & operator<<(std::ostream &s, Fahrzeug &kfz){
	return s << kfz.kz << " " << "VIN.: " << kfz.vin << " km = " << kfz.km << std::endl;
}

