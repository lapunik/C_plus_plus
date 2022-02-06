#include <iostream>

typedef int (*fce)(int, int); // je možné si ukazatel na funkci vytvořit jako "typedef" a pak s ní jednodušeji pracovat

int add(int a, int b) 
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}


int times(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int (*funkce)(int, int) = add; // ukazatel na funkci

   std::cout << "addition: " << funkce(6, 2) << "\n";

   funkce = sub;

   std::cout << "subscract: " << funkce(6, 2) << "\n";

   funkce = times;

   std::cout << "times: " << funkce(6, 2) << "\n";

   funkce = divide;

   std::cout << "divide: " << funkce(6, 2) << "\n";

   fce func = add; // přiřazení funkce "add" ukazateli na fuknci "func", který je vytvořen pomocí typedef "fce"

   std::cout << "addition: " << func(6, 2) << "\n";

   funkce = func;

   std::cout << "addition: " << funkce(6, 2) << "\n";


}
