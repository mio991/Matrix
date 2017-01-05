#pragma once

#include <iostream>

class Matrix
{
public:
	/**
	* Standard Copy-Construktor
	* @param o Das Orginal das kopiert wird.
	*/
	Matrix(const Matrix& o);
	/**
	* Der Standard Constructor für eine quadratische Matrix.
	* @param n 
	*/
	Matrix(size_t n);
	Matrix(size_t m, size_t n);

	double at(size_t m, size_t n = 0) const;
	double& at(size_t m, size_t n = 0);
	void set(size_t m, size_t n, double value);

	Matrix multiply(const Matrix& rhs);

	double norm() const;
	Matrix transpose() const;
	static Matrix add(const Matrix& lhs, const Matrix& rhs);
	static Matrix dot(const double lambda, const Matrix& rhs);
	static Matrix multiply(const Matrix& lhs, const Matrix& rhs);

	Matrix& operator=(const Matrix& o);

	void print(std::ostream& out) const;

	size_t height() const;
	size_t width() const;

	~Matrix();

private:
	size_t m_Rows;
	size_t m_Collumns;
	double* m_Field;

	double* point(size_t m, size_t n) const;

	void copy_from(const Matrix& other);
};

Matrix operator+(const Matrix& lhs,const Matrix& rhs);
Matrix operator*(const Matrix& lhs,const Matrix& rhs);
Matrix operator*(const double lhs,const Matrix& rhs);
