#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>

#include <memory>

#include "Matrix.hpp"

size_t size(size_t m, size_t n);

size_t size(size_t m, size_t n)
{
	return m * n;
}

Matrix::Matrix(size_t n) : Matrix(n, n) {}
Matrix::Matrix(size_t m, size_t n) : m_Rows(m), m_Collumns(n), m_Field(new double[size(m,n)]) {}

double* Matrix::point(size_t m, size_t n) const
{
	if (m >= m_Rows)
	{
		throw std::out_of_range("m is bigger than height");
	}

	if (m >= m_Rows)
	{
		throw std::out_of_range("n is bigger than width");
	}

	return (m_Field + n + (m*m_Collumns));
}

double& Matrix::at(size_t m, size_t n) 
{
	return *point(m,n);
}


double Matrix::at(size_t m, size_t n) const
{
	return *point(m,n);
}


void Matrix::set(size_t m, size_t n, double value)
{
	at(m,n) = value;
}

double Matrix::norm() const
{
	double sum = 0;

	for (size_t i = 0; i < m_Rows; i++)
	{
		for (size_t j = 0; j < m_Rows; j++)
		{
			sum += std::pow(at(i, j), 2);
		}
	}

	return std::sqrt(sum);
}

Matrix Matrix::transpose() const
{
	Matrix result(m_Collumns,m_Rows);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Collumns; ++j)
		{
			result.at(i, j) = this->at(j,i);
		}
	}
	return result;
}


size_t Matrix::height() const
{
	return m_Rows;
}

size_t Matrix::width() const
{
	return m_Collumns;
}

Matrix Matrix::add(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.width() != rhs.width() && lhs.height() != rhs.height())
	{
		throw std::invalid_argument("The dimensions of lhs and rhs are not equal!");
	}

	Matrix result = Matrix(lhs.height(), lhs.width());

	for (size_t i = 0; i < lhs.height(); ++i)
	{
		for (size_t j = 0; j < lhs.width(); ++j)
		{
			result.at(i, j) = lhs.at(i,j) + rhs.at(i,j);
		}
	}

	return result;
}

Matrix Matrix::dot(double lambda, const Matrix& rhs)
{
	Matrix result = Matrix(rhs.height(), rhs.width());

	for (size_t i = 0; i < rhs.height(); ++i)
	{
		for (size_t j = 0; j < rhs.width(); ++j)
		{
			result.at(i, j) = lambda * rhs.at(i,j);
		}
	}

	return result;
}

Matrix Matrix::multiply(const Matrix& rhs)
{
	return Matrix::multiply(*this, rhs);
}

Matrix Matrix::multiply(const Matrix& lhs, const Matrix& rhs)
{
	if(lhs.width() != rhs.height())
	{
		throw std::invalid_argument("lhs width dosen't equal rhs height!");
	}

	Matrix result = Matrix(lhs.height(), rhs.width());

	for (size_t i = 0; i < result.width(); ++i) // Zeile Counter
	{
		for (size_t j = 0; j < result.height(); ++j) // Spalte Counter
		{
			double sum = 0;
			for (size_t k = 0; k < lhs.width(); ++k) // Zeile-Spalte Counter
			{
				sum += lhs.at(i, k) * rhs.at(k, j);
			}
			result.at(i, j) = sum;
		}
	}

	return result;
}

void Matrix::print(std::ostream& out) const
{
	for (size_t i = 0; i < m_Collumns; ++i)
	{
		for (size_t j = 0; j < m_Rows; ++j)
		{
			out << at(i, j) << "\t";
		}
		out << std::endl;
	}
	out << std::endl;
}

Matrix::Matrix(const Matrix& o)
{
	copy_from(o);
}

void Matrix::copy_from(const Matrix& other)
{
	if(size(m_Rows,m_Collumns) 
		!= size(other.m_Rows, other.m_Collumns))
	{
		delete[] m_Field;
		m_Field = new double[size(other.m_Rows, other.m_Collumns)];
	}
	m_Rows = other.m_Rows;
	m_Collumns = other.m_Collumns;
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Collumns; ++j)
		{
			this->at(i,j) = other.at(i,j);
		}
	}
}

Matrix::~Matrix()
{
	delete[] m_Field;
}

Matrix& Matrix::operator=(const Matrix& o)
{
	this->copy_from(o);

	return *this;
}

Matrix operator+(const Matrix& lhs,const Matrix& rhs)
{
	return Matrix::add(lhs, rhs);
}

Matrix operator*(const Matrix& lhs,const Matrix& rhs)
{
	return Matrix::multiply(lhs, rhs);
}

Matrix operator*(const double lhs,const Matrix& rhs)
{
	return Matrix::dot(lhs, rhs);
}
