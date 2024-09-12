#include<bits/stdc++.h>
using namespace std;

bool ss(int a, int b)
{
    // Nếu 2 số có cùng số dư khi chia hết cho 3...
    return a%3 == b%3 ? a < b : a%3 < b%3;
}

struct SS
{
    bool operator()(int a, int b)
    {
        return a%3 == b%3 ? a < b : a%3 < b%3;
    }
}

int main()
{
    int n; cin >> n;
    int a[n]; 
    for (auto &i : a) cin >> i;

    sort(a, a+n, [](int a, int b){return a%3 == b%3 ? a < b : a%3 < b%3;}); // lambda
}