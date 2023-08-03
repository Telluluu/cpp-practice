#pragma once
#ifndef _MYDECORATOR_
#define _MYDECORATOR_

#include<iostream>

class Component
{
public:
	virtual ~Component(){}

	virtual std::string GetStyle() const = 0;
};

class ConcreteComponentMetal : public Component
{
public:
	virtual std::string GetStyle() const override
	{
		return "Metal";
	}
};

class ConcreteComponentPunk : public Component
{
public:
	virtual std::string GetStyle() const override
	{
		return "Punk";
	}
};

class ConcreteComponentRock : public Component
{
public:
	virtual std::string GetStyle() const override
	{
		return "Rock";
	}
};

class Decorator : public Component
{
public:
	Decorator(Component* component):component_(component){}

	virtual std::string GetStyle() const override
	{
		return this->component_->GetStyle();
	}


private:
	Component* component_;
};

class ConcreteDecoratorPost : public Decorator
{
public:
	ConcreteDecoratorPost(Component* component):Decorator(component){}

	virtual std::string GetStyle() const override
	{
		return "Post " + Decorator::GetStyle();
	}

};

class ConcreteDecoratorAvant_grade : public Decorator
{
public:
	ConcreteDecoratorAvant_grade(Component* component) :Decorator(component) {}

	virtual std::string GetStyle() const override
	{
		return "Avant_grade " + Decorator::GetStyle();
	}
};

#endif // !_MYDECORATOR_
