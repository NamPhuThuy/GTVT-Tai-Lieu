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

template <class T>
T LowerToGreater(const void* a, const void* b)
{
    const T* x = (T*) a;
    const T* y = (T*) b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}

template <class T>
void insertArr(T A[], T n)
{
	for (T i = 0; i < n; i++) cin >> A[i];
}

template <class T>
void printArr(T *A, T n)
{
	for (T i = 0; i < n; i++) cout << A[i] << " ";
}

vector <ll> x = {};

void Backtrack(vector <ll> x, int k, int f)
{
	if (x[k] == f)
	{
		for (int i = 0; i < k; i++) cout << x[i] << " ";
		cout << x[k] << "\n";
	}
	
	for (int a = 1; a*a <= x[k]; a++)
	{
		if (x[k] % a == 0)
		{
			x[k + 1] = (a - 1)*(x[k]/a + 1);
			if (x[k + 1] >= f) Backtrack(x, k + 1, f);
		}
	}
}

void sol()
{
	ll x0, f;
	cin >> x0 >> f;
	x.push_back(x0);
	Backtrack(x, 1, f);
	
	sort(x.begin(), x.end());
	for (int i = 0; i < 100; i++) 
	{
//		if (x[i] == 0) break;
		cout << x[i] << " ";
	}
}	

int main()
{
	//qsort(arr, num, sizeof(int), LowerToGreater);
	//qsort(Arr, n, sizeof(ll), LowerToGreater);
 	sol();
}

