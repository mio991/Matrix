#pragma once

#include "Matrix.hpp"

class Matrix2d : public Matrix
{
public:
	Matrix2d();
	Matrix2d(double a11, double a12, double a21, double a22);

	//static Matrix2d unit();
	
};
