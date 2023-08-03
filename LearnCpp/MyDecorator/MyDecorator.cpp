#include "MyDecorator.h"

int main()
{
	ConcreteComponentMetal* metal = new ConcreteComponentMetal();
	ConcreteComponentPunk* punk = new ConcreteComponentPunk();
	ConcreteComponentRock* rock = new ConcreteComponentRock();
	ConcreteDecoratorAvant_grade ag(metal);
	ConcreteDecoratorPost postpunk(punk);
	ConcreteDecoratorPost postrock(rock);


	std::cout << ag.GetStyle() << std::endl;
	std::cout << postpunk.GetStyle() << std::endl;
	std::cout << postrock.GetStyle() << std::endl;

	return 0;
}