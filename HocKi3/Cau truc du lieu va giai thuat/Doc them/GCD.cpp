#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void Sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (a[i] > a[j])
        {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }
}


int main()
{
	int a = 6, b = 10;
    a ^= b; b ^= a; a ^= b;
    cout << a << " " << b;
} 


