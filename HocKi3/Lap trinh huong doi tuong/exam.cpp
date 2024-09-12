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
void insertArr(T A[], T n) {for (T i = 0; i < n; i++) cin >> A[i];}

template <class T>
void printArr(T *A, T n) {for (T i = 0; i < n; i++) cout << A[i] << " ";}

map <ll, ll> Dict; // dùng map để chứa các giá trị input(first) - output (second)

long long zero(ll n)
{
    if (Dict.find(n) != Dict.end()) return Dict[n];
    if (n == 0) return Dict[n] = 1;

    ll s = 0;
    for (ll a = 1; a*a <= n; a++) 
        if (n % a == 0) s = (s + zero((a - 1)*(n/a + 1))) % MOD;

    return Dict[n] = s; // Mỗi lần trả về kết quả của các bài toán con thì ta đều sẽ lưu lại để có thể dùng cho lần sau (giống như QHĐ)
}

void sol()
{
	ll n; cin >> n;
    cout << zero(n) << endl;
}	

int main()
{
	//qsort(arr, num, sizeof(int), LowerToGreater);
	//qsort(Arr, n, sizeof(ll), LowerToGreater);
 	// freopen("Input.txt", "r", stdin);
	std::ios::sync_with_stdio(NULL); std::cin.tie(0); std::cout.tie(0);
	long long t; cin >> t;
	for (long long ca = 1; ca <= t; ca++)
	{
		// std::cout << "Case #" << ca << ": ";
		sol();
	}
}
