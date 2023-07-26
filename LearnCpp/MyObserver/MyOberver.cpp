#include  "MyObserver.h"

int main()
{
	std::shared_ptr<Subject> pSubject = std::make_shared<ConcreteSubject>();

	std::shared_ptr<Observer> pObserver_1 = std::make_shared<ConcreteObserver>(pSubject, "1");
	std::shared_ptr<Observer> pObserver_2 = std::make_shared<ConcreteObserver>(pSubject, "2");
	std::shared_ptr<Observer> pObserver_3 = std::make_shared<ConcreteObserver>(pSubject, "3");
	std::shared_ptr<Observer> pObserver_4 = std::make_shared<ConcreteObserver>(pSubject, "4");
	std::shared_ptr<Observer> pObserver_5 = std::make_shared<ConcreteObserver>(pSubject, "5");
	std::shared_ptr<Observer> pObserver_6 = std::make_shared<ConcreteObserver>(pSubject, "6");

	pSubject->Attach(pObserver_1);
	pSubject->Attach(pObserver_2);
	pSubject->Attach(pObserver_3);
	pSubject->Attach(pObserver_4);
	pSubject->Attach(pObserver_5);
	pSubject->Attach(pObserver_6);

	pSubject->SetState(1);
	pSubject->Notify();

	pSubject->Detach(pObserver_5);
	pSubject->Detach(pObserver_6);

	pSubject->SetState(6);
	pSubject->Notify();

	return 0;
}