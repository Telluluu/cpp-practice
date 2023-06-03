#pragma once
#ifndef _COMPLEX_H
#define _COMPLEX_H

#include<iostream>

class complex
{
public:
	complex(double r = 0, double i = 0)
		:re(r),im(i)
	{ }
	double real()const { return re; }
	double image()const { return im; }



	void Print();
	bool operator == (const complex& r);

	complex& operator += (const complex& r);
	complex& operator -= (const complex& r);
	complex& operator *= (const complex& r);
	complex& operator /= (const complex& r);
private:
	double re,im;
	friend complex& _doapl(complex*, const complex&);

};

std::ostream& operator << (std::ostream& os, const complex& x)
{
	return os << "(" << x.real() << "," << x.image() << ")";
}

inline void complex::Print()
{
	std::cout << "(" << re << "," << im << ")";
}

inline bool complex::operator == (const complex& r)
{
	if ((this->re == r.re) && (this->im == r.im))
		return 1;
	else return 0;
}

inline complex& complex::operator += (const complex& r)
{
	return _doapl(this, r);
}

inline complex& _doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex& complex::operator -= (const complex& r)
{
	this->re -= r.re;
	this->im -= r.im;
	return *this;
}

inline complex& complex::operator *= (const complex& r)
{
	this->re *= r.re;
	this->im *= r.im;
	return *this;
}

inline complex& complex::operator /= (const complex& r)
{
	this->re /= r.re;
	this->im /= r.im;
	return *this;
}

inline complex operator + (const complex& x, const complex& y)
{
	return complex(x.real() + y.real(), x.image() + y.image());
}

inline complex operator + (const complex& x, const double& y)
{
	return complex(x.real() + y, x.image());
}

inline complex operator + (const double& x, const complex& y)
{
	return complex(x + y.real(), y.image());
}

inline complex operator - (const complex& x, const complex& y)
{
	return complex(x.real() - y.real(), x.image() - y.image());
}

inline complex operator - (const complex& x, const double& y)
{
	return complex(x.real() - y, x.image());
}

inline complex operator - (const double& x, const complex& y)
{
	return complex(x - y.real(), y.image());
}

inline complex operator * (const complex& x, const complex& y)
{
	return complex(x.real() * y.real(), x.image() * y.image());
}

inline complex operator * (const complex& x, const double& y)
{
	return complex(x.real() * y, x.image());
}

inline complex operator * (const double& x, const complex& y)
{
	return complex(x * y.real(), y.image());
}

inline complex operator / (const complex& x, const complex& y)
{
	return complex(x.real() / y.real(), x.image() / y.image());
}

inline complex operator / (const complex& x, const double& y)
{
	return complex(x.real() / y, x.image());
}

inline complex operator / (const double& x, const complex& y)
{
	return complex(x / y.real(), y.image());
}

#endif // !_COMPLEX_H
