#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;
long long A[] = {};

template <class T, class CMP = less<T>>
class PQ
{
    T *buf;
    CMP cmp;
    int cap, n;//capacity, size

    void sol(int *A, int n, int k)
    {
        if (2*k + 1 >= n) return;
        int p = 2*k + 1;

        if (p + 1 < n && A[p] < A[p + 1]) p++;

        if (A[k] < A[p])
        {
            swap(A[k], A[p]);
            sol(A, n, p);
        }
    }
    public:
    PQ()
    {
        buf = NULL;
        cap = n = 0;
    }

    ~PQ(){if (buf) delete buf;}
    int size() {return n;}
    bool empty() {return n == 0;}
    T top() {return buf[0];}
    void push(T x)
    {
        if (n == cap)
        {
            cap = cap*2 + 1;
            T *tmp = buf;
            buf = new T[cap];

            for (int i = 0; i < n; i++)
                buf[i] = tmp[i];
            if (!tmp) delete tmp;
        }

        buf[n++] = x;
        int k = n-1;
        while(k > 0 && a[(k-1)/2] < a[k])
        {
            swap(a[(k-1)/2], a[k]);
            k = (k-1)/2;
        }
    }

    void pop()
    {
        buf[0] 
    }
};

int main()
{

}

