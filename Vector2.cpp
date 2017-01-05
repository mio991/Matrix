#include "Vector2.hpp"

Vector2::Vector2() : Matrix(2, 1) {}
Vector2::Vector2(double a1, double a2) : Matrix(2, 1)
{
	at(0) = a1;
	at(1) = a2;
}

void Vector2::set(size_t m, double value)
{
	Matrix::set(m, 0, value);
}
