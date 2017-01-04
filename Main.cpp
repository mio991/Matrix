#include <iostream>
#include "Matrix.hpp"

int main()
{
	Matrix kuchen(2);

	Matrix torte(2);
	torte.set(0, 0, 1);
	torte.set(0, 1, 0);
	torte.set(1, 0, 0);
	torte.set(1, 1, 1);

	kuchen.set(0, 0, 1);
	kuchen.set(0, 1, 2);
	kuchen.set(1, 0, 3);
	kuchen.set(1, 1, 4);


	kuchen.print(std::cout);

	torte.print(std::cout);

	torte = torte * kuchen;

	kuchen.print(std::cout);

	torte.print(std::cout);

	torte.transpose().print(std::cout);



//	std::cout << kuchen.norm() << std::endl;

	return 0;
}
