#include <iostream>

using namespace std;

// 
// Gif:         https://upload.wikimedia.org/wikipedia/commons/6/60/Tower_of_Hanoi_4.gif
// Popř. video  https://www.youtube.com/watch?v=EkjucFnNZoA&ab_channel=zsvrchlickeho
// 
// 
// Pravidla:
// 
// 1. Z původní věže přendat všechny kotouče na cílovou věž
// 2. Nelze odložit větší kotouč na menší
// 3. V každém tahu lze přemístit právě jeden kotouč
// 
// 
// vždycky si jakoby skládám co největší věž dokážu, abych si uvolnil co největší kotouč, a mohl ho použít pro postavení větší pomocné věže (pokud je to nějvětší kotouč, tak pro finální věž)
void Hanojske_veze(int n, char z, char na, char pomocna)
{
    if (n == 1)
    {
        cout << "Presun kotouc 1 z veze " << z << " na vez " << na << "\n";

        return;
    }

    Hanojske_veze(n - 1, z, pomocna, na); // Tady se jakoby střídá pomocná a poslendí věž kam odkládám menší kotouče, abych si udělal místo na větší kotouč

    cout << "Presun kotouc " << n << " z veze " << z << " na vez " << na <<  "\n";

    Hanojske_veze(n - 1, pomocna, na, z); // Tady se pak jakoby rozebírá pomocně vyrobená věž 
}

int Faktorial_rekurzivne(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * Faktorial_rekurzivne(n - 1);
    }
}

int Faktorial(int n) 
{

    int faktorial = 1;

    for (int i = 2; i <= n; i++) 
    {
        faktorial *= i;
    }

    return faktorial;
}

int main()
{

    //cout << Faktorial(5) << "\n";

    //cout << Faktorial_rekurzivne(5) << "\n";

    //Hanojske_veze(4, 'A', 'B', 'C');

}