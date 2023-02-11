#include <iostream>
#include <functional>

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiple(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

int main()
{
	std::function<int(int, int)> func;
	func = add;
	std::cout << func(4, 2) << std::endl;
	func = subtract;
	std::cout << func(4, 2) << std::endl;
	func = multiple;
	std::cout << func(4, 2) << std::endl;
	func = divide;
	std::cout << func(4, 2) << std::endl;
}


// OR:


//#include <iostream>
//#include <functional>
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int subtract(int a, int b)
//{
//	return a - b;
//}
//
//int multiple(int a, int b)
//{
//	return a * b;
//}
//
//int divide(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	auto func = std::bind(add, std::placeholders::_1, std::placeholders::_2);
//	std::cout << func(4, 2) << std::endl;
//	func = std::bind(subtract, std::placeholders::_1, std::placeholders::_2);
//	std::cout << func(4, 2) << std::endl;
//	func = std::bind(multiple, std::placeholders::_1, std::placeholders::_2);
//	std::cout << func(4, 2) << std::endl;
//	func = std::bind(divide, std::placeholders::_1, std::placeholders::_2);
//	std::cout << func(4, 2) << std::endl;
//}


// OR:


//#include <iostream>
//
//typedef int (*function)(int, int);
//
//int add(int a, int b) 
//{
//	return a + b;
//}
//
//int subtract(int a, int b)
//{
//	return a - b;
//}
//
//int multiple(int a, int b)
//{
//	return a * b;
//}
//
//int divide(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	function func = add;
//	std::cout << func(4, 2) << std::endl;
//	func = subtract;
//	std::cout << func(4, 2) << std::endl;
//	func = multiple;
//	std::cout << func(4, 2) << std::endl;
//	func = divide;
//	std::cout << func(4, 2) << std::endl;
//}