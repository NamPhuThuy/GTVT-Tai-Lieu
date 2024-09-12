#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;
typedef vector <ll> vtl;
typedef pair <ull, ull> pull;
typedef pair <int, int> pii;
typedef vector <int> vti;

#define fi first
#define se second
#define pb push_back

const ll MOD = 1e9+7;
const ll MAX = 1e6;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// freopen("Output.txt", "w", stdout);
// freopen("Error.txt", "w", stderr);

template <class T>
T LowerToGreater(const void* a, const void* b)
{
    const T* x = (T*) a, y = (T*) b;
    if (*x > *y) return 1;
    else if (*x < *y) return -1;
    return 0;
}

template <class T>
T GreaterToLower(const void* a, const void* b)
{
    const T* x = (T*) a, y = (T*) b;
    if (*x < *y) return 1;
    else if (*x > *y) return -1;
    return 0;
}

void Bubble(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int ok = 1;
		for(int j = n-1; j > i; j--)
		{
			if (a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
				ok = 0;
			}
		}
		if (ok == 1) return;
	}
}

void Bubble2(int *L, int *R)
{
	int ok = 1;
	for (int *p = R-1; p > 0; p++)
	{
		if (*p < *(p - 1))
		{
			swap(*p, *(p - 1));
			ok = 0;
		}
	}
	if (ok == 1) return;
}

template <class T, class CMP>
void Bubble3(T *L, T *R, CMP cmp = less<T>())
{
	
	for (T *p = L; p < R; p++)
	{
		int ok = 1;
		for (T *q = R - 1; q > p; q--)
			if (cmp(*q, *(q - 1)))
			{
				swap(*q, *(q - 1))
				ok = 0;
			}
	}
	if (ok == 1) return
}

void sol()
{

}

int main()
{
	sol();
}

