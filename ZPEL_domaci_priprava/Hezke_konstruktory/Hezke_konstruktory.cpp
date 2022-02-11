#include <iostream>

class Cokoliv 
{
    int neco;
    double neco2;

    Cokoliv(int n, double n2) 
    {
        neco = n;
        neco2 = n2;
    }

    // totéž jiným způsobem

    Cokoliv(int n, double n2) : neco(n), neco2(n2)
    {

    }

};

int main()
{
    std::cout << "Hello World!\n";
}