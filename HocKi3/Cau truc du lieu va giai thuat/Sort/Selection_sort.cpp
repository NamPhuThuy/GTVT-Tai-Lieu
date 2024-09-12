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

void Select(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int p = 1;
		for(int j = i + 1; j < n; j++)
			if (a[j] < a[p]) 
				p = j;

		swap(a[i], a[p]);
	}
}

void Select2(int *L, int *R)
{
	for (int *p = L; p < R; p++)
	{
		int *z = p;
		for (int *q = p + 1; q < R; q++) 
			if (*q < *z)
				z = q;
		
		swap(*p, *z);
	}
}

template <class T, class CMP>
void Select3(T *L, T *R, CMP cmp = less<T>())
{
	for (T *p = L; p < R; p++)
	{
		T *z = p;
		for (T *q = p + 1; q < R; q++) 
			if (cmp(*q, *z))
				z = q;
		
		swap(*p, *z);
	}
}

void sol()
{
	int A[4];
	
}

int main()
{
	sol();
}

