#include "Fraction.h" 	
using namespace std;

// Constructors / Destructors
Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(ll numerator, ll denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::~Fraction()
{

}

long long Fraction::getDenominator() { return this->denominator; }
void Fraction::setDenominator(ll value) { this->denominator = value; }

long long Fraction::getNumerator() { return this->numerator; }
void Fraction::setNumerator(ll value) { this->numerator = value; }

// Overloading Operators
    // Binary operators
        //Normal operators
Fraction Fraction::operator + (Fraction& a)
{
    Fraction ans;
    ans.setNumerator(this->numerator * a.getDenominator() + a.getNumerator() * this->denominator);
    ans.setDenominator(this->denominator * a.getDenominator());
    ans.Simplify();
    return ans;
}

Fraction Fraction::operator - (Fraction& a)
{
    Fraction ans;
    ans.setNumerator(this->numerator * a.getDenominator() - a.getNumerator() * this->denominator);
    ans.setDenominator(this->denominator * a.getDenominator());
    ans.Simplify();
    return ans;
}

Fraction Fraction::operator * (Fraction& a)
{
    Fraction ans;
    ans.setNumerator(this->numerator * a.getNumerator());
    ans.setDenominator(this->denominator * a.getDenominator());
    ans.Simplify();
    return ans;
}

Fraction Fraction::operator / (Fraction& a)
{
    Fraction ans;
    ans.setNumerator(this->numerator * a.getDenominator());
    ans.setDenominator(this->denominator * a.getNumerator());
    ans.Simplify();
    return ans;
}

// Comparison operators

bool Fraction::operator > (Fraction& a)
{
    Fraction tmp;
    tmp.setDenominator(this->getDenominator());
    tmp.setNumerator(this->getNumerator());

    Reduce(tmp, a);

    if (tmp.getNumerator() > a.getNumerator()) return true;
    return false;
}

bool Fraction::operator >= (Fraction& a)
{
    Fraction tmp;
    tmp.setDenominator(this->getDenominator());
    tmp.setNumerator(this->getNumerator());

    Reduce(tmp, a);

    if (tmp.getNumerator() >= a.getNumerator()) return true;
    return false;
}

bool Fraction::operator < (Fraction& a)
{
    Fraction tmp;
    tmp.setDenominator(this->getDenominator());
    tmp.setNumerator(this->getNumerator());

    Reduce(tmp, a);

    if (tmp.getNumerator() < a.getNumerator()) return true;
    return false;
}

bool Fraction::operator <= (Fraction& a)
{
    Fraction tmp;
    tmp.setDenominator(this->getDenominator());
    tmp.setNumerator(this->getNumerator());

    Reduce(tmp, a);

    if (tmp.getNumerator() <= a.getNumerator()) return true;
    return false;
}

// Unary operators
    //Prefix
Fraction Fraction::operator - ()
{
    Fraction ans;
    ans.setDenominator(-this->getDenominator());
    ans.setNumerator(this->getNumerator());
    return ans;
}

Fraction Fraction::operator ++()
{
    Fraction ans;
    ans.setDenominator(this->getDenominator());
    ans.setNumerator(this->getNumerator() + this->getDenominator());
    return ans;
}

Fraction Fraction::operator --()
{
    Fraction ans;
    ans.setDenominator(this->getDenominator());
    ans.setNumerator(this->getNumerator() - this->getDenominator());
    return ans;
}

//Suffix
Fraction Fraction::operator ++(int)
{
    Fraction ans;
    ans.setDenominator(this->getDenominator());
    ans.setNumerator(this->getNumerator() + this->getDenominator());
    return ans;
}

Fraction Fraction::operator --(int)
{
    Fraction ans;
    ans.setDenominator(this->getDenominator());
    ans.setNumerator(this->getNumerator() - this->getDenominator());
    return ans;
}

//Functions
long long Fraction::GCD(long long a, long long b)
{
    long long r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void Fraction::Simplify()
{
    ll tmp = GCD(this->getDenominator(), this->getNumerator());
    this->setDenominator(this->getDenominator() / tmp);
    this->setNumerator(this->getNumerator() / tmp);
}

void Fraction::Reduce(Fraction& a, Fraction& b)
{
    Fraction tmp = a, tmp2 = b;
    a.setNumerator(tmp.getNumerator() * tmp2.getDenominator());
    a.setDenominator(tmp.getDenominator() * tmp2.getDenominator());

    b.setNumerator(tmp2.getNumerator() * tmp.getDenominator());
    b.setDenominator(tmp2.getDenominator() * tmp.getDenominator());
}






