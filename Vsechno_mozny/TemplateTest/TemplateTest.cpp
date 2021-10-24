#include <iostream>
#include "TamplateT.h"

using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{

	TamplateT<int> bi;
	TamplateT <float> bf;

	//TamplateT<int> = new TamplateT<int>();

	/*
	int a = 1;
	int b = 2;

	double c = 1.2;
	double d = 3.4;

	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "d: " << d << "\n" << endl;

	Swap<int>(a, b);
	Swap<double>(c, d);

	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "d: " << d << "\n" << endl;

	Swap(a, b);
	Swap(c, d);

	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "d: " << d << "\n" << endl;
	*/
}