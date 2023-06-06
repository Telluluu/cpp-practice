#pragma once
#ifndef _MYSTRING_
#define _MYSTRING_



#include<cstring>

class MyString
{
public:
	MyString(const char* cstr = 0);
	MyString(const MyString& str);
	MyString& operator = (const MyString& str);
	~MyString();
	char* get_cstr()const { return m_data;}

private:
	char* m_data;
};

inline MyString::MyString(const char* cstr)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline MyString::MyString(const MyString& str)
{
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
}

inline MyString& MyString::operator = (const MyString& str)
{
	if (this == &str)
	{
		return *this;
	}
	else
	{
		delete[] m_data;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}
}

inline MyString::~MyString()
{
	delete[] m_data;
}

#endif // !_MYSTRING_H
