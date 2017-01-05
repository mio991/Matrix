#pragma once

#include <iostream>

/**
* Stellt eine Matrix dar.
*/
class Matrix
{
public:
	/**
	* Standard Copy-Construktor
	* @param o Das Orginal das kopiert wird.
	*/
	Matrix(const Matrix& o);
	/**
	* Der Constructor für eine quadratische Matrix.
	* @param n Die größe der Matrix
	*/
	Matrix(size_t n);
	/**
	* Erzeugt eine mxn Matrix.
	* @param m Die Anzahl der Zeilen.
	* @param n Die Spaltenzahl.
	*/
	Matrix(size_t m, size_t n);

	/**
	* Gibt den Wert an der Stelle (m, n) zurück. 
	* 0 bezeichnet jewails das erste Element. Wenn n nicht übergeben wird ist n = 0.
	* @param m Die Zeile in der das Element liegt.
	* @param n Die Spalte in der das Element liegt.
	* @return Der Wert bei (m, n)
	*/
	double at(size_t m, size_t n = 0) const;
	/**
	* Gibt eine Reference zur Stelle (m, n) zurück. 
	* 0 bezeichnet jewails das erste Element. Wenn n nicht übergeben wird ist n = 0.
	* @param m Die Zeile in der das Element liegt.
	* @param n Die Spalte in der das Element liegt. 
	* @return Der eine Referenz auf (m, n)
	*/
	double& at(size_t m, size_t n = 0);
	/**
	* Setzt den Wert an der stelle (m, n). 
	* 0 bezeichnet jewails das erste Element.
	* @param m Die Zeile in der das Element liegt.
	* @param n Die Spalte in der das Element liegt.
	* @param value Der neue Wert des Elements (m, n).s
	*/
	void set(size_t m, size_t n, double value);

	/**
	* Multipliziert eine weitere Matrix mit dieser Matrix.
	* @param rhs Die rechte Seite der Matrixmultiplikation.
	* @return Das Ergebnis der Matrixmultiplikation.
	*/
	Matrix multiply(const Matrix& rhs);

	/**
	* Berechnet die Euklidische Norm der aktuelen Matrix.
	* @return Die Norm der Matrix
	*/
	double norm() const;
	/**
	* Transponiert die Matrix und gibt sie zurück.
	* @return Das Transpose der Matrix
	*/
	Matrix transpose() const;

	/**
	* Addiert zwei Matrizen.
	* Die Matrizen müssen die selben Dimensionen haben.
	* @param lhs Die linke Seite der Addition.
	* @param rhs Die rechte Seite der Addition.
	* @return Das Ergebnis der Addition.
	*/
	static Matrix add(const Matrix& lhs, const Matrix& rhs);
	/**
	* Multipliziert eine Matrix mit einem Realfaktor.
	* @param lambda Der Realfaktor in der Multiplikation.
	* @param rhs Die Matrix.
	* @return Das Ergebnis der Multiplikation.
	*/
	static Matrix dot(const double lambda, const Matrix& rhs);
	/**
	* Multipliziert zwei Matrizen.
	* Die Matrizen müssen den einschränkungen der Matrizenmultiplikation genügen.
	* @param lhs Die linke Seite der Multiplikation.
	* @param rhs Die rechte Seite der Multiplikation.
	* @return Das Ergebnis der Multiplikation.
	*/
	static Matrix multiply(const Matrix& lhs, const Matrix& rhs);

	/**
	* Kopiert eine Matrize in eine Andere.
	* @param o Das Orginal
	* @return Die Kopie
	*/
	Matrix& operator=(const Matrix& o);

	/**
	* Schreibt eine Darstellung der Matrix in den Ausgabestrom.
	* @param out Das Ziel des Schreibvorgangs.
	*/
	void print(std::ostream& out) const;

	/**
	* Gibt die Höhe(Zeilenzahl) der Matrix zurück.
	*/
	size_t height() const;
	/**
	* Gibt die Weite(Spaltenzahl) der Matrix zurück.
	*/
	size_t width() const;

	/**
	* Der Standarddestruktor gibt belegten speicher wieder frei.
	*/
	~Matrix();

private:
	size_t m_Rows;
	size_t m_Collumns;
	double* m_Field;

	double* point(size_t m, size_t n) const;

	void copy_from(const Matrix& other);
};

/**
	* Addiert zwei Matrizen.
	* Die Matrizen müssen die selben Dimensionen haben.
	* @param lhs Die linke Seite der Addition.
	* @param rhs Die rechte Seite der Addition.
	* @return Das Ergebnis der Addition.
	*/
Matrix operator+(const Matrix& lhs,const Matrix& rhs);
/**
	* Multipliziert zwei Matrizen.
	* Die Matrizen müssen den einschränkungen der Matrizenmultiplikation genügen.
	* @param lhs Die linke Seite der Multiplikation.
	* @param rhs Die rechte Seite der Multiplikation.
	* @return Das Ergebnis der Multiplikation.
	*/
Matrix operator*(const Matrix& lhs,const Matrix& rhs);
/**
	* Multipliziert eine Matrix mit einem Realfaktor.
	* @param lhs Der Realfaktor in der Multiplikation.
	* @param rhs Die Matrix.
	* @return Das Ergebnis der Multiplikation.
	*/
Matrix operator*(const double lhs,const Matrix& rhs);
