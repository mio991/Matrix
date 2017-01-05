#include <iostream>
#include "Matrix2d.hpp"
#include "Vector2.hpp"

int main()
{
	Matrix2d m( -1.0, 1.0, 2.0, 5.0 );
	std::cout << m.norm() << std::endl;
	m.at(0,0) = -1.0;
	m.print( std::cout );
	m.transpose().print( std::cout );
	m.multiply( Vector2( 2.0, 0.0 ) ).print( std::cout );
	m.multiply( Vector2( 0.0, 3.0 ) ).print( std::cout );
	return 0;
}
