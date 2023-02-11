#include <iostream>

class Euler
{
public:
    int n;
    double e;
    double vypocetCykly;
    double vypocetPresnost;
    double rozdily[2];

    Euler(int cykly, double presnost)
    {
        n = cykly;
        e = presnost;
    }

    int faktorial(int n) {
        int faktorial = 1;
        for (int i = 1; i <= n; i++) {
            faktorial *= i;
        }
        return faktorial;
    }

    void vypocetCykly() {
        double e1 = 0;
        for (int i = 0; i <= n; i++) {
            e1 += 1.0 / faktorial(i);
        }
        vypocetCykly = e1;
    }

    void vypocetPresnost() {
        double e2 = 0;
        int i = 0;
        double rozdil = 1;
        while (rozdil > this->e) {
            double pomE = e;
            e2 += 1.0 / faktorial(i);
            rozdil = e - pomE;
            i++;
        }
        vypocetPresnost = e;
    }

    void kontrola() {
        double e3 = 2.71828182845904523536;
        rozdily[0] = e3 - vypocetCykly;
        rozdily[1] = e3 - vypocetPresnost;
    }

    void vypisVysledky() {
        std::cout << "Eulerovo cislo spoctene pomoci " << n << " iteraci je e = " << vypocetCykly << std::endl;
        std::cout << "rozdil oproti referencni hodnote je " << rozdily[0] << std::endl;
        std::cout << "Eulerovo cislo spoctene s presnosti " << e << " je e = " << vypocetPresnost << std::endl;
        std::cout << "rozdil oproti referencni hodnote je " << rozdily[1] << std::endl;
    }
};
int main()
{
    int n = 8;
    double e = 1e-6;
    Euler euler(n, e);
    euler.vypocetCykly();
    euler.vypocetPresnost();
    euler.kontrola();
    euler.vypisVysledky();
}