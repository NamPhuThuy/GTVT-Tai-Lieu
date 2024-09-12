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
    long long DFS()
    {
        stack <state> Stack;
        map <state, long long> Count;
        Stack.push({0, 0});
        Count[{0, 0}] = 0;

        while (Stack.size())
        {
            long long x = Stack.top().first, y = Stack.top().second, z = x + y;
            cout << "x = " << x << ", y = " << y << endl;
            Stack.pop();

            state Next[6] = {{0, y}, {x, 0}, {n, y}, {x, m}, {max(0, z - m), min (z, m)}, {min(z, n), max(0, z - n)}};

            for (auto i : Next)
            {
                if (Count.find(i) == Count.end())
                {
                    Count[i] = Count[{x, y}] + 1;
                    if (i.first == k || i.second == k) return Count[i];
                }

            }
        }
        return -1;
    }

    public:
    void sol()
    {
        cin >> n >> m >> k;
        long long ans = DFS();
        if (ans == -1) cout << "Cant solve";
        else cout << ans;
    }
};



int main()
{
    water a;
	a.sol();
}
