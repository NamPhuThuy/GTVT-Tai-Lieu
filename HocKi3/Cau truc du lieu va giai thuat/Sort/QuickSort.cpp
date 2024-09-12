#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

// Tốt nhất O(nlogn)
// Trung bình O(nlogn)
// Xấu nhất O(n^2)

// Cách 1: làm việc với chỉ số
// void quickSort(int *A, int L, int R)
// {
//     if (L + 1 >= R) return;
//     swap(A[L], A[(L + R)/2]);

//     int i = L;
//     for (int j = L + 1; j < R; j++)
//         if (A[j] < A[L]) swap(A[++i], A[j]);
//     swap(A[i], A[L]);

//     quickSort(A, L, i);
//     quickSort(A, i + 1, R);
// }

// Cách 2: làm việc với con trỏ
// void quickSort(int *L, int *R)
// {
//     if (L + 1 >= R) return;
//     swap(*L, *(L + (R - L)/2));

//     int *i = L;
//     for (int *j = L + 1; j < R; j++)
//         if (*j < *L) swap(*++i, *j);
//     swap(*i, *L);

//     quickSort(L, i);
//     quickSort(i + 1, R);
// }

template <class T, class CMP = less <T>>
void quickSort(T *L, T *R, CMP cmp = less<T>())
{
    if (L + 1 >= R) return;
    swap(*L, *(L + (R - L)/2));

    T *i = L;
    for (T *j = L + 1; j < R; j++)
        if (*j < *L) swap(*++i, *j);
    swap(*i, *L);

    quickSort(L, i, cmp);
    quickSort(i + 1, R, cmp);
}

void sol()
{
	int A[] = {5, 6, 12, 0, -9, 21, -12, 6, 7, 15};
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, A + n, greater<int>());
    for (auto i : A) cout << i << " ";
}

int main()
{
	sol();
}

