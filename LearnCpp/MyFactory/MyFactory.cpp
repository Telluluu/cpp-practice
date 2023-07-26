#include "MyFactory.h"

int main()
{
	ConcreteFactory<Metal, BlackMetal> testFactory;
	Metal* blackMetal = testFactory.CreatProduct();
	blackMetal->show();

	return 0;
}