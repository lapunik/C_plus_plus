#include <iostream>
using namespace std;

class Complex 
{
private:
	double re, im;

public:

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}
	
	Complex operator + (Complex& b) 
	{
		return Complex(re + b.re, im * b.im);
	}

	Complex operator * (int b)
	{
		return Complex(re * b, im * b);
	}

	void Display() 
	{
		cout << re << ", " << im << "\n";
	}

};

int main() {
	Complex a = Complex(1.2, 3.4);
	Complex b = Complex(5.6, 7.8);
	Complex c = Complex(0.0, 0.0);

	c = a + b;
	
	c.Display();

	c = c * 2;

	c.Display();


}