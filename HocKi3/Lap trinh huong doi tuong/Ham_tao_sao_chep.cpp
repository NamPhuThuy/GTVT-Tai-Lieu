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

        A (const A& tmp)
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
	//qsort(arr, num, sizeof(int), LowerToGreater);
	//qsort(Arr, n, sizeof(ll), LowerToGreater);
 	// freopen("Input.txt", "r", stdin);
	std::ios::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
	long long t; t = 1;
	for (long long ca = 1; ca <= t; ca++)
	{
		// std::cout << "Case #" << ca << ": ";
		sol();
	}
}
