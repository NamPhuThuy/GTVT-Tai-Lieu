#include<bits/stdc++.h>
using namespace std;

// Độ phúc tạp
// T(n) = T(n/2) + C
//      = T(n/4) + 2C
//      = T(n/2^k) + kC
//      = T(1) + logn = O(logn)

//Cách 1
// int *biSearch(int *L, int *R, int x)
// {
//     while(L + 1 <= R)
//     {
//         int *M = L + (R - L)/2;
//         if (*M == x) return M;

//         *M > x ? L = M + 1 : R = M - 1;
//     }
//     return NULL;
// }

//Cách 2
// template <class T>
// int *biSearch(T *L, T *R, T x)
// {
//     while(L + 1 <= R)
//     {
//         int *M = L + (R - L)/2;
//         if (*M == x) return M;

//         *M > x ? L = M + 1 : R = M - 1;
//     }
//     return NULL;
// }

//Cách 3
int *biSearch(int *L, int *R, int x)
{
    if (L + 1 >= R) return NULL;
    int *M = L + (R - L)/2;
    if (*M == x) return M;

    if (*M < x) return biSearch(M + 1, R, x);
    else return biSearch(L, M - 1, x);
}

int main()
{
    int a[] = {-12, -9, -5, 0, 2, 6, 7, 11, 32, 45, 120};
    int n = sizeof(a)/ sizeof(a[0]);
    
    int x; cin >> x;
    int *p = biSearch(a, a+n, x);
    if (p) cout << p;
    else cout << "deo co";

}

// 4 7 3 5 8 2 9 1 6 3
// 1 3 6 9

