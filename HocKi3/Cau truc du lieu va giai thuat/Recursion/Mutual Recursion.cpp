#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double Cos(double);
double Sin(double);

double Sin(double x)
{
    if (x < 1e-6) return x;
    return 2*Sin(x/2)*Cos(x/2);
}

double Cos(double x)
{
    if (abs(x) < 1e-6) return 1;
    double u = Cos(x/2), v = Sin(x/2);
    return u*u - v*v;
}

int main()
{
    // std::ios::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
    
    for (double x = -3; x <= 3; x += 0.2)
    {
        cout << "\nCos: " << Cos(x) << " " << cos(x);
        cout << "\nSin: " << Sin(x) << " " << sin(x);
    }
}
