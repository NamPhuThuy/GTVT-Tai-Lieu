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
T GreaterToLower(const void* a, const void* b)
{
    const T* x = (T*) a;
    const T* y = (T*) b;
    if (*x < *y)
        return 1;
    else if (*x > *y)
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
//My Code
void sol()
{
    list <int> L(5, 3); // 3 3 3 3 3
    L.front() = 7;
    L.back() = 8;
    L.push_front(1);
    L.push_back(6);
    cout << "L: ";
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";

    L.pop_front();
    L.pop_back();
    L.sort();
    cout << "\nL: ";
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";

    auto it = L.begin(); it++, it++;
    L.insert(it, 9);
    L.erase(it);
    cout << "\nL: ";
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";
    

}

int main()
{
	//qsort(arr, num, sizeof(int), LowerToGreater);
	//qsort(Arr, n, sizeof(ll), LowerToGreater);
 	//freopen("Input.txt", "r", stdin);
	std::ios::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
	long long t; t = 1;
	for (long long ca = 1; ca <= t; ca++)
	{
		//cout << "Case #" << ca << ": ";
		sol();
	}
}
