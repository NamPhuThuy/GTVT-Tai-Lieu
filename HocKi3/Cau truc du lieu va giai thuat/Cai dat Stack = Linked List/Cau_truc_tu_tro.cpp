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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// freopen("Output.txt", "w", stdout);
// freopen("Error.txt", "w", stderr);

struct human
{
    string name;
    int age;
    struct human *bo, *me;

    human(string name = "Unknown", int age = 18)
    {
        name = name;
        age = age;
        bo = me = NULL;
    }
};

void sol()
{

}

int main()
{
	//qsort(arr, num, sizeof(int), LowerToGreater);
	//qsort(Arr, n, sizeof(ll), LowerToGreater);
 	human X("Chi Pheo", 13), Y("Thi No"), *Z = new human("Ba Kien", 23);
    cout << "cat\n";
    Z->bo = &X;
    Z->me = &Y;
    cout << X.name << endl;
    cout << Z->bo->name;
    delete Z;
}
