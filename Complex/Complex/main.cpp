#include"Complex.h"

int main()
{
	complex r1(1, 2);
	complex r2(3, 3);
	r1 += r2;
	r1.Print();
	std::cout << std::endl << r1 + r2;
}