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

class PhanSo
{
    int tu, mau;
    ps (int a = 0, int b = 1)
    {
        tu = a;
        mau = b;
    }

    ps (PhanSo &p)
    {
        cout << "Toan tu copy\n";
        tu = p.tu;
        mau = p.mau;
    }

    PhanSo operator& = (PhanSo &a)
    {
        cout << "Toan tu gan\n";
        tu = a.tu;
        mau = a.mau;
        return *this;
    }
}

//My Code
void sol()
{
    PhanSo A(3, 4);
    PhanSo B = A;
    PhanSo C;
    C = A;
}

int main()
{
	sol();
}
