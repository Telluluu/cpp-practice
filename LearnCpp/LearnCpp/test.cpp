#include"MySingleton.h"
#include"MyFactory.h"
#include"MyObserver.h"
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>

void ForEach(std::vector<int>& values, std::function<void(int)>func)
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	int a = 5;
	std::vector<int> values = {1, 3, 5, 7, 9, 2, 4, 3, 4, 0, 7, 2, 1};
	auto lambda = [=](int value) mutable {a = 7; std::cout << "Value:" << value << std::endl; };
	ForEach(values, lambda);

	std::cout << a;

	//Singleton* testSingleton = Singleton::getInstance("aaa");
	//testSingleton->print();

	//ConcreteFactory<Metal, BlackMetal> testFactory;
	//Metal* blackMetal = testFactory.CreatProduct();
	//blackMetal->show();


	//std::shared_ptr<Subject> pSubject = std::make_shared<ConcreteSubject>();
	//
	//std::shared_ptr<Observer> pObserver_1 = std::make_shared<ConcreteObserver>(pSubject, "1");
	//std::shared_ptr<Observer> pObserver_2 = std::make_shared<ConcreteObserver>(pSubject, "2");
	//std::shared_ptr<Observer> pObserver_3 = std::make_shared<ConcreteObserver>(pSubject, "3");
	//std::shared_ptr<Observer> pObserver_4 = std::make_shared<ConcreteObserver>(pSubject, "4");
	//std::shared_ptr<Observer> pObserver_5 = std::make_shared<ConcreteObserver>(pSubject, "5");
	//std::shared_ptr<Observer> pObserver_6 = std::make_shared<ConcreteObserver>(pSubject, "6");

	//pSubject->Attach(pObserver_1);
	//pSubject->Attach(pObserver_2);
	//pSubject->Attach(pObserver_3);
	//pSubject->Attach(pObserver_4);
	//pSubject->Attach(pObserver_5);
	//pSubject->Attach(pObserver_6);

	//pSubject->SetState(1);
	//pSubject->Notify();

	//pSubject->Detach(pObserver_5);
	//pSubject->Detach(pObserver_6);

	//pSubject->SetState(6);
	//pSubject->Notify();

}