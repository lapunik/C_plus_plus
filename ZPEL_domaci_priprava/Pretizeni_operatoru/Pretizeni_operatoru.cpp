#include <iostream>

class Vektor {
private:
    int x;
    int y;
public:
    Vektor(int r = 0, int i = 0)
    { 
        x = r;   
        y = i; 
    }

    Vektor operator + (Vektor const& obj)
    {
        Vektor v;

        v.x = x + obj.x;
        v.y = y + obj.y;

        return v;
    }

    void vypis_se()
    {
        std::cout << "x: " << x << "\ty: " << y << "\n";
    }
};

int main()
{
    Vektor a(10, 5);
    Vektor b(2, 4);
    Vektor c = a + b;
    c.vypis_se();
}