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

int main()
{
   
	STACK<int> S;
    for (int x : {12, 34, 54, 89, 33434, 13}) S.push(x);
    while(S.size())
    {
        cout << S.top() << " ";
        S.pop();
    }

    STACK <int> *A = new STACK<int>();
    for (int x : {12, 34, 54, 89, 33434, 13}) A->push(x);
    while(A->size())
    {
        cout << A->top() << " ";
        A->pop();
    }
    delete A;

}
