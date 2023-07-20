#pragma once
#ifndef _MYOBSERVER_
#define _MYOBSERVER_

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<iterator>
#include<memory>

//观察者
class Observer;

//被观察者
class Subject
{
public:
	Subject():m_nState(0){}

	virtual ~Subject() = default;

	virtual void Attach(const std::shared_ptr<Observer> pObserver) = 0;

	virtual void Detach(const std::shared_ptr<Observer> pObserver) = 0;

	virtual void Notify() = 0;

	virtual int GetState() { return m_nState; }

	void SetState(int state)
	{
		std::cout << "Subject updated!" << std::endl;
		m_nState = state;
	}
protected:
	std::list<std::shared_ptr<Observer>> m_pObserver_list;
	int m_nState;
};

class Observer
{
public:
	virtual ~Observer() = default;

	Observer(const std::shared_ptr<Subject> pSubject, const std::string& name = "unknown")
		:m_pSubject(pSubject), m_strName(name){}

	virtual void Update() = 0;

	virtual const std::string& name() { return m_strName; }

protected:
	std::shared_ptr<Subject> m_pSubject;
	std::string m_strName;
};

class ConcreteSubject : public Subject
{
	virtual void Attach(const std::shared_ptr<Observer> pObserver)override
	{
		//在[first,last)中找目标元素pObserver,first和last为输入迭代器
		auto iter = std::find(m_pObserver_list.begin(), m_pObserver_list.end(), pObserver);
		if (iter == m_pObserver_list.end())
		{
			std::cout << "Attach observer " << pObserver->name() << std::endl;
			//list.emplace_back(T& val) 链表尾插，列表大小加一
			m_pObserver_list.emplace_back(pObserver);
		}
	}

	virtual void Detach(const std::shared_ptr<Observer> pObserver) override
	{
		std::cout << "Detach observer" << pObserver->name() << std::endl;
		m_pObserver_list.remove(pObserver);
	}

	virtual void Notify() override
	{
		auto it = m_pObserver_list.begin();
		while (it != m_pObserver_list.end())
		{
			(*it++)->Update();
		}
	}
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(const std::shared_ptr<Subject> pSubject,const std::string& name="unknown")
		:Observer(pSubject,name){}

	void Update()override
	{
		std::cout << "Observer_" << m_strName << " get updated."
			<< "The new state is:" << m_pSubject->GetState() << std::endl;
	}
};

#endif // !_MYOBSERVER_
