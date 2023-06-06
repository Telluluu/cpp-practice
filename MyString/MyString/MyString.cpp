#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"MyString.h"

int main()
{
	using namespace std;
	MyString s1;
	MyString s2;
	s1 = "Hello World!";
	s2 = "Big Three!";
	cout << s1.get_cstr() << s2.get_cstr() << endl;
}