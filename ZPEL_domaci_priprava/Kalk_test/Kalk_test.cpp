#include<iostream>
#include<string>
#include<limits>

int main()
{

	int a = INT_MAX;

	std::cout << a << "\t" << static_cast<float>(a) << "\t" << (float)a;
}