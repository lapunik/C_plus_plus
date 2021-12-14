#include <iostream>

using namespace std;

template<typename T>
void Funkce(T a)
{
    cout << "Ja jsem funkce se sablonou vstupnim argumentem: " << a << "\n";
}

void Funkce(double a)
{
    cout << "Ja jsem funkce s double vstupnim argumentem: " << a << "\n";
}

void Funkce(string slovo)
{
    cout << "Ja jsem funkce se string vstupnim argumentem: " << slovo << "\n";
}

void Funkce(int a, int b)
{
    cout << "Ja jsem funkce s int vstupnimi argumenty: " << a <<" a " << b << "\n";
}

void Funkce(int a)
{
    cout << "Ja jsem funkce s int vstupnim argumentem: " << a << "\n";
}

void Funkce() 
{
    cout << "Ja jsem funkce bez vstupnich argumentu\n";
}


int main()
{
    double cislo = 5.6;

    Funkce();
    Funkce(15);
    Funkce(11, 0);
    Funkce("Ahoj");
    Funkce(15.0);
    Funkce(cislo);
    Funkce<int>(15);
}