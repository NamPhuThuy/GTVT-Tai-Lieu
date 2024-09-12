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

// Example 1:
template <class T>
T GCD(T a, T b)
{
    T r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

// Example 2:
template <class T>
void insertArr(T A[], long long n)
{
	for (long long i = 0; i < n; i++) cin >> A[i];
}

template <class T>
void printArr(T *A, long long n) 
{
    cout << "Arr: ";
	for (long long i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

template <class T>
T getSumArr(T A[], long long n)
{
    T ans = A[0];
    for (long long i = 1; i < n; i++) ans += A[i];
    return ans;
}

int main()
{
	// Example 1:
	long long a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
    
    // Example 2:
    ll n; cout << "Insert num of elements: ";
    cin >> n;
    complex <double> A[n];
    insertArr<complex<double>>(A, n);

    printArr<complex<double>>(A, n);
	cout << getSumArr<complex<double>>(A, n);
}
