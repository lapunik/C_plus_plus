#include <iostream>

using namespace std;

class Kvadr
{
public:

    enum material 
    {
        drevo = static_cast<int>('x'),
        zelezo = static_cast<int>('*'),
        kamen = static_cast<int>('o'),
        guma = static_cast<int>('/'),
        keramika = static_cast<int>('+'),
    };

    enum pohled
    {
        zepredu,
        z_prava,
        shora,
    };

    Kvadr(int a, int b, int c, material m)
    {
        Zmen_rozmery(a, b, c);
        Zmen_material(mat);
    }

    Kvadr()
    {
        Zmen_rozmery(5, 6, 7);
        Zmen_material(drevo);
    }

    void Zmen_rozmery(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void Zmen_material(material m)
    {
        mat = m;
    }

    int Objem()
    {
        return a * b * c;
    }

    int Povrch()
    {
        return 2 * (a * b + b * c + c * a);
    }

    void Vykresli_se_3D()
    {
        char m = static_cast<int>(mat);

        for (int y = 0; y < b + c - 1; y++)
        {
            for (int x = 0; x <= ((2 * (a - 1)) + (c - 1)); x++)
            {
                // vykresleni svislych car
                if ((y > c - 1) && ((x == 0) || (x == (a - 1) * 2)))
                {
                    cout << m;
                }
                else if ((y <= b - 1) && (x == ((2 * (a - 1)) + (c - 1))))
                {
                    cout << m;
                }
                // vyskresleni sikmych car
                else if (((y > 0) && (y < c - 1)) || ((y > 0)&&(x > (a - 1) * 2)))
                {
                    if (((c - 1) - x) == y)
                    {
                        cout << m;
                    }
                    else if (((c - 1) - x + (a - 1)*2) == y)
                    {
                        cout << m;
                    }
                    else if (((c - 1) - x + (a - 1) * 2) == y-(b-1))
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                // vykresleni vodorovnych car
                else if ((y == 0) && (x >= c - 1))
                {
                    if (x % 2 ==(c%2==0?1:0))
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (((y == c - 1) || (y == b + c - 2)) && (x <= (a - 1) * 2))
                {
                    if (x % 2 == 0)
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else
                {
                    cout << " ";
                }
            }

            cout << "\n";

        }

    }

    void Vykresli_se_2D(pohled p) 
    {
        char m = static_cast<int>(mat);

        int a;
        int b; 

        switch (p)
        {
        case Kvadr::zepredu:
            a = this->a;
            b = this->b;
            break;
        case Kvadr::z_prava:
            a = this->c;
            b = this->b;
            break;
        case Kvadr::shora:
            a = this->a;
            b = this->c;
            break;
        default:
            break;
        }
        cout << "\n";
        for (int y = 0; y < b; y++)
        {
            for (int x = 0; x <= (a-1)*2; x++)
            {
                if ((x == 0) || (x == (a - 1) * 2))
                {
                    cout << m;

                }
                else if ((y == 0) || (y == b - 1))
                {
                    if (x % 2 == 0)
                    {
                        cout << m;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else 
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

private:

    int a = 1, b = 1, c = 2;
    material mat = drevo;
};

int main()
{
    int delka = 9, sirka = 4, vyska = 6;
    cout << "Zadej rozmery kvadru: " << "\n";
    cin >> delka >> sirka >> vyska;

    Kvadr k(delka, sirka, vyska,Kvadr::drevo);
    cout << "Objem kvadru: " << k.Objem() << "\n";
    cout << "Povrch kvadru: " << k.Povrch() << "\n\n";
    k.Vykresli_se_2D(Kvadr::zepredu);
    k.Vykresli_se_2D(Kvadr::z_prava);
    k.Vykresli_se_2D(Kvadr::shora);
    k.Vykresli_se_3D();

    Kvadr kk; // ukázat příkald se stringem.

    cout << "Objem kvadru: " << kk.Objem() << "\n";
    cout << "Povrch kvadru: " << kk.Povrch() << "\n\n";
    kk.Vykresli_se_2D(Kvadr::zepredu);
    kk.Vykresli_se_2D(Kvadr::z_prava);
    kk.Vykresli_se_2D(Kvadr::shora);
    kk.Vykresli_se_3D();
}