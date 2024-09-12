#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;


// Nhập, xuất và so sánh của dãy học sinh
class student
{
    // public:
    string name;
    double mark;

    public:
    student(string n = "", double m = 0)
    {
        name = n;
        mark = m;
    }

    bool operator > (student a)
    {
        // double dis1 = sqrt(pow(this->first, 2) + pow(this->second, 2));
        
        if (this->mark > a.mark) return true;
        return false;
    }

    friend istream& operator >> (istream& , student& );
    friend ostream& operator << (ostream& , student& );
};

istream& operator >> (istream& in, student& a)
    // istream& operator >> (istream& in)
{
    cin >> a.name >> a.mark;
    return in;
}

ostream& operator << (ostream& out, student& a)
// ostream& operator << (ostream& out)
{
    cout << "(" << a.name << ", " << a.mark << ")";
    return out;
}

template <class T>
class A
{
    T *arr;
    int n;


    public:
    ~A()
    {
        delete arr;
    }

    int getN(){return n;}

    T* getArr(){return arr;}

    void nhap()
    {
        cout << "Nhap n, bitch: ";
        cin >> n;

        arr = new T[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void xuat()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << endl;
    }

    void sort()
    {
        for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[j], arr[i]);
    }

    T at(int i) // chưa hoạt động
    {
        return this->getArr()[i];
    }
};

// Nhập, xuất và so sánh của dãy điểm
template <class T> 
bool operator > (pair<T, T> a, pair <T, T> b)
{
    // double dis1 = sqrt(pow(this->first, 2) + pow(this->second, 2));
    double dis1 = sqrt(pow(a.first, 2) + pow(a.second, 2));
    double dis2 = sqrt(pow(b.first, 2) + pow(b.second, 2));
    if (dis1 > dis2) return true;
    return false;
}

template <class T>
ostream& operator << (ostream& out, pair<T, T>& a)
{
    cout << "(" << a.first << ", " << a.second << ")";
    return out;
}

template <class T>
istream& operator >> (istream& in, pair<T, T>& a)
{
    cin >> a.first >> a.second;
    return in;
}

void sol()
{
    A <pair<int, int>> a;
    a.nhap();
    a.sort();
    cout << "\nDay diem sau khi da sap xep:\n";
    a.xuat();
    
    cout << "\nDiem cach xa goc toa do nhat la: \n";
    for (int i = a.getN() - 1; i > 0; i--)
    {
        cout << a.getArr()[i] << endl;
        // cout << a.at(i) << endl;
        if (a.getArr()[i] > a.getArr()[i-1]) break;
    }
    

    cout << "\n";
    A <student> b;
    b.nhap();
    b.sort();
    cout << "\n Danh sach sinh vien sau khi da sap xep:\n";
    b.xuat();
    cout << "\n Nhung hoc sinh co diem cao nhat: \n";
    for (int i = b.getN() - 1; i > 0; i--)
    {
         cout << b.getArr()[i] << endl;
        if (b.getArr()[i] > b.getArr()[i-1]) break;
    }
    
    

}	

int main()
{
	sol();
}
