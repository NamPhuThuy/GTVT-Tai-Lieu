#include <math.h>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> state;

long long max(ll a, ll b)
{
    if (a > b) return a;
    return b;
}

class water
{
    long long n, m, k; 
    map <state, state> Path;

    void DFS()
    {
        stack <state> Stack;
        
        Stack.push({0, 0});
        Path[{0, 0}] = {-1, -1};

        while (Stack.size())
        {
            long long x = Stack.top().first, y = Stack.top().second, z = x + y;
            Stack.pop();

            state Next[6] = {{0, y}, {x, 0}, {n, y}, {x, m}, {max(0, z - m), min (z, m)}, {min(z, n), max(z - n, 0)}};

            for (auto i : Next)
            {
                cout << "what\n";
                cout << i.first << " " << i.second << endl;
                if (Path.find(i) == Path.end())
                {
                    cout << "hi\n";
                    Path[i] = Path[{x, y}];
                    if (i.first == k || i.second == k) 
                    {
                        printResult(i);
                        return;
                    }
                }
            }
        }
        cout << "Cant solve";
    }

    void printResult(state i)
    {
        stack <state> ansPath;
        do
        {
            ansPath.push(i);
            i = Path[i];
        }
        while(i.first != 0 || i.second != 0);

        while(ansPath.size())
        {
            cout << "(" << ansPath.top().first << ", " << ansPath.top().second << ") ";
        }
    }

    public:
    void sol()
    {
        cin >> n >> m >> k;
        DFS();
    }
};



int main()
{
    water a;
	a.sol();
}
