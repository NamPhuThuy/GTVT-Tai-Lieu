#include <bits/stdc++.h>

using namespace std;

void insert(int &a, int *&b)
{
    cout << "Insert array number: "; cin >> a;

    b = new int [a + 1];
    cout << "\nInsert array:";
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }
}

void print(int a, int *b)
{
    for (int i = 0; i < a; i++)
    {
       cout << b[i] << " ";
    }
    cout << endl;
}


int main()
{
    int m, n, *a, *b;
    insert(m, a);
    print(m, a);

    insert(n, b);
    print(n, b);
}