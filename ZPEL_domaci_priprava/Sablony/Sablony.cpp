#include <iostream>

using namespace std;

template<typename T>
T Socet(T a, T b) 
{
	return a + b;
}

double Soucet(double a, double b)
{
	return a + b;
}

int Soucet(int a, int b) 
{
	return a + b;
}

int main()
{
	int a = 5;
	int b = 7;

	cout << Soucet(a, b) << "\n";

	double c = 5.6;
	double d = 7.1;

	cout << Soucet(c, d) << "\n";


	cout << Socet<int>(a, b) << "\n";
	cout << Socet<double>(c, d) << "\n";



}
