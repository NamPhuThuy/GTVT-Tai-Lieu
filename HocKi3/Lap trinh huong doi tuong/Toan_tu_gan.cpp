#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class A
{
    ll a, *a1;
    public:
        A(ll x = 1, ll y = 2)
        {
            a = x;
            a1 = new ll;
            (*a1) = y;
        }

        void operator = (const A& tmp)
        {
            a = tmp.a;
            a1 = new ll;
            *a1 = *(tmp.a1);
        }

        void change()
        {
            a += 12;
            *a1 = 1000;
        }

        void print()
        {
            cout << a << " " << *a1 << "\n";
        }
};

void sol()
{
	A x(9, 9), x1;
    x1 = x;
    x.change();

    x.print();
    x1.print();
}	

int main()
{
	sol();
}
