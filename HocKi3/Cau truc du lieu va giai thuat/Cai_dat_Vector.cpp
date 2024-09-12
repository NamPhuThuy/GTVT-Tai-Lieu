#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

class vt_rite
{
    T*curr;
    public:
    vt_rite(T *c = NULL)
    {
        curr = c;
    }
    vt_rite<T> &operator = (vt_rite<T> it)
    {
        this->curr = it.curr;
        return *this;
    }

    bool operator != (vt_rite<T> it)
    {
        return this->curr != it.curr;
    }

    T &operator *()
    {
        return *curr;
    }

    vt_rite<T> operator++(int) //it++
    {
        T* c = curr;
        curr = curr-1;
        return vt_rite<T>(c);

        // curr = curr-1;
        // return vt_rite<T>(curr);
    }

    vt_rite<T> operator++() //++it
    {
        curr = curr-1;
        return vt_rite<T>(curr);
    }
};

template<class T>
class Vector
{
    int n, cap; // n: size, cap: capacity
    T *buf;
    void recap(int k)
    {
        if (cap >= k) return;
        // else
        // {
        //     cap = k;
        //     T *tmp = new T[cap];
        //     for (int i = 0; i < cap; i++) 
        // }

        cap = k;
        T *tem = new T[cap];
        for (int i = 0; i < n; i++)
        {
            tem[i] = buf[i];
        }
        if (buf) delete[] buf;
        buf = tem;
    }

    public:
        typedef T* iterator;
        iterator begin() {return buf;}
        iterator end() {return buf + n;} 
        typedef vt_rite<T> reverse_iterator;
        reverse_iterator rbegin(){return buf + n - 1;}
        reverse_iterator rend(){return buf - 1;}

        Vector()
        {
            n = cap = 0;
            buf = NULL;
        }

        Vector (int k, T x)
        {
            n = cap = k;
            buf = new T[k];
            for (int i = 0; i < k; i++) buf[i] = x;

        }

        Vector (Vector<T> &v)
        {
            if (v.n == 0)
            {
                this->buf = 0;
                this->n = this->cap = 0;
            }
            else 
            {
                this->cap = v.cap;
                this->n = v.n;
                this->buf = new T[v.cap];
                for (int i = 0; i < n; i++)
                    this->buf[i] = v.buf[i];
                
                
            }
        }

        Vector<T> &operator = (Vector<T> &v)
        {
            if (v.n == 0)
            {
                this->buf = 0;
                this->n = this->cap = 0;
            }
            else 
            {
                this->buf = new T[v.cap];
                for (int i = 0; i < n; i++)
                    this->buf[i] = v.buf[i];
                this->n = v.n;
                this->cap = v.cap;
            }
            return *this;
        }

        ~Vector() {if (buf) delete[]buf;}

        int size() {return n;}
        bool empty() {return n == 0;}
        T &front() {return buf[0];}
        T &back() {return buf[n-1];}
        T &operator [] (int i) {return buf[i];}
        T &at(int i) {return buf[i];}

        void pop_back() {n--;}
        void push_back(T x)
        {
            if (n == cap) recap(cap ? cap*2, 1);
            buf[n++] = x;
        }

        void resize(int k, T x)
        {
            if (n >= k)
            {
                n = k;
                return ;
            }

            if (k > cap)
                recap(k);

            for (int i = n; i < k; i++) buf[i] = x;
                n = k;
        }

        void insert(iterator &it, T x)
        {
            if (n == cap)
            {
                int k = it - buf;
                recap(cap ? cap*2 : 1);
                it = buf + k;
            }

            for (auto it1 = buf + n-1; it1 >= it; it1--) *(it1+1) = *it1;
            *it = x;
            n++;
        }

        void erase(iterator it)
        {
            for (iterator it1 = it; it1 < buf + n; it1++) *it1 = *(it1+1);
            n--;
        }
};

int main()
{
	Vector A;
    for(auto i : {12, 1212, 1212, 90}) A.push_back;
    Vector B;
    B = A;
}
