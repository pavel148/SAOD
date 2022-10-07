#pragma once
#include <cmath>
using namespace std;

class Complex
{
public:
	double Re, Im;
		/* Complex() 
		 {
			 this->Re = 0;
			 this->Im = 0;
		 }*/
		 Complex(double re = 0.0, double im = 0.0)
		{
		 Re = re;
		 Im = im;

		}
	 double Mod(Complex c)
	{
			  return(sqrt(c.Re * c.Re + c.Im * c.Im));
	}
	 double Arg(Complex c)
	 {
		 if (c.Re > 0) return atan(c.Re/c.Im);
		 if (c.Re == 0)
		 {
			 if (c.Im > 0) return (acos(0));
			 if (c.Im < 0) return (-acos(0));
			 if (c.Im == 0) return 0.0;
		 }
			 if (c.Re < 0) 
			{
				 if (c.Im >=0 ) return (acos(-1) + atan(c.Im/c.Re));
				 if (c.Im < 0) return (-acos(-1) - atan(c.Im / c.Re));
			}
	 }
	Complex Conjugate(Complex c)
	{
		return Complex(c.Re, -c.Im);
	}

	Complex operator +(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator -(const Complex& c)const
	{
		return Complex(Re - c.Re, Im - c.Im);
	}
	Complex operator *(const Complex& c)const
	{
		return Complex (Re*c.Re-Im*c.Im, Re*c.Im+c.Re*Im);
	}
	
	Complex operator /(const Complex& c)const
	{
		return Complex((Re * c.Re + Im * c.Im)/(c.Re*c.Re+c.Im*c.Im), (-Re*c.Im+c.Re*Im)/(c.Re*c.Re+c.Im*c.Im));
	}
	

};
inline ostream& operator << (ostream& o, const Complex& c)
{
	return o << '(' << c.Re << ", " << c.Im << ')';
}

