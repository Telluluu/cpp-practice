#include "MySingleton.h"

int main()
{
	Singleton* single = Singleton::getInstance("aaa");
	single->print();

	return 0;
}