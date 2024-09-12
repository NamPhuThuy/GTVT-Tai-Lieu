#include <iostream>
#include "Fraction.h"

typedef long long ll;
using namespace std;

//iostream
istream& operator >> (istream& input, Fraction& a)
{
    double x, y;
    input >> x >> y;
    a.setNumerator(x);
    a.setDenominator(y);
    return input;
}

ostream& operator << (ostream& output, Fraction& a)
{
    if (a.getDenominator() < 0 && a.getNumerator() >= 0)
    {
        a.setDenominator(-a.getDenominator());
        a.setNumerator(-a.getNumerator());
    }
    cout << a.getNumerator() << "/" << a.getDenominator();
    return output;
}

int main()
{
    Fraction a, b;
    cout << "Insert 1st fraction: "; cin >> a;
    cout << "Insert 2nd fraction: "; cin >> b;

    Fraction c = a + b;
    cout << "\nSum = " << c;

    c = a - b;
    cout << "\nSubtract = " << c;

    c = a * b;
    cout << "\nMultiply = " << c;

    c = a / b;
    cout << "\nDivide = " << c;

    c = -a;
    cout << "\nOpposite num = " << c;

    cout << endl << (a > b) << endl;
    cout << (a < b) << endl;
}
