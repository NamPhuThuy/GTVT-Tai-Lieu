#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
class Queue
{
    // n: số lượng phần tử, F: vị trí phần tử đầu, L: vị trí phần tử cuối, cap: sức chứa
    ll n, F, L, cap;
    T *buf;

    public:
        Queue()
        {
            buf = NULL; 
            n = 0; 
            F = L = 0;
        }

        ~Queue()
        {
            if (buf) delete []buf;
        }

        ll size(){return n;}
        bool empty(){return n == 0;}

        T& front(){return buf[F];}
        T& back()
        {
            if (L == 0) return buf[cap - 1];
            return buf[L - 1];
        }

        void pop()
        {
            n--;
            // F = (F + 1) % cap;

            if (n == 0) F = L = 0;
            else F = (F + 1) % cap;
        }

        void push(T x)
        {
            if (n == cap)
            {
                cap = cap ? cap*2 : 1;
                T *tmp = new T[cap];

                for (ll i = F, j = 0; i < F + n; i++, j++)
                    tmp[j] = buf[i%cap];

                if (buf) delete[]buf;
                buf = tmp;
                F = 0;
                L = n;
            }

            buf[L] = x;
            L = (L + 1)%cap;
            n++;
        }
};

int main()
{	
	Queue<ll> q;
    for (ll x : {123, 123, 31, 31, 536, 747, 474}) q.push(x);
    q.front() = 10000;
    q.back() = 99999;
    while(q.size())
    {
        cout << q.front();
        q.pop();
    }
}
