#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vek;

    for (int i = 0; i < 10; i++)
    {
        vek.push_back(i);
    }

    cout << "Velikost: " << vek.size() << "\n";

    cout << "Posledni prvek: " << vek.back() << "\n";

    cout << "Prvni prvek: " << vek.front() << "\n";

    cout << "Jakykoliv prvek: " << vek.at(4) << "\n";

    for (int i = 0; i < vek.size(); i++)
    {
        cout << vek.at(i) << "  ";
        //cout << vek[i] << "   ";
    }

    cout << "\n";

    while(!vek.empty())
    {
        cout << vek.back() << "  ";
        vek.pop_back();
    }

}