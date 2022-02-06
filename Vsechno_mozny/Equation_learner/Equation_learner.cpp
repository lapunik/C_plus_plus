#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <vector>


typedef double (*function)(double); 

template <class T>
double calculate(std::vector<T> functions, double x)
{
    for (auto element : functions)
    {
        x = element(x);
    }

    return x;
}

template <class T>
std::vector<double> calculate(std::vector<T> functions, std::vector<double> x)
{
    for (int i = 0;i < x.size();i++)
    {
        for (auto element : functions)
        {
            x.at(i) = element(x.at(i));
        }

    }

    return x;
}

template <class T>
double derivate(std::vector<T> functions, double x)
{
    double h = 0.0000000000001;

    return (calculate(functions, x+h) - calculate(functions, x))/h;

}

template <class T>
std::vector<double> derivate(std::vector<T> functions, std::vector<double> x)
{
    double h = 0.0000000000001;

    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = (calculate(functions, x.at(i) + h) - calculate(functions, x.at(i))) / h;
    }

    return x;
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

    if ( (y < (((max - min) / static_cast<double>(Q)) * static_cast<double>(q)) + min) || ((q == Q)))
    {
        return Q-q;
    }
    else
    {
        q++;
        return discretize(y, q, Q+1, min, max);
    } 
};

void plot(std::vector<double> y,int Q)
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

    std::cout << x.at(x.size()-1) << "\n";

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

    std::cout << x.at(x.size() - 1) << "\n";

}

void print(std::vector<double> x, std::vector<double> y)
{
    for (int i = 0; i <= 80; i++)
    {
        std::cout << "x: " << x.at(i) << "\ty: " << y.at(i) << "\n";
    }
}

void print(std::vector<double> x, std::vector<std::vector<double>> y)
{
    for (int i = 0; i < x.size(); i++)
    {
        std::cout << "x: " << x.at(i);
        
        for (int j = 0 ;j < y.size();j++) 
        {
            std::cout << "\t\ty" << j << ": " << y.at(j).at(i);
        }

        std::cout << "\n";
        
    }
}

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

int main()
{

    //std::vector<function> functions = {std::cos, std::sin, pow2};

    //std::vector<double> x = generate(0.0,2*M_PI,80);

    //std::vector<double> y = calculate(functions, x);
    //std::vector<double> dy = derivate(functions, x);

    //plot(x,{ y, dy}, 20);


    std::vector<double> y;
    std::vector<double> x;
    double r;
    for (int i = 0; i <= 80; i++)
    {
        x.push_back((((2*M_PI - 0.0) / static_cast<double>(80)) * static_cast<double>(i)) + 0.0);

        y.push_back(2 * calculate(std::vector<function>{std::sin, pow2}, x.back()) + 2);
    }

    plot(x,y,20);

}