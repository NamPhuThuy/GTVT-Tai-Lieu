#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <ull, ull> pull;

const ll MOD = 1e9+7;
const ll MAX = 1e6;

class Shoes
{
private:
    string shoesCode, origin, type;
    double height, price;

public:
	Shoes(){};
    Shoes(string shoesCode, double height, string origin, double price)
    : shoesCode(shoesCode), height(height), origin(origin), price(price)
    {};

    //Getters / Setters
    string getOrigin(){return this->origin;}
    double getPrice(){return this->price;}

    friend istream& operator >> (istream& input, Shoes& a);
    friend ostream& operator << (ostream& output, Shoes& a);
};

istream& operator >> (istream& input, Shoes& a)
{
    cout << "insert shoesCode: "; input >> a.shoesCode;
    cout << "insert origin: "; input >> a.origin;
    cout << "insert height: "; input >> a.height;
    cout << "insert price: "; input >> a.price;

    return input;
}

ostream& operator << (ostream& output, Shoes& a)
{
    cout << "\nShoes's information: ";
    output << a.shoesCode << " " << a.origin << " " << a.height << " " << a.price;
    return output;
}

class Func
{
    private:
        Shoes *shoesList;
        ll numOfShoes;

    public:
        friend istream& operator >> (istream& input, Func& a);
        friend ostream& operator << (ostream& output, Func& a);
};

istream& operator >> (istream& input, Func& a)
{
    cout << "insert number of shoes: "; input >> a.numOfShoes;
    a.shoesList = new Shoes[a.numOfShoes];

    for (ll i = 0; i < a.numOfShoes; i++)
    {
        cout << "insert the " << i + 1 << "-th shoes's information: \n\n";
        input >> a.shoesList[i];
    }

    return input;
}

ostream& operator << (ostream& output, Func& a)
{
    for (ll i = 0; i < a.numOfShoes; i++) output << a.shoesList[i];
    return output;
}

int main()
{
    Func a;
    cin >> a; cout << a;
    
    
}

