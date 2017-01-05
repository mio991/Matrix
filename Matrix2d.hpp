#pragma once

#include "Matrix.hpp"

class Matrix2d : public Matrix
{
public:
	/**
	* Erzeugt eine leere 2x2 Matrix.
	*/
	Matrix2d();
	/**
	* Erzeugt eine 2x2 Matrix mit den übergebenen einträgen.
	* @param a00 Der Wert an der Stelle (0, 0)
	* @param a01 Der Wert an der Stelle (0, 1)
	* @param a10 Der Wert an der Stelle (1, 0)
	* @param a11 Der Wert an der Stelle (1, 1)
	*/
	Matrix2d(double a00, double a01, double a10, double a11);

	//static Matrix2d unit();
	
};
