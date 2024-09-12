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

class DaThuc
{
    private:
        ll bac;
        double *hs;

    public:
        DaThuc(){bac = 0; hs = NULL;}
        DaThuc(ll b, double* h) : bac(b), hs(h) {};
        ~DaThuc(){delete hs;}

        void insert();
        DaThuc operator + (DaThuc a);

        friend ostream& operator << (ostream& output, const DaThuc& a);
        friend double Cal(DaThuc a, double x0);
};

void DaThuc::insert()
{
    cout << "insert DaThuc's bac: "; cin >> bac;
    hs = new double[bac + 1];

    for (ll i = 0; i <= bac; i++)
    {
        cout << "insert the " << i + 1 << "-th heso: ";
        cin >> hs[i];
    }

    cout << "\n";
}

DaThuc DaThuc::operator + (DaThuc a)
{
    DaThuc ans;
    ans.bac = max(this->bac, a.bac);
    ans.hs = new double[ans.bac + 1];

    for (ll i = 0; i <= min(this->bac, a.bac); i++)
    {
        ans.hs[i] = this->hs[i] + a.hs[i];
    }

    if (this->bac < a.bac)
    {
        for (ll i = this->bac + 1; i <= a.bac; i++)
            ans.hs[i] = a.hs[i];
    }
    else if (this->bac > a.bac)
    {
        for (ll i = a.bac + 1; i <= this->bac; i++)
            ans.hs[i] = this->hs[i];
    }

    return ans;
}

// istream& operator >> (istream& input, DaThuc& a)
// {
//     cout << "insert DaThuc's bac: "; input >> a.bac;
//     a.hs = new double[a.bac + 1];

//     for (ll i = 0; i <= a.bac; i++)
//     {
//         cout << "insert the " << i + 1 << "-th heso:\n";
//         input >> a.hs[i];
//     }

//     return input;
// }

ostream& operator << (ostream& output, const DaThuc& a)
{
    cout << a.hs[0] << "*x^0";
    for (ll i = 1; i <= a.bac; i++) 
        cout << " + " << a.hs[i] << "*x^" << i;
    return output;
}

double Cal(DaThuc a, double x0)
{
    double ans = 0;
    for (ll i = 0; i <= a.bac; i++)
    {
        ans += a.hs[i]*pow(x0, i);
    }
    cout<<"\n ans=\n"<<ans;

    return ans;
}

int main()
{
    DaThuc P, Q;
    P.insert();
    Q.insert();

    cout << P << endl;
    cout << Q << endl;

    DaThuc F = P + Q;
    cout << F << endl;
 
    double d; cin >> d;
    double a = Cal(P, d)+ Cal(Q, d), ans;

    if (ans != 0) 
    {
    	ans = 1/a;
    	cout << "ans = " << ans;
	}
    else cout << "khong tinh duoc";
    
}

