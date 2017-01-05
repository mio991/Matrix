#include "Matrix2d.hpp"

Matrix2d::Matrix2d() : Matrix(2) {}
Matrix2d::Matrix2d(double a11, double a12, double a21, double a22) : Matrix(2)
{
	at(0, 0) = a11;
	at(0, 1) = a12;
	at(1, 0) = a21;
	at(1, 1) = a22;
}
