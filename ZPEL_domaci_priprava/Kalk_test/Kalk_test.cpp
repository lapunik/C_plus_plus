#include <iostream>

using namespace std;

int main()
{
    int a, b;
    char c;
    while (true)
    {

        cout << "Zadej hodnotu 1: " << endl;

        cin >> a;

        cout << "Zadej hodnotu 2: " << endl;

        cin >> b;

        while (true)
        {
            cout << "Zadej operaci (+,-,*,/,): " << endl;

            cin >> c;
            switch (c)
            {
            case '+':
                cout << "Vysledek " << a + b << endl;
                break;
            case '-':
                cout << "Vysledek " << a - b << endl;
                break;
            case '*':
                cout << "Vysledek " << a * b << endl;
                break;
            case '/':
                if (b == 0)
                {
                    cout << "Nulou nelze delit " << endl;
                    break;
                }
                else
                {
                    cout << a / b << endl;
                    cout << "Zbytek po celociselnem deleni: " << a % b << endl;
                    break;
                }

            default:
                cout << "Neznam operaci" << endl;
                continue;

            }
            break;
        }

        {

            cout << "Dalsi vypocet? ((n)e), ((a)no)" << endl;
            char d;
            cin >> d;

            if (d == 'n')
            {

                cout << "Konec" << endl;
                break;

            }
        }
    }
    return 0;
}