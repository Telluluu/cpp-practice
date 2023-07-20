#pragma once
#ifndef _MYFACTORY_
#define _MYFACTORY_

#include <iostream>

class Metal
{
public:
	virtual void show()const = 0;
};

class BlackMetal : public Metal
{
public:
	void show()const
	{
		std::cout << "Black Metal is War" << std::endl;
	}
};

class DeathMetal :public Metal
{
public:
	void show()const
	{
	std::cout << "Fast&Sick" << std::endl;
	}
};

class Electronic
{
public:
	virtual void show() = 0;
};

class Breakcore : public Electronic
{
	void show()const
	{
		std::cout << "I'm Breakcore" << std::endl;
	}
};

class Hardcore : public Electronic
{
	void show()const
	{
		std::cout << "Hardcore TANO*C" << std::endl;
	}
};

template<class AbstractProduct_t>
class AbstractFactory
{
	virtual AbstractProduct_t* CreatProduct() = 0;
};

template<class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t>
{
public:
	AbstractProduct_t* CreatProduct()
	{
		return new ConcreteProduct_t();
	}
};
#endif // !_MYFACTORY_
