#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check(long long n)
{
    if (n < 0 || n % 3 > 1 || n % 4 > 1) return 0;
    long long L = 0, R = n;

    while(L <= R)
    {
        long long m = (L + R) / 2; // m: mid
        if (m*m == n) return 1;
        m*m > n ? R = m - 1 : L = m + 1;

        if (m*m > n) R =  m - 1;
        else L = m + 1;
    }
    return 0;
}

int main()
{
    for (long long i = 0; i < 1000; i++) if (check(i)) cout << i << " ";
}