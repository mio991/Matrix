#pragma once

#include "Matrix.hpp"

class Vector2 : public Matrix
{
public:
	/**
	* Erzeugt ein leeren 2-Vektor.
	*/
	Vector2();
	/**
	* Erzeugt einen 2-Vektor mit den übergebenen einträgen.
	* @param a0 Der Wert an der Stelle 0
	* @param a1 Der Wert an der Stelle 1
	*/
	Vector2(double a0, double a1);

	/**
	* Setzt den Wert an der Stelle m auf value
	* @param m Die Stelle die gesetzt werden soll.
	* @param value Der Zielwert auf den m gesetzt werden soll
	*/
	void set(size_t m, double value);
};
