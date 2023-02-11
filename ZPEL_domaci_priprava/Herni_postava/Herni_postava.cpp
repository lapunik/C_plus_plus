#include <iostream>
#include <random>

enum rasa_e
{
    clovek,
    elf,
    trpaslik,
    skret,
    maia,
};

class Zbroj
{
public:
    std::string nazev;
    int durabilita;

    Zbroj()
    {

    }

    Zbroj(std::string nazev_v, int poskozeni_v)
    {
        nazev = nazev_v;
        durabilita = poskozeni_v;
    }
};

class Zbran
{
public:

    std::string nazev;
    int poskozeni;

    Zbran()
    {

    }

    Zbran(std::string nazev_v, int poskozeni_v)
    {
        nazev = nazev_v;
        poskozeni = poskozeni_v;
    }

};

class Postava
{
private:
    
    int max_zivotu;
    Zbran zbran;
    Zbroj zbroj;


    int nahodna_hodnota(int min, int max)
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(min, max);

        return distr(gen);
    }

public:
    std::string jmeno;
    rasa_e rasa;
    int pocet_zivotu;

    Postava(std::string jmeno_v, rasa_e rasa_v, int max_pocet_zivotu = 100)
    {
        jmeno = jmeno_v;
        rasa = rasa_v;
        max_zivotu = max_pocet_zivotu;
        pocet_zivotu = max_zivotu;
    }

    void predstav_se()
    {
        std::cout << "Ahoj, ja jsem " << jmeno << ".\n";
    }

    //void zdravotni_stav()
    //{
    //    std::cout << jmeno << " ma " << pocet_zivotu << " zivotu.\n";
    //}

    void zdravotni_stav()
    {
        std::cout << jmeno << ": ";
        for (int i = 0; i < 20; i++)
        {
            std::cout << ((static_cast<double>(i) > (20.0 * (static_cast<double>(pocet_zivotu) / static_cast<double>(max_zivotu)))) ? static_cast<char>(176) : static_cast<char>(219));
        }
        std::cout << "\n";
    }

    void uzdrav_se()
    {
        pocet_zivotu += 10;

        if (pocet_zivotu > max_zivotu)
        {
            pocet_zivotu = max_zivotu;
        }

        std::cout << jmeno << " se leci za 10 bodu zivotu.\n";
    }

    void utok(Postava& protivnik)
    {

        int poskozeni = zbran.poskozeni + nahodna_hodnota(-10, 10);

        std::cout << jmeno << " utoci na " << protivnik.jmeno << " za " << poskozeni << " bodu poskozeni" << ".\n";

        //protivnik.pocet_zivotu -= 20;

        protivnik.obrana(poskozeni);
    }

    void obrana(int poskozeni)
    {
        poskozeni -= zbroj.durabilita + nahodna_hodnota(-5, 5);

        if (poskozeni < 0)
        {
            std::cout << jmeno << " odvratil utok.\n";
        }
        else
        {

            pocet_zivotu -= poskozeni;

            std::cout << jmeno << " dostava poskozeni za " << poskozeni << " bodu.\n";

            if (pocet_zivotu < 1)
            {
                std::cout << "\n" << jmeno << " umira!\n";
            }

        }
    }
    
    void vyzbroj_se(Zbran zbran_v, Zbroj zbroj_v)
    {
        zbran = zbran_v;
        zbroj = zbroj_v;
    }

    void vyhra(int kolo) 
    {
        std::cout << jmeno << " vitezi v " << kolo << ". kole\n";
    }

};

int main()
{
    //Postava p1;
    //p1.jmeno = "Legolas";
    //p1.rasa = "elf";


    Postava p1("Legolas", elf);
    Zbran luk("Elfsky luk", 20);
    Zbroj platova_zbroj("Elfska platova zbroj", 14);
    p1.vyzbroj_se(luk, platova_zbroj);
    p1.predstav_se();
    p1.zdravotni_stav();
    Postava p2("Saruman", maia, 150);
    Zbran hul("Magicka hul", 25);
    Zbroj habit("Magicky habit", 5);
    p2.vyzbroj_se(hul, habit);
    p2.predstav_se();
    p2.zdravotni_stav();


    std::cout << "\nSouboj zacina!\n";
    int pocitadlo = 1;
    while (true)
    {

        while (std::cin.get() != '\n') {};

        std::cout << "Kolo " << pocitadlo << ".\n";
        p1.utok(p2);
        p2.zdravotni_stav();
        if (p2.pocet_zivotu < 1)
        {
            p1.vyhra(pocitadlo);
            p1.zdravotni_stav();
            break;
        }

        p2.utok(p1);
        p1.zdravotni_stav();
        if (p1.pocet_zivotu < 1)
        {
            p2.vyhra(pocitadlo);
            p2.zdravotni_stav();
            break;
        }
        pocitadlo++;
    }

    /// mizení konzole

    /// rozhodovani (at si trochu zahrajeme)

    std::cout << "Konec hry!\n\n";

}