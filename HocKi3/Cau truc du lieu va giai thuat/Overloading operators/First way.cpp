// #include<bits/stdc++.h>
#include <iostream>
#define endl '\n'

using namespace std;
typedef long long ll;

class Fraction
{
private:
    ll denominator, numerator; //mau so, tu so

public:
	// Constructors / Destructors
	Fraction()
	{
	    this->numerator = 0;
	    this->denominator = 0;
	}
	
	Fraction(ll numerator, ll denominator)
	{
	    this->numerator = numerator;
	    this->denominator = denominator;
	}
	
	~Fraction()	{}
	
	// Getters / Setters
	long long getDenominator() {return this->denominator;}
	void setDenominator(ll value) {this->denominator = value;}
	
	long long getNumerator() {return this->numerator;}
	void setNumerator(ll value) {this->numerator = value;}
	
	// Overloading Operators
	    // Binary operators
	        //Normal operators
	Fraction operator + (Fraction &a)
	{
	    Fraction ans;
	    ans.setNumerator(this->numerator * a.getDenominator() + a.getNumerator() * this->denominator);
	    ans.setDenominator(this->denominator * a.getDenominator());
	    ans.Simplify();
	    return ans;
	}
	
	Fraction operator - (Fraction &a)
	{
	    Fraction ans;
	    ans.setNumerator(this->numerator * a.getDenominator() - a.getNumerator() * this->denominator);
	    ans.setDenominator(this->denominator * a.getDenominator());
	    ans.Simplify();
	    return ans;
	}
	
	Fraction operator * (Fraction &a)
	{
	    Fraction ans;
	    ans.setNumerator(this->numerator * a.getNumerator());
	    ans.setDenominator(this->denominator * a.getDenominator());
	    ans.Simplify();
	    return ans;
	}
	
	Fraction operator / (Fraction &a)
	{
	    Fraction ans;
	    ans.setNumerator(this->numerator * a.getDenominator());
	    ans.setDenominator(this->denominator * a.getNumerator());
	    ans.Simplify();
	    return ans;
	}
	
	        // Comparison operators
	
	bool operator > ( Fraction& a)
	{
	    Fraction tmp;
	    tmp.setDenominator(this->getDenominator());
	    tmp.setNumerator(this->getNumerator());
	
	    Reduce(tmp, a);
	
	    if (tmp.getNumerator() > a.getNumerator()) return true;
	    return false;
	}
	
	bool operator >= ( Fraction& a)
	{
	    Fraction tmp;
	    tmp.setDenominator(this->getDenominator());
	    tmp.setNumerator(this->getNumerator());
	
	    Reduce(tmp, a);
	
	    if (tmp.getNumerator() >= a.getNumerator()) return true;
	    return false;
	}
	
	bool operator < (Fraction& a)
	{
	    Fraction tmp;
	    tmp.setDenominator(this->getDenominator());
	    tmp.setNumerator(this->getNumerator());
	
	    Reduce(tmp, a);
	
	    if (tmp.getNumerator() < a.getNumerator()) return true;
	    return false;
	}
	
	bool operator <= (Fraction& a)
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
	Fraction operator - ()
	{
	    Fraction ans;
	    if (this->getNumerator() != 0)
	    	ans.setNumerator(-this->getNumerator());
	    else ans.setNumerator(this->getNumerator());
	    
	    ans.setDenominator(this->getDenominator());
	    
	    if (ans.getDenominator() * ans.getNumerator() > 0 && ans.getDenominator() < 0)
	    {
	    	ans.setDenominator(-ans.getDenominator());
	    	ans.setNumerator(-ans.getNumerator());
		}
	    return ans;
	}
	
	Fraction operator ++()
	{
	    Fraction ans;
	    ans.setDenominator(this->getDenominator());
	    ans.setNumerator(this->getNumerator() + this->getDenominator());
	    return ans;
	}
	
	Fraction operator --()
	{
	    Fraction ans;
	    ans.setDenominator(this->getDenominator());
	    ans.setNumerator(this->getNumerator() - this->getDenominator());
	    return ans;
	}
	
	        //Suffix
	Fraction operator ++(int)
	{
	    Fraction ans;
	    ans.setDenominator(this->getDenominator());
	    ans.setNumerator(this->getNumerator() + this->getDenominator());
	    return ans;
	}
	
	Fraction operator --(int)
	{
	    Fraction ans;
	    ans.setDenominator(this->getDenominator());
	    ans.setNumerator(this->getNumerator() - this->getDenominator());
	    return ans;
	}
	
	//Functions
	void Simplify()
	{
	    ll tmp = std::__gcd(this->getDenominator(), this->getNumerator());
	    this->setDenominator(this->getDenominator() / tmp);
	    this->setNumerator(this->getNumerator() / tmp);
	}
	
	void Reduce( Fraction& a,  Fraction& b)
	{
	    Fraction tmp = a, tmp2 = b;
	    a.setNumerator(tmp.getNumerator() * tmp2.getDenominator()); 
	    a.setDenominator(tmp.getDenominator() * tmp2.getDenominator());
	
	    b.setNumerator(tmp2.getNumerator() * tmp.getDenominator());
	    b.setDenominator(tmp2.getDenominator() * tmp.getDenominator());
	}
};

int main()
{
	long long x1, x2, y1, y2;
    cout << "Insert 1st fraction: "; cin >> x1 >> y1;
    cout << "Insert 2nd fraction: "; cin >> x2 >> y2;
    
    cout << "\nFirst fraction: " << x1 << "/" << y1;
    cout << "\nSecond fraction: " << x2 << "/" << y2;

    Fraction a(x1, y1), b(x2, y2);
    
    Fraction c = a + b;
    cout << "\n\n	Sum = " << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = a - b;
    cout << "Subtract = " << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = a * b;
    cout << "Multiply = " << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = a / b;
    cout << "Divide = " << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = -a;
    cout << "Opposite of the 1st fraction = " << c.getNumerator() << "/" << c.getDenominator() << endl;

    cout << (a > b) << endl;
    cout << (a < b) << endl;
}

