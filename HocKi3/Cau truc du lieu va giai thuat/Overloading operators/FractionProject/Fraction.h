#pragma once

#include <iostream>
typedef long long ll;

class Fraction
{
private:
    ll denominator, numerator; //mau so, tu so

public:
    // Constructors / Destructor
    Fraction();
    Fraction(ll denominator, ll numerator);
    ~Fraction();

    // Getters / Setters
    ll getDenominator();
    void setDenominator(ll value);

    ll getNumerator();
    void setNumerator(ll value);

    // Overloading operators
        // Binary operators
            //Normal operators
    Fraction operator + (Fraction& a);
    Fraction operator - (Fraction& a);
    Fraction operator * (Fraction& a);
    Fraction operator / (Fraction& a);

    // Comparison operators
    bool operator > (Fraction& a);
    bool operator >= (Fraction& a);
    bool operator < (Fraction& a);
    bool operator <= (Fraction& a);

    // Unery operators
        //Prefix operators
    Fraction operator - ();
    Fraction operator --();
    Fraction operator ++();

    // Suffix operators
    Fraction operator --(int);
    Fraction operator ++(int);

    //Functions
    void Simplify();
    void Reduce(Fraction& a, Fraction& b);
    long long GCD(long long a, long long b);
};

