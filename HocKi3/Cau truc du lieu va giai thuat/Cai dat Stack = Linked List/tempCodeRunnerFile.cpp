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

cal(ll b, ll a, char i)
{
    if (i == '+') return a + b;
    if (i == '-') return b - a;
    if (i == '*') return a*b;
    return b/a;
}


ll valueOfExpression(string ans)
{
    stack <ll> tmp;
    ll res = 0;
    for (char i : ans)
    {
        if (i <= '9' && i >= '0')
        {
            tmp.push(i - '0');
        }
        else 
        {
            ll a = tmp.top(); tmp.pop();
            ll b = tmp.top(); tmp.pop();

            tmp.push(cal(b, a, i));
        }
    }

    return tmp.top();
}


void sol()
{
    string A, ans = ""; cin >> A; // A: chuỗi đầu vào, ans: chuỗi hậu tố Ba Lan
    map <char, int> Priority = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {')', 0}, {'(', 0}}; // map lưu trữ độ ưu tiên của từng kí tự 
    stack <char> B; // stack dùng làm vật chứa tạm để chứa các kí tự không phải số 

    for (ll i = 0; i < A.size(); i++)
    {
        if (A[i] <= '9' && A[i] >= '0') 
        {
            // ans.push_back(A[i]);
            ans += A[i];
        }
        else if (A[i] == '(') ans += A[i];
        else if (A[i] == ')') 
        {
            while(B.top() != '(') 
            {
                ans += B.top();
                B.pop();
            }
            B.pop(); // lấy nốt dấu '(' ra khỏi stack
        } 
        else 
        {
            // while(B.size() && (Priority[B.top()] >= Priority[A[i]]))
            while(!B.empty() && (Priority[B.top()] >= Priority[A[i]]))
            {
                // ans.push_back(B.top());
                ans += B.top();
                B.pop();
            }
            B.push(A[i]);
        }
    }

    while(B.size()) 
    {
        ans += B.top();
        B.pop();
    }
    cout << ans;

    // Tính giá trị biểu thức 
    ll res = valueOfExpression(ans);
    cout << endl << res;

}

int main()
{
   sol();
}
