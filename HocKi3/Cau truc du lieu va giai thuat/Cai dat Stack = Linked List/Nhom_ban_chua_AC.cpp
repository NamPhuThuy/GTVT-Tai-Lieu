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
struct Node
{
    T value;
    Node *next;
    Node (T val, Node *n = 0)
    {
        value = val; 
        next = n;
    }
};

template<class T>
class STACK
{
    private:
        Node<T> *Head;
        int n;

    public: 
        STACK(){Head = NULL; n = 0;}
        ~STACK(){while(n) pop();}
        ll size(){return n;}
        bool empty(){return n == 0;}

        void push(T x)
        {
            // Node<T> *p = new Node<T>(x, Head); Head = p;
            Head = new Node<T>(x, Head); // cách 2
            n++;
        }

        void pop()
        {
            Node<T> *p = Head;
            Head = Head->next;
            delete p;
            n--;
        }

        T top(){return Head->value;}
};

STACK<ll> A[MAX];
map<ll, ll> Marked;
ll tmpMaxPeople = 0;

void DFS(ll n)
{
    tmpMaxPeople++;
    Marked[n] = 1;
    while(A[n].size())
    {
        ll tmp = A[n].top(); A[n].pop();
        if (Marked.find(tmp) == Marked.end()) DFS(tmp);
    }
}

int main()
{

    ll n, m; cin >> n >> m;
    

    while(m--)
    {
        ll a, b; cin >> a >> b;
        A[a].push(b);
        A[b].push(a);
    }

    ll grs = 0, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (Marked.find(i) == Marked.end())
        {
            DFS(i);
            ans = max(ans, tmpMaxPeople);
            grs++;
            tmpMaxPeople = 0;
        }
    }

    cout << grs << "\n" << ans;
}
