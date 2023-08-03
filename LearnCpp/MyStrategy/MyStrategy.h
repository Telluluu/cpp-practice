#pragma once
#ifndef _MYSTRATEGY_
#define _MYSTRAGEGY

#include<iostream>

class Strategy
{
public:
	virtual ~Strategy(){}
	virtual void AlgorithmInterface() = 0;
};


class ConcreteStrategyA: public Strategy
{
public:
	void AlgorithmInterface() override
	{
		std::cout << "AlgorithmInterface A" << std::endl;
	}
};


class ConcreteStrategyB : public Strategy
{
public:
	void AlgorithmInterface() override
	{
		std::cout << "AlgorithmInterface B" << std::endl;
	}
};


class ConcreteStrategyC : public Strategy
{
public:
	void AlgorithmInterface() override
	{
		std::cout << "AlgorithmInterface C" << std::endl;
	}
};

class Context
{
public:
	Context():m_strategy(nullptr){};
	Context(Strategy* strategy) :m_strategy(strategy) {}
	~Context() { delete m_strategy; }
	void operator = (Strategy* strategy)
	{
		m_strategy = strategy;
	}

	void AlgorithmInterface()
	{
		m_strategy->AlgorithmInterface();
	}

private:
	Strategy* m_strategy;


		
};
#endif // !_MYSTRATEGY_
