#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vektor;

    for (int i = 0; i < 10; i++)
    {
        vektor.push_back(i);
    }

    cout << "Velikost: " << vektor.size() << "\n";

    cout << "Posledni prvek: " << vektor.back() << "\n";

    cout << "Prvni prvek: " << vektor.front() << "\n";

    cout << "Jakykoliv prvek: " << vektor.at(4) << "\n";

    for (int i = 0; i < vektor.size(); i++)
    {
        cout << vektor.at(i) << "  ";
        //cout << vektor[i] << "   ";
    }

    cout << "\n";

    while(!vektor.empty())
    {
        cout << vektor.back() << "\n";
        vektor.pop_back();
    }

}