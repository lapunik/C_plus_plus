// Kalkulačka.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
using namespace std;


int main()
{
label1:
    cout << "Ahoj ja jsem kalkulacka, zadej prvni hodnotu: \n";
    float cislo1;
    cin >> cislo1;



    cout << "Zadej druhou hodnotu: \n";
    float cislo2;
    cin >> cislo2;

    cout << "Zadej operator: +, -, *, /: \n";
    char op;
label2:
    cin >> op;

    switch (op)
    {
    case '+':
        cout << cislo1 << " + " << cislo2 << " = " << cislo1 + cislo2 << "\n";
        break;
    case '-':
        cout << cislo1 << " - " << cislo2 << " = " << cislo1 - cislo2 << "\n";
        break;
    case '*':
        cout << cislo1 << " * " << cislo2 << " = " << cislo1 * cislo2 << "\n";
        break;
    case '/':
        if (cislo2 == 0)
        {
            cout << "Nelze delit nulou \n";
            cout << "Zadej cislo znovu \n";
            goto label2;
        }
        else
        {
            cout << cislo1 << " / " << cislo2 << " = " << cislo1 / cislo2 << "\n";
        }
        break;

    default:

        cout << "Error! neznamm operaci \n";
        cout << "Zadej znak znovu \n";
        goto label2;

    }

    cout << "Dalsi vypocet? Pro ano napis a, pro ne napis n: \n";
    string odpoved;
label3:
    cin >> odpoved;
    if (odpoved == "a")
    {
        goto label1;
    }
    else if (odpoved != "n" && odpoved != "a")
    {
        cout << "Pro ano napis A, pro ne napis N, nic jineho: \n";
        goto label3;
    }

}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.

