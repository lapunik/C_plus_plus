#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "pbPlots.h"
#include "supportLib.h"


typedef double (*function)(double, double);

double id(double x, double x2)
{
    return x;
}

double pow2(double x, double x2)
{
    return x * x;
}

double pow3(double x, double x2)
{
    return x * x * x;
}

double pow4(double x, double x2)
{
    return x * x * x * x;
}

double times(double x, double x2)
{
    return x * x2;
}

double divide(double x, double x2)
{
    if (x2 <= 0.000000000000001)
    {
        return 0.0;
    }
    else
    {
        return x / x2;
    }


}

double sin(double x, double x2)
{
    return std::sin(x);
}

double cos(double x, double x2)
{
    return std::cos(x);
}

double sigmoid(double x, double x2)
{
    return (1 / (1 + exp(-x)));
}

double n_sigmoid(double x, double x2)
{
    return (2 / (1 + exp(-x))) - 1;
}

double tanh(double x, double x2)
{
    return std::tanh(x);
}

double f_sigmoid(double x, double x2)
{
    return (x / (1 + abs(x)));
}

double heaviside(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

double signum(double x, double x2)
{
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

double p_id(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else
    {
        return x;
    }
}

double sat(double x, double x2)
{
    if (x < -1)
    {
        return -1;
    }
    else if (x > 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}

double p_sat(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x > 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}

double rad(double x, double x2)
{
    return (1 / (std::pow(exp(1), pow2(x, 0))));
}

double mse(std::vector<double> y0, std::vector<double> y1)
{
    std::vector<double> E(y0.size());

    std::transform(y0.begin(), y0.end(), y1.begin(), E.begin(), [](double& a, double& b) { return std::pow(a - b, 2); });

    return std::accumulate(E.begin(), E.end(), 0.0) / E.size();
}

std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net, double w_val, double b_val)
{
    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    int num_of_inputs = 1; // pokud síť bude rozšiřována pro více vstupů, tak tady musí být jejich počet

    int net_size = net.at(0).size();

    for (int n = 0; n < net_size; n++)
    {
        try
        {
            if ((net.at(0).at(n) == times) || (net.at(0).at(n) == divide))
            {
                net_size = net_size + num_of_inputs;
            }
        }
        catch (...) {}

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

            net_size = net.at(l).size() * net.at(l + 1).size();


            for (int n = 0; n < net_size; n++)
            {
                try
                {
                    if ((net.at(l + 1).at(n) == times) || (net.at(l + 1).at(n) == divide))
                    {
                        net_size = net_size + net.at(l).size();
                    }
                }
                catch (...) {}

                w.at(l + 1).push_back(w_val);
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w, b};
}

std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net)
{
    return initialize_koeficients(net, 1.0, 1.0);
}

std::vector<std::vector<std::vector<double>>> initialize_random_koeficients(std::vector<std::vector<function>> net, double min, double max)
{
    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    int num_of_inputs = 1; // pokud síť bude rozšiřována pro více vstupů, tak tady musí být jejich počet

    int net_size = net.at(0).size();

    std::uniform_real_distribution<double> random(min, max);
    std::default_random_engine rng;

    for (int n = 0; n < net_size; n++)
    {
        try
        {
            if ((net.at(0).at(n) == times) || (net.at(0).at(n) == divide))
            {
                net_size = net_size + num_of_inputs;
            }
        }
        catch (...) {}

        w.at(0).push_back((random(rng)));
    }

    for (int l = 0; l < net.size(); l++)
    {

        for (int n = 0; n < net.at(l).size(); n++)
        {
            b.at(l).push_back(random(rng));
        }

        if (l != net.size() - 1)
        {

            net_size = net.at(l).size() * net.at(l + 1).size();


            for (int n = 0; n < net_size; n++)
            {
                try
                {
                    if ((net.at(l + 1).at(n) == times) || (net.at(l + 1).at(n) == divide))
                    {
                        net_size = net_size + net.at(l).size();
                    }
                }
                catch (...) {}

                w.at(l + 1).push_back(random(rng));
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w, b};
}

std::vector<std::vector<std::vector<double>>> initialize_random_koeficients(std::vector<std::vector<function>> net)
{
    return initialize_random_koeficients(net, 0.0, 0.1);
}

double calculate(function f, double x, double x2)
{
    return f(x, x2);
}

double calculate(std::vector<function> functions, double x, double x2)
{
    int i = 0;
    for (auto element : functions)
    {
        x = calculate(element, x, x2);
        i++;
    }

    return x;
}

std::vector<double> calculate(function f, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = calculate(f, x.at(i), x2.at(i));
    }

    return x;
}

std::vector<double> calculate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = calculate(functions, x.at(i), x2.at(i));
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

    int koef_shift = 0; // pokud mám funcki násobení nebo dělení, tak už nesedí velikost vektoru result s koef, to znamená že musím 
    std::vector<double> two_imput_results;


    //kam:        results.at(l + 1).at(nl2)
    //z:          results.at(l).at(nl1)
    //funkce:     net.at(l).at(nl2)
    //w:          koef.at(0).at(l).at((nl2 * results.at(l).size()) + nl1)
    //b:          koef.at(1).at(l).at(nl2))

    for (int l = 0; l < net.size(); l++)
    {
        results.at(l + 1).resize(net.at(l).size());

        koef_shift = 0;

        for (int nl2 = 0; nl2 < results.at(l + 1).size(); nl2++) // projed celou naslednou vrstvu 
        {
            results.at(l + 1).at(nl2) = results.at(l).at(0);

            w = (koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size())));

            std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [w](double& c) { return c * w; }); // první sčítanec
            // vynásobení koefiicentem w

            for (int nl1 = 1; nl1 < results.at(l).size(); nl1++) // projet celou predchozi vrstvu
            {
                w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                im_results = results.at(l).at(nl1);

                std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                // vynásobení koefiicentem w

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), im_results.begin(), results.at(l + 1).at(nl2).begin(), std::plus<double>());

            }

            if ((net.at(l).at(nl2) == times) || (net.at(l).at(nl2) == divide))
            {
                koef_shift++;

                two_imput_results = results.at(l).at(0);

                w = (koef.at(0).at(l).at((nl2 + koef_shift) * results.at(l).size()));

                std::transform(two_imput_results.begin(), two_imput_results.end(), two_imput_results.begin(), [w](double& c) { return c * w; }); // první sčítanec
                // vynásobení koefiicentem w

                for (int nl1 = 1; nl1 < results.at(l).size(); nl1++) // projet celou predchozi vrstvu
                {
                    w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                    im_results = results.at(l).at(nl1);

                    std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                    // vynásobení koefiicentem w

                    std::transform(two_imput_results.begin(), two_imput_results.end(), im_results.begin(), two_imput_results.begin(), std::plus<double>());

                }

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), two_imput_results);

                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

            }
            else
            {
                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), results.at(l + 1).at(nl2));
            }


        }
    }

    return results.at(results.size() - 1).at(0);
}

double derivate(function f, double x, double x2)
{
    return (calculate(f, x + 0.0000000000001, x2) - calculate(f, x, x2)) / 0.0000000000001;
}

double derivate(std::vector<function> functions, double x, double x2)
{
    return (calculate(functions, x + 0.0000000000001, x2) - calculate(functions, x, x2)) / 0.0000000000001;
}

std::vector<double> derivate(function f, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(f, x.at(i), x2.at(i));
    }

    return x;
}

std::vector<double> derivate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(functions, x.at(i), x2.at(i));
    }

    return x;
}

std::vector<double> partial_derivate(std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n)
{

    double h = 0.0000000000001;

    std::vector<double> y = calculate(x, net, koef);

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    std::vector<double> y_h = calculate(x, net, koef);

    std::transform(y_h.begin(), y_h.end(), y.begin(), y_h.begin(), [h](double& a, double& b) { return pow2(a - b, 0) / h; });

    return y_h;
}

double derivate_mse(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n)
{
    double e = mse(y0, calculate(x, net, koef));

    double h = 0.0000000000001;

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    double e_h = mse(y0, calculate(x, net, koef));

    return ((e_h - e) / h);
}

double derivate_mse(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n, double lambda)
{
    double koef_sum = 0;

    for (int k = 0; k < koef.size(); k++)
    {
        for (int j = 0; j < koef.at(k).size(); j++)
        {
            for (int i = 0; i < koef.at(k).at(j).size(); i++)
            {
                koef_sum += abs(koef.at(k).at(j).at(i));
            }
        }
    }

    double e = mse(y0, calculate(x, net, koef)) + lambda * koef_sum;

    double h = 0.0000000000001;

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    double e_h = mse(y0, calculate(x, net, koef)) + lambda * (koef_sum + h);

    if (e_h == 3.9629049796248412)
    {
        int a = 5;
    }

    return ((e_h - e) / h);
}

std::vector<std::vector<std::vector<double>>> batch_gradient_descent(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N)
{
    double d_koef = 0;
    double max_d_koef;

    for (int i = 0; i < N; i++)
    {
        max_d_koef = 0;

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

    return koef;
}

std::vector<std::vector<std::vector<double>>> batch_gradient_descent(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda)
{
    double d_koef = 0;
    double max_d_koef;

    for (int i = 0; i < N; i++)
    {
        max_d_koef = 0;

        for (int wb = 0; wb < koef.size(); wb++)
        {
            for (int l = 0; l < koef.at(wb).size(); l++)
            {
                for (int n = 0; n < koef.at(wb).at(l).size(); n++) // projed celou naslednou verstvu
                {

                    d_koef = derivate_mse(y0, x, net, koef, 0, 0, 0, lambda);

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

    return koef;
}

std::vector<std::vector<std::vector<double>>> stochastic_gradient_descent(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < x.size() * (1 - ratio); i++)
    {

        std::uniform_int_distribution<std::mt19937::result_type> random(0, x.size() - 1);

        int q = random(rng);

        x.erase(x.begin() + q);
        y0.erase(y0.begin() + q);

    }


    return batch_gradient_descent(y0, x, net, koef, alpha, tau, N);
}

std::vector<std::vector<std::vector<double>>> stochastic_gradient_descent(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda, double ratio)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < x.size() * (1 - ratio); i++)
    {

        std::uniform_int_distribution<std::mt19937::result_type> random(0, x.size() - 1);

        int q = random(rng);

        x.erase(x.begin() + q);
        y0.erase(y0.begin() + q);

    }


    return batch_gradient_descent(y0, x, net, koef, alpha, tau, N, lambda);
}

std::vector<std::vector<std::vector<double>>> ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N)
{

    double d_koef = 0;
    double max_d_koef;

    double epsilon = 10e-8;
    double beta1 = 0.9;
    double beta2 = 0.999;
    double beta1_1 = 1 - beta1;
    double beta2_1 = 1 - beta2;

    std::vector<std::vector<std::vector<double>>>  m = initialize_koeficients(net, 0.0, 0.0);
    std::vector<std::vector<std::vector<double>>>  v = initialize_koeficients(net, 0.0, 0.0);

    for (int i = 0; i < N; i++)
    {
        max_d_koef = 0;

        for (int wb = 0; wb < koef.size(); wb++)
        {
            for (int l = 0; l < koef.at(wb).size(); l++)
            {
                for (int n = 0; n < koef.at(wb).at(l).size(); n++) // projed celou naslednou verstvu
                {

                    d_koef = derivate_mse(y0, x, net, koef, wb, l, n);

                    m.at(wb).at(l).at(n) = (beta1 * m.at(wb).at(l).at(n)) + (beta1_1)*d_koef;
                    v.at(wb).at(l).at(n) = (beta2 * v.at(wb).at(l).at(n)) + ((beta2_1)*pow2(d_koef, 0));

                    koef.at(wb).at(l).at(n) = koef.at(wb).at(l).at(n) - ((alpha * m.at(wb).at(l).at(n) / (1 - pow(beta1, i + 1))) / (std::sqrt(v.at(wb).at(l).at(n) / (1 - pow(beta2, i + 1))) + epsilon));

                    if (std::abs(max_d_koef) < std::abs(d_koef))
                    {
                        max_d_koef = d_koef;
                    }

                }
            }
        }

        if (std::abs(max_d_koef) < tau)
        {
            break;
        }

    }

    return koef;
}

std::vector<std::vector<std::vector<double>>> ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda)
{

    double d_koef = 0;
    double max_d_koef;

    double epsilon = 10e-8;
    double beta1 = 0.9;
    double beta2 = 0.999;
    double beta1_1 = 1 - beta1;
    double beta2_1 = 1 - beta2;

    std::vector<std::vector<std::vector<double>>>  m = initialize_koeficients(net, 0.0, 0.0);
    std::vector<std::vector<std::vector<double>>>  v = initialize_koeficients(net, 0.0, 0.0);

    for (int i = 0; i < N; i++)
    {
        max_d_koef = 0;

        for (int wb = 0; wb < koef.size(); wb++)
        {
            for (int l = 0; l < koef.at(wb).size(); l++)
            {
                for (int n = 0; n < koef.at(wb).at(l).size(); n++) // projed celou naslednou verstvu
                {
                    d_koef = derivate_mse(y0, x, net, koef, wb, l, n, lambda);

                    m.at(wb).at(l).at(n) = (beta1 * m.at(wb).at(l).at(n)) + (beta1_1)*d_koef;
                    v.at(wb).at(l).at(n) = (beta2 * v.at(wb).at(l).at(n)) + ((beta2_1)*pow2(d_koef, 0));

                    koef.at(wb).at(l).at(n) = koef.at(wb).at(l).at(n) - ((alpha * m.at(wb).at(l).at(n) / (1 - pow(beta1, i + 1))) / (std::sqrt(v.at(wb).at(l).at(n) / (1 - pow(beta2, i + 1))) + epsilon));

                    if (std::abs(max_d_koef) < std::abs(d_koef))
                    {
                        max_d_koef = d_koef;
                    }

                }
            }
        }

        if (std::abs(max_d_koef) < tau)
        {
            break;
        }

    }

    return koef;
}

std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < x.size() * (1 - ratio); i++)
    {

        std::uniform_int_distribution<std::mt19937::result_type> random(0, x.size() - 1);

        int q = random(rng);

        x.erase(x.begin() + q);
        y0.erase(y0.begin() + q);

    }


    return ADAM(y0, x, net, koef, alpha, tau, N);
}

std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda, double ratio)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < x.size() * (1 - ratio); i++)
    {

        std::uniform_int_distribution<std::mt19937::result_type> random(0, x.size() - 1);

        int q = random(rng);

        x.erase(x.begin() + q);
        y0.erase(y0.begin() + q);

    }


    return ADAM(y0, x, net, koef, alpha, tau, N, lambda);
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

std::vector<double> noise_generate(std::vector<double> x, double sd)
{
    std::uniform_real_distribution<double> random(0.0, sd);
    std::default_random_engine rng;

    for (int i = 0; i < x.size(); i++)
    {
        if (random(rng) > sd / 2.0)
        {
            x.at(i) += random(rng);
        }
        else
        {
            x.at(i) -= random(rng);
        }
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

std::vector<int> change_color(std::vector<int> color)
{
    char c = (color.at(0)) | (color.at(1) << 1) | (color.at(2) << 2);
    c++;
    color.at(0) = c & 0x1 ? 1 : 0, color.at(1) = c & 0x2 ? 1 : 0, color.at(2) = c & 0x4 ? 1 : 0;

    return color;
}

void export_graph(std::vector<double> x, std::vector<double> y, int size_x, int size_y, std::string name)
{
    StringReference* errorMessage = new StringReference();
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    DrawScatterPlot(imageReference, size_x, size_y, &x, &y, errorMessage);

    WriteToFile(ConvertToPNG(imageReference->image), name);
    DeleteImage(imageReference->image);
}

void export_graph(std::vector<double> x, std::vector<std::vector<double>> y, int size_x, int size_y, std::string name)
{
    StringReference* errorMessage = new StringReference();
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    std::vector<ScatterPlotSeries*> series;

    std::vector<int> colors{ 0,0,0 };

    for (int i = 0; i < y.size(); i++)
    {
        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(i)->xs = &x;
        series.at(i)->ys = &y.at(i);
        series.at(i)->linearInterpolation = (i == 1 ? false : true);
        series.at(i)->pointType = (i == 1 ? toVector(L"circles") : toVector(L"dots"));
        //series.at(i)->lineThickness = 2;

        series.at(i)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);

    }

    ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
    settings->width = size_x;
    settings->height = size_y;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = toVector(L"");
    settings->xLabel = toVector(L"");
    settings->yLabel = toVector(L"");

    for (int i = 0; i < y.size(); i++)
    {
        settings->scatterPlotSeries->push_back(series.at(i));
    }

    DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    WriteToFile(ConvertToPNG(imageReference->image), name);
    DeleteImage(imageReference->image);

}

int main()
{

    std::string name{ "regularization_" };

    double alpha = 0.05;   // learning koeficient
    double tau = 0.001;     // toerance 
    int N = 10000;           // max number of interation


    std::vector<double> x = generate(0.5, 3.5, 200);

    std::vector<std::vector<function>> net =
    {
        {id, sin, times},
        {divide}
    };

    //std::vector<std::vector<function>> net =
    //{
    //    {id, sin},
    //    {id,times},
    //    {id}
    //};

    //std::vector<std::vector<function>> net =
    //{
    //    {pow2, sin},
    //    {pow2, sin},
    //    {id}
    //};

    //std::vector<std::vector<function>> net =
    //{
    //    {id, pow2},
    //    {id, pow2},
    //    {id}
    //};

    //std::vector<std::vector<function>> net =
    //{
    //    {pow2,pow3,pow4},
    //    {id}
    //};

    //std::vector<std::vector<function>> net =
    //{
    //    {pow2}
    //};

    std::vector<std::vector<std::vector<double>>> koef = initialize_koeficients(net, 1.0, 0.0);

    koef.at(0).at(0).at(0) = 0.0, koef.at(0).at(0).at(1) = M_PI, koef.at(0).at(1).at(0) = 0.0, koef.at(0).at(1).at(2) = 0.0, koef.at(0).at(1).at(3) = 0.0, koef.at(0).at(1).at(4) = 0.0;
    koef.at(1).at(0).at(2) = 1.0;

    //koef.at(0).at(0).at(1) = 5.0, koef.at(0).at(1).at(0) = 2.0, koef.at(0).at(1).at(3) = 0.0, koef.at(0).at(1).at(4) = 0.0, koef.at(0).at(2).at(1) = 1.0 / 3.0; // od nuly, do tří, 80 prvků, (0.5, 0.001, 1000)

    //koef.at(0).at(0).at(0) = -1.0, koef.at(0).at(0).at(1) = 1.0, koef.at(0).at(1).at(0) = 1.0, koef.at(0).at(1).at(1) = 1.0, koef.at(0).at(2).at(0) = 1.0, koef.at(0).at(2).at(1) = 1.0;
    //koef.at(1).at(0).at(0) = 2.0, koef.at(1).at(0).at(1) = -1.0;

    //koef.at(0).at(0).at(0) = 2.0, koef.at(0).at(1).at(2) = 1.0, koef.at(0).at(2).at(1) = 3.0, koef.at(1).at(0).at(0) = 1.0; koef.at(1).at(0).at(0) = 1.0;

    //koef.at(0).at(1).at(0) = 0.0, koef.at(0).at(1).at(1) = 3.0, koef.at(0).at(1).at(2) = 0.0;

    //koef.at(0).at(0).at(0) = 2.0, koef.at(1).at(0).at(0) = 1.0;

    std::vector<double> y0 = calculate(x, net, koef); // výpočet požadovaných hodnot, na které model fitujeme 
    y0 = noise_generate(y0, 0.05); // zanesení dat šumem
    plot(x, y0, 30);

    std::vector<double> regularization_range;

    for (double i = 0.00001; i <= 0.1; i *= 10)
    {
        regularization_range.push_back(i);
        //regularization_range.push_back(0.00001);
    }

    std::vector<double> MSE(regularization_range.size());

    for (int i = 0; i < regularization_range.size(); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        koef = batch_gradient_descent(y0, x, net, initialize_koeficients(net, 1.0, 1.0), alpha, tau, N, regularization_range.at(i));
        auto stop = std::chrono::high_resolution_clock::now();

        std::vector<double>  y1 = calculate(x, net, koef);


        MSE.at(i) = mse(y0, y1);

        plot(x, { y0, y1 }, 30);

        export_graph(x, { y1,y0 }, 1000, 750, name + std::to_string(regularization_range.at(i)) + ".png");

        print_koef(koef);

        std::cout << "\n\nIt took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms.\n\n";

    }


    std::transform(regularization_range.begin(), regularization_range.end(), regularization_range.begin(), [](double& c) { return std::log10(c); });

    export_graph(regularization_range, MSE, 1000, 750, "MSE_to_lambda.png");

}