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

struct node
{
    ll value;
    node *next;

    node(ll val = 0, node *n = NULL)
    {
        value = val;
        next = n;
    }
};

void sol()
{

}

int main()
{
    node E, D(7, &E), *C = new node(6, &D), *B = new node(4, C), A(8, B);
    for (node *p = &A; p != NULL; p = p->next) cout << p->value << " ";
    delete C;
    delete B;
	
}
