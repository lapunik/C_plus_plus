#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <chrono>


typedef double (*function)(double);

double id(double x)
{
    return x;
}

double pow2(double x)
{
    return x * x;
}

double pow3(double x)
{
    return x * x * x;
}

double mse(std::vector<double> y0, std::vector<double> y1)
{
    std::vector<double> E(y0.size());

    std::transform(y0.begin(), y0.end(), y1.begin(), E.begin(), [](double& a, double& b) { return std::pow(a - b, 2); });

    return std::accumulate(E.begin(), E.end(), 0.0) / E.size();
}

double calculate(function f, double x)
{
    return f(x);
}

double calculate(std::vector<function> functions, double x)
{
    int i = 0;
    for (auto element : functions)
    {
        x = calculate(element, x);
        i++;
    }

    return x;
}

std::vector<double> calculate(function f, std::vector<double> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = calculate(f, x.at(i));
    }

    return x;
}

std::vector<double> calculate(std::vector<function> functions, std::vector<double> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = calculate(functions, x.at(i));
    }

    return x;
}

std::vector<double> calculate(std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef)
{
    std::vector<std::vector<std::vector<double>>> results(net.size() + 1);

    results.at(0).resize(1); // jedna, protože jeden vstup, kdybych chtěl více vstupů, musím to zde změnit
    results.at(0).at(0) = x;

    double w;
    double b;

    std::vector<double> im_results;

    //kam:        results.at(l + 1).at(nl2)
    //z:          results.at(l).at(nl1)
    //funkce:     net.at(l).at(nl2)
    //w:          koef.at(0).at(l).at((nl2 * results.at(l).size()) + nl1)
    //b:          koef.at(1).at(l).at(nl2))

    for (int l = 0; l < net.size(); l++)
    {
        results.at(l + 1).resize(net.at(l).size());

        for (int nl2 = 0; nl2 < results.at(l + 1).size(); nl2++) // projed celou naslednou verstvu
        {
            results.at(l + 1).at(nl2) = results.at(l).at(0);

            w = (koef.at(0).at(l).at((nl2 * results.at(l).size())));

            std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [w](double& c) { return c * w; });
            // vynásobení koefiicentem w

            for (int nl1 = 1; nl1 < results.at(l).size(); nl1++) // projet celou predchozi vrstvu
            {
                w = koef.at(0).at(l).at((nl2 * results.at(l).size()) + nl1);

                im_results = results.at(l).at(nl1);

                std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; });
                // vynásobení koefiicentem w

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), im_results.begin(), results.at(l + 1).at(nl2).begin(), std::plus<double>());

            }

            b = koef.at(1).at(l).at(nl2);

            std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
            // přičtení koeficientu b


            results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2));

        }
    }

    return results.at(results.size() - 1).at(0);
}

double derivate(function f, double x)
{
    return (calculate(f, x + 0.0000000000001) - calculate(f, x)) / 0.0000000000001;
}

double derivate(std::vector<function> functions, double x)
{
    return (calculate(functions, x + 0.0000000000001) - calculate(functions, x)) / 0.0000000000001;
}

std::vector<double> derivate(function f, std::vector<double> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(f, x.at(i));
    }

    return x;
}

std::vector<double> derivate(std::vector<function> functions, std::vector<double> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(functions, x.at(i));
    }

    return x;
}

std::vector<double> partial_derivate(std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n)
{

    double h = 0.0000000000001;

    std::vector<double> y = calculate(x, net, koef);

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    std::vector<double> y_h = calculate(x, net, koef);

    std::transform(y_h.begin(), y_h.end(), y.begin(), y_h.begin(), [h](double& a, double& b) { return pow2(a - b) / h; });

    return y_h;
}

double derivate_mse(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n)
{
    double e = mse(y0, calculate(x, net, koef));

    double h = 0.0000000000001;

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    double e_h = mse(y0, calculate(x, net, koef));

    return -((e_h - e) / h);
}

std::vector<double> generate(double min, double max, int N)
{
    std::vector<double> x;
    double r;
    for (int i = 0; i <= N; i++)
    {
        r = (((max - min) / static_cast<double>(N)) * static_cast<double>(i)) + min;

        x.push_back(r);
    }

    return x;
}

int discretize(double y, int q, int Q, double min, double max)
{
    Q = Q - 1;

    if ((y < (((max - min) / static_cast<double>(Q)) * static_cast<double>(q)) + min) || ((q == Q)))
    {
        return Q - q;
    }
    else
    {
        q++;
        return discretize(y, q, Q + 1, min, max);
    }
};

std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net, double w_val, double b_val)
{

    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    for (int n = 0; n < net.at(0).size(); n++)
    {
        w.at(0).push_back((w_val));
    }

    for (int l = 0; l < net.size(); l++)
    {
        for (int n = 0; n < net.at(l).size(); n++)
        {
            b.at(l).push_back(b_val);
        }

        if (l != net.size() - 1)
        {
            for (int n = 0; n < net.at(l).size() * net.at(l + 1).size(); n++)
            {
                w.at(l + 1).push_back(w_val);
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w, b};
}

void plot(std::vector<double> y, int Q)
{
    double max_y = *std::max_element(y.begin(), y.end());
    double min_y = *std::min_element(y.begin(), y.end());

    std::vector<int> data;

    for (auto element : y)
    {
        data.push_back(discretize(element, 0, Q, min_y, max_y));
    }

    std::cout << max_y << "\n";

    for (int i = 0; i < Q; i++)
    {
        for (auto j : data)
        {
            if (j == i)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }

        std::cout << "\n";

    }

    std::cout << min_y << "\n";
}

void plot(std::vector<double> x, std::vector<double> y, int Q)
{
    plot(y, Q);

    std::cout << "\n" << x.at(0);

    for (int i = 0; i < x.size() - 2; i++)
    {
        std::cout << " ";
    }

    std::cout << x.at(x.size() - 1) << "\n\n";

}

void plot(std::vector<std::vector<double>> y, int Q)
{

    double max_y = *std::max_element(y.at(0).begin(), y.at(0).end());
    double min_y = *std::min_element(y.at(0).begin(), y.at(0).end());

    for (int i = 1; i < y.size(); i++)
    {
        double max = *std::max_element(y.at(i).begin(), y.at(i).end());
        double min = *std::min_element(y.at(i).begin(), y.at(i).end());

        if (max > max_y)
        {
            max_y = max;
        }

        if (min < min_y)
        {
            min_y = min;
        }
    }

    std::vector<std::vector<int>> data(y.size());

    for (int j = 0; j < y.size(); j++)
    {
        for (int i = 0; i < y.at(j).size(); i++)
        {
            data.at(j).push_back(discretize(y.at(j).at(i), 0, Q, min_y, max_y));

        }
    }

    std::cout << max_y << "\n";

    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < y.at(0).size(); j++)
        {
            char c = ' ';

            for (int k = 0; k < y.size(); k++)
            {

                if (data.at(k).at(j) == i)
                {
                    c = 49 + k;
                }
            }

            std::cout << c;
        }

        std::cout << "\n";
    }

    std::cout << min_y << "\n";

}

void plot(std::vector<double> x, std::vector<std::vector<double>> y, int Q)
{
    plot(y, Q);

    std::cout << "\n" << x.at(0);

    for (int i = 0; i < x.size() - 2; i++)
    {
        std::cout << " ";
    }

    std::cout << x.at(x.size() - 1) << "\n\n";

}

void print(std::vector<double> x, std::vector<double> y)
{
    for (int i = 0; i < x.size(); i++)
    {
        std::cout << "x: " << x.at(i) << "\ty: " << y.at(i) << "\n";
    }
}

void print_koef(std::vector<std::vector<std::vector<double>>> koef)
{
    std::cout << "\nKoeficienty:\n";

    for (int wb = 0; wb < koef.size(); wb++)
    {
        for (int l = 0; l < koef.at(wb).size(); l++)
        {
            for (int n = 0; n < koef.at(wb).at(l).size(); n++) // projed celou naslednou verstvu
            {
                std::cout << koef.at(wb).at(l).at(n) << "\n";
            }
        }
    }

}

void print(std::vector<double> x, std::vector<std::vector<double>> y)
{
    for (int i = 0; i < x.size(); i++)
    {
        std::cout << "x: " << x.at(i);

        for (int j = 0; j < y.size(); j++)
        {
            std::cout << "\t\ty" << j << ": " << y.at(j).at(i);
        }

        std::cout << "\n";

    }
}

int main()
{
    std::vector<double> x = generate(-2.0, 2.0, 30);

    std::vector<std::vector<function>> net =
    {
        {pow2}
    };

    std::vector<std::vector<std::vector<double>>> koef = initialize_koeficients(net, 0.0, 0.0);

    koef.at(0).at(0).at(0) = 2.0, koef.at(1).at(0).at(0) = 1.0;
    std::vector<double> y0 = calculate(x, net, koef); // výpočet požadovaných hodnot, na které model fitujeme 

    plot(x, y0, 20);

    koef = initialize_koeficients(net, 1.0, 0.0);
    std::vector<double> y1 = calculate(x, net, koef); // výpočet modelu s počátečními koeficietny

    double alpha = 0.0001;
    double tau = 0.1;
    double d_koef = 0;
    double max_d_koef;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 500; i++)
    {
        max_d_koef = 100;

        for (int wb = 0; wb < koef.size(); wb++)
        {
            for (int l = 0; l < koef.at(wb).size(); l++)
            {
                for (int n = 0; n < koef.at(wb).at(l).size(); n++) // projed celou naslednou verstvu
                {

                    d_koef = derivate_mse(y0, x, net, koef, 0, 0, 0);

                    koef.at(wb).at(l).at(n) = koef.at(wb).at(l).at(n) + (d_koef * alpha);

                    if (std::abs(max_d_koef) < std::abs(d_koef))
                    {
                        max_d_koef = d_koef;
                    }

                }
            }
        }

        if (std::abs(d_koef) < tau)
        {
            break;
        }

    }

    auto stop = std::chrono::high_resolution_clock::now();

    y1 = calculate(x, net, koef);
    plot(x, y1, 20);

    print_koef(koef);

    std::cout << "\n\nIt took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms.\n\n";

}