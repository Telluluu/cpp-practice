#include "MyStrategy.h"

int main()
{
	Strategy* straA;
	straA = new ConcreteStrategyA();
	Strategy* straB;
	straB = new ConcreteStrategyB();
	Strategy* straC;
	straC = new ConcreteStrategyC();

	Context context(straA);
	context.AlgorithmInterface();
	context = straB;
	context.AlgorithmInterface();
	context = straC;
	context.AlgorithmInterface();

	return 0;
}