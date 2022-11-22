#include <iostream>
#include <vector>

class Vektor
{

public:

    int x = 0;
    int y = 0;

    static Vektor soucet_vektoru(Vektor a, Vektor b)
    {
        Vektor c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;

        return c;
    }

    void zdvojnasob_se()
    {
        x = x*2;
        y = y*2;
    }

    void vypis_se()
    {
        std::cout << "x: " << x << "\ty: " << y << "\n";
    }

private:

    int x_tajne = 0;

};

int soucet_vektoru(int a_x, int a_y, int b_x, int b_y)
{
    int x = a_x + b_x;
    int y = a_y + b_y;

    return x; // nemohu vátit y
}

int soucet_vektoru(int a, int b)
{
    return a + b;;
}

std::vector<int> soucet_vektoru(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> c;

    c.push_back(a.at(0) + b.at(0));
    c.push_back(a.at(1) + b.at(1));
    
    return c;
}

int main()
{
    //int a_x = 1;
    //int a_y = 2;

    //int b_x = 3;
    //int b_y = 1;

    //int c_x = soucet_vektoru(a_x,a_y,b_x,b_y);

    //int c_x = soucet_vektoru(a_x,b_x);
    //int c_y = soucet_vektoru(a_y,b_y);


    //std::vector<int> a = { 1,2 };
    //std::vector<int> b = { 3,1 };

    //std::vector<int> c = soucet_vektoru(a, b);

    Vektor a;
    a.x = 1;
    a.y = 2;

    a.vypis_se();

    Vektor b;
    b.x = 3;
    b.y = 1;

    b.vypis_se();
    
    Vektor c;
    //c = soucet_vektoru(a, b);
    c = Vektor::soucet_vektoru(a, b);

    c.vypis_se();

    c.zdvojnasob_se();

    c.vypis_se();

}
