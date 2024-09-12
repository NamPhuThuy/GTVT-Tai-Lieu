#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

template<class T>
class HT //để cài unordered_map, unordered_set
{
    int M = 12348;// số ngăn của mảng
    list <T> L[M];
    int hashFunction(T x)
    {
        hash <T> H;
        return H(x) % M;
    }

    public:
        HT() {n = 0;}
        int size() {return n;}
        int empty() {return n == 0;}
        void insert(T x)
        {
            int k = hashFunction(x);
            L[k].push_back(x);
            n++;
        }

        void erase(T x)
        {
            int k = hashFunction(x);
            auto it = L[k].begin();
            while(it != L[k].end() && *it != x) it++;
            if (it == L[k].end()) return;
            L[k].erase(it);
            n--;
        }

        void travel()
        {
            for (int i = 0; i < M; i+=)
                for (auto x : L[i])     
                    cout << x << " ";
        }

};

int main()
{
    // hash<string> H;
    // cout << H("thang cho");

    
}

