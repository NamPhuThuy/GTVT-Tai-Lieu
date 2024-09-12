#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

// Đánh giá độ phức tạp:
// Ưu: nhanh, dễ song song hóa 
int B[120];

// //Cách 1: sắp xếp dãy A từ L đến R-1
// void mergeSort(int *A, int L, int R)
// {
// 	if (L >= R-1) return;
// 	int mid = (L + R) / 2;

// 	mergeSort(A, L, mid);
// 	mergeSort(A, mid, R);


// 	for (int i = L, j = mid, k = L; k < R; k++)
// 	{
//         // Nếu j >= R: 
//         // i vẫn còn nhỏ hơn mid và A[i] < A[j] thì 
// 		B[k] = ((j >= R || i < mid && A[i] < A[j]) ? A[i++] : A[j++]);
// 	}

// 	for (int k = L; k < R; k++) A[k] = B[k];
// }

// Cách 2: 
// void mergeSort(int *L, int *R, int * B)
// {
// 	if (L >= R-1) return;
// 	int *mid = L + (R - L)/2;

// 	mergeSort(L, mid, B);
// 	mergeSort(mid, R, B);


// 	for (int *i = L, *j = mid, *k = B; k < B + (R - L); k++)
// 	{
// 		*k = (j >= R || i < mid && *i < *j) ? *i++ : *j++;
// 	}

// 	for (int *k = L, *p = B; k < R; k++) *k = *p++;
// }

// void ms(int *L, int * R)
// {
//     int *B = new int[R - L + 5];
//     mergeSort(L, R, B);
//     delete[] B;
// }

// Cách 3: tổng quát
template <class T, class CMP>
void mergeSort(T *L, T *R, T * B, CMP cmp)
{
	if (L >= R-1) return;
	int *mid = L + (R - L)/2;

	mergeSort(L, mid, B, cmp);
	mergeSort(mid, R, B, cmp);


	for (T *i = L, *j = mid, *k = B; k < B + (R - L); k++)
	{
		*k = (j >= R || i < mid && cmp(*i, *j)) ? *i++ : *j++;
	}

	for (T *k = L, *p = B; k < R; k++) *k = *p++;
}

template <class T, class CMP>
void ms(T *L, T * R, CMP cmp = less<T>())
{
    T *B = new T[R - L + 5];
    mergeSort(L, R, B, cmp);
    delete[] B;
}

void sol()
{
	int A[] = {5, 6, 12, 0, -9, 21, -12, 6, 7, 15};
    for (auto i : A) cout << i << " ";
    cout << endl;
    int n = sizeof(A) / sizeof(A[0]);
	ms(A, A + n, greater<int>());
	for (auto i : A) cout << i << " ";
}

int main()
{
	sol();
}

