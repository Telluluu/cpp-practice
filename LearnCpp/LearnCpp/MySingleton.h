#pragma once
#ifndef _MYSINGlETON_
#define _MYSINGLETON_

#include<iostream>
#include<string>

class Singleton
{
private:
	Singleton();
	~Singleton();
	Singleton(const std::string value);

public:
	//用getInstance获取单例
	static Singleton* getInstance(const std::string& value);
	void print()const;

	//拷贝构造和复制被禁止
	Singleton(const Singleton& sing) = delete;
	Singleton& operator = (const Singleton& sing) = delete;


private:
	static Singleton* _singleton;
	std::string _value;
};

Singleton* Singleton::_singleton = nullptr;

inline Singleton::Singleton() {}

inline Singleton::Singleton(const std::string value) :_value(value){}

inline Singleton* Singleton::getInstance(const std::string& value)
{
	if (_singleton == nullptr)
	{
		_singleton = new Singleton(value);
	}
	return _singleton;
}

inline void Singleton::print()const
{
	std::cout << _value << std::endl;
}

#endif // !_MYSINGlETON_
