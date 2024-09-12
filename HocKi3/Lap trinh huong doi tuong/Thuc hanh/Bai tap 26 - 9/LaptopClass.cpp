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

class Laptop
{
    private:
        string model, manufacturer;
        double price;
        ll warrantyPeriod;

    public:
        Laptop()
        {
            this->model = "";
            this->manufacturer = "";
            this->price = 0.0f;
            this->warrantyPeriod = 0;
        }

        Laptop(string model, string manufacturer, double price, long warrantyPeriod)
        {
            this->model = model;
            this->manufacturer = manufacturer;
            this->price = price;
            this->warrantyPeriod = warrantyPeriod;
        }

        double getPrice(){return this->price;}
        string getManufacturer(){return this->manufacturer;}

        friend istream& operator >> (istream& input, Laptop &a);
        friend ostream& operator <<(ostream& output, const Laptop &a);
};

istream& operator >> (istream& input, Laptop &a)
{
	
    cout << "insert laptop's model: "; input >> a.model;
    cout << "insert laptop's manufacturer: "; input >> a.manufacturer; 
    cout << "insert laptop's price: "; input >> a.price;
    cout << "insert laptop's warrantyPeriod: "; input >> a.warrantyPeriod;

    return input;
}

ostream& operator << (ostream& output, const Laptop &a)
{
    output << "\nlaptop's information: " << a.model << " " << a.manufacturer << " " << a.price << " " << a.warrantyPeriod;

    return output;
}

class Func
{
    public: 
        Laptop *arr;
        ll numOfLaps;

        

    // public:
        void Sort();
        void Search(double findingPrice, string findingManufacturer);
        friend istream& operator >> (istream&, Func&);
        friend ostream& operator << (istream&, const Func&);
};

void Func::Sort()
{
    for (int i = 0; i < this->numOfLaps - 1; i++)
    {
        for (int j = i + 1; j < this->numOfLaps; j++)
        {
            if (this->arr[i].getPrice() > this->arr[j].getPrice())
                swap(this->arr[i], this->arr[j]);
        }
    }
}

void Func::Search(double findingPrice, string findingManufacturer)
{
    for (int i = 0; i < this->numOfLaps; i++)
    {
        if (this->arr[i].getPrice() == findingPrice && this->arr[i].getManufacturer() == findingManufacturer)
        {
            cout << this->arr[i];
            return;
        }

        
    }
    cout << "\nCant find any laptop";
}

istream& operator >> (istream& input, Func& a)
{
    cout << "insert number of laptops: "; input >> a.numOfLaps;
    a.arr = new Laptop[a.numOfLaps];
    for (int i = 0; i < a.numOfLaps; i++)
    {
        cout << "insert the " << i + 1 << "-th laptop: \n";
        input >> a.arr[i];
    }

    return input;
}

ostream& operator << (ostream& output, const Func& a)
{
    for (int i = 0; i < a.numOfLaps; i++) output << a.arr[i];
    return output;
}

int main()
{

    Func a; cin >> a;
    a.Sort();
    cout << a;
	
	cout << "\ninsert price ";
    double price; cin >> price;
    
    cout << "\n insert manufacturer ";
    string manufacturer; cin >> manufacturer;

    a.Search(price, manufacturer);

}
