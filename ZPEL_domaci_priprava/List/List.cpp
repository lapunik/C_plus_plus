#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> seznam;

    for (int i = 0; i < 10; i++)
    {
        seznam.push_back(i);
    }

    cout << "Velikost: " << seznam.size() << "\n";

    cout << "Posledni prvek: " << seznam.back() << "\n";

    cout << "Prvni prvek: " << seznam.front() << "\n";

    cout << "\n";


    while (!seznam.empty())
    {
        //cout << seznam.front() << "\n";
        //seznam.pop_front();
        cout << seznam.back() << "\n";
        seznam.pop_back();

    }
    
}