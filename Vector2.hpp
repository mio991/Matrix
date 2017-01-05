#pragma once

#include "Matrix.hpp"

class Vector2 : public Matrix
{
public:
	Vector2();
	Vector2(double a1, double a2);

	void set(size_t m, double value);
};
