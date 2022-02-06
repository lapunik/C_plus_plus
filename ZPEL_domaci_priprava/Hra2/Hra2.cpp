#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <random>

using namespace std;

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr_sirka(1, 19); // define the range
std::uniform_int_distribution<> distr_vyska(1, 9); // define the range

struct Poloha
{
    int x;
    int y;
};

void Draw(int sirka, int vyska, Poloha player, Poloha bod)
{
    // ┌ 218

    // ┐ 191

    // └ 192

    // ┘ 217

    // ─ 196

    // │ 179

    // ▄ 220

    for (int y = 0; y <= vyska; y++)
    {
        for (int x = 0; x <= sirka; x++)
        {
            if ((y == 0) && (x == 0))
            {
                cout << static_cast<char>(218);
            }
            else if ((y == vyska) && (x == sirka))
            {
                cout << static_cast<char>(217);
            }
            else if ((y == 0) && (x == sirka))
            {
                cout << static_cast<char>(191);
            }
            else if ((y == vyska) && (x == 0))
            {
                cout << static_cast<char>(192);
            }
            else if ((x == 0) || (x == sirka))
            {
                cout << static_cast<char>(179);
            }
            else if ((y == vyska) || (y == 0))
            {
                cout << static_cast<char>(196);
            }
            else if ((y == player.y) && (x == player.x))
            {
                cout << static_cast<char>(220);
            }
            else if ((y == bod.y) && (x == bod.x))
            {
                cout << 'o';
            }
            else
            {
                cout << " ";
            }

        }
        cout << "\n";
    }

}

Poloha Hlidej_kraje(Poloha player, int vyska, int sirka)
{
    if (player.x < 1)
    {
        player.x = 1;
    }
    else if (player.y < 1)
    {
        player.y = 1;
    }
    else if (player.x > sirka - 1)
    {
        player.x = sirka - 1;
    }
    else if (player.y > vyska - 1)
    {
        player.y = vyska - 1;
    }

    return player;
}

Poloha Pohyb_hrace(Poloha player, char znak)
{
    if (static_cast<int>(znak) == 72)
    {
        player.y--;
    }
    else if (static_cast<int>(znak) == 80)
    {
        player.y++;
    }
    else if (static_cast<int>(znak) == 75)
    {
        player.x--;
    }
    else if (static_cast<int>(znak) == 77)
    {
        player.x++;
    }

    return player;
}

Poloha Generator_bodu(Poloha player, Poloha bod, int vyska, int sirka,int velikost_hada)
{

    if ((bod.x != player.x) || (bod.y != player.y))
    {
        return bod;
    }
    else
    {
        velikost_hada++;
        do
        {
            bod = { distr_sirka(gen),distr_vyska(gen)% (vyska - 2) + 1 };
        } while ((bod.x == player.x) && (bod.y == player.y));

        return bod;
    }
}

int main()
{
    char znak;

    Poloha player = { 10,5 };
    Poloha bod = { 10, 5 };

    int sirka = 20;
    int vyska = 10;


    while (true)
    {
        if (_kbhit())
        {
            znak = _getch();

            if (static_cast<int>(znak) == 27)
            {
                break;
            }

            player = Pohyb_hrace(player, znak);

            player = Hlidej_kraje(player, vyska, sirka);

        }

        bod = Generator_bodu(player, bod, vyska, sirka, velikost_hada);

        Draw(sirka, vyska, player, bod);
        Sleep(100);
        system("cls");
    }
}