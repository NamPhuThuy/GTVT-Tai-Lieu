#include<bits/stdc++.h>
using namespace std;

//Heap (đống)
// Heap là cây nhị phân được định nghĩa đệ quy
// - Cây rỗng hoặc 1 phần tử là heap
// - Cây nhị phận:
//  + Gốc >= mọi phần tử trong cây
//  + Cây trái và phải đều là cây heap 
//                 87
//        65                 56
//   42       57        50        32
// 18   35
// Biểu diễn dạng mảng: 87 65 56 42 57 50 32 18 35

// Tạo đống
// Tạo đống từ 1 mảng. Xét từ cuối mảng lên đầu mảng
// Node nào có con thì kiểm tra xem node gốc đã lớn nhất chưa, chưa thì đổi chỗ node gốc và node
// có giá trị lớn nhất
// Sau đó lại xét tiếp các node con của node đang xét cho đến khi node đang xét không có con

// Độ phức tạp:
// Vun đống O(logn)
// -> Tạo đống O(nlogn), Sắp xếp O(nlogn)
// ==> T(n) = O(nlogn)


//Cách 1:
// void sol(int *A, int n, int k)
// {
//     if (2*k + 1 >= n) return;
//     int p = 2*k + 1;

//     if (p + 1 < n && A[p] < A[p + 1]) p++;

//     if (A[k] < A[p])
//     {
//         swap(A[k], A[p]);
//         sol(A, n, p);
//     }
// }

// void heapSort(int *A, int n)
// {
//     for (int i = n - 1; i >= 0; i--) 
//         sol(A, n, i); // Tạo đống
    
//     for (int i = n - 1; i > 0; i--)
//     {
//         swap(A[0], A[i]);
//         sol(A, i, 0);
//     }
// }

//Cách 2
// Vun tại vị trí k trong dãy con trỏ từ L đến R
// void sol(int *L, int *R, int k)
// {
//     if (L + 2*k + 1 >= R) return;
//     // Xét con thứ 1
//     int *p = L + 2*k + 1;

//     // Nếu con thứ 2 lớn hơn thì xét con 2
//     if (p + 1 < R && *p < *(p + 1)) 
//         p++;
//     if (*(L + k) < *p)
//     {
//         swap(*(L + k), *p);
//         sol(L, R, p-L);
//     }
// }

// void heapSort(int *L, int *R)
// {
        // Tạo đống
//     for (int *i = R-1; i >= L; i--) 
        // sol(L, R, i-L);

//     for (int *i = R-1; i >= L; i--)
//     {
//         swap(*L, *i);
//         sol(L, i, 0);
//     }
// }

// Cách 3
template <class T, class CMP>
void sol(T *L, T *R, int k, CMP cmp)
{
    if (L + 2*k + 1 >= R) return;
    // Xét con thứ 1
    T *p = L + 2*k + 1;

    // Nếu con thứ 2 lớn hơn thì xét con 2
    if (p + 1 < R && cmp(*p, *(p + 1)))
        p++;
    if (cmp(*(L + k), *p))
    {
        swap(*(L + k), *p);
        sol(L, R, p-L, cmp);
    }
}

template <class T, class CMP = less<T>>
void heapSort(T *L, T *R, CMP cmp = less<T>())
{
    for (T *i = R-1; i >= L; i--) sol(L, R, i-L, cmp);
    for (T *i = R-1; i >= L; i--)
    {
        swap(*L, *i);
        sol(L, i, 0, cmp);
    }
}

int main()
{
	int a[] = {12, 32, 43, 423, 224, 424, 7, 87, 23, 3};
    int n = sizeof(a)/sizeof(a[0]);

    // make_heap(a, a + n);//Tạo đống từ mảng a
    for (auto i : a) cout << i << " ";

    heapSort(a, a + n, greater<int>());
    cout << endl;
    for (auto i : a) cout << i << " ";
}

