#include<bits/stdc++.h>
using namespace std;

// Dãy con tăng dài nhất
int main()
{
    int n, x;
    cin >> n;
    vector <int> b;

    while(n--)
    {
        cin >> x;
        if (b.size() == 0 || b.back() < x)
            b.push_back(x);
        else
        {
            auto p = lower_bound(b.begin(), b.end(), x);
            *p = x;
        }
    }

    cout << b.size();
}

// 4 7 3 5 8 2 9 1 6 3
// 1 3 6 9

