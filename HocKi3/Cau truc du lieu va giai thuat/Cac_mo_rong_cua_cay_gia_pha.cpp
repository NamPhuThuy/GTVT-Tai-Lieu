#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

ll maxChild = 0, height = 0;

class node
{
public:
	vector <node*> child;
	ll num, deep;
	string name;
	node(string na  = "", ll n = 0, ll de = 0)
	{
		name = na;
		num = n, deep = de;
	}
};



void update(node *&H, string a, string b)
{
	if (!H) return;
	if (H->child.size()) update(H->child[0], a, b);
	if (H->name == a) 
	{
		node *tmp = new node(b, 0, H->deep + 1);
		// tmp->name = b;
		// tmp->deep = H->deep + 1;

		H->child.push_back((node*)tmp);
		H->num++;
        return;
	}
	for (ll i = 1; i < H->child.size(); i++) update(H->child[i], a, b);
}

// Duyệt trung thứ tự để in ra cây gia phả: con cả -> gốc -> các con còn lại
// void inorder2(node *&H)
// {
// 	if (!H) return;
// 	maxChild = max(maxChild, H->num);
// 	height = max(H->deep, height);
// 	if (H->child.size()) inorder2(H->child[0]);
// 	cout << H->name << " ";
	
	
// 	for (ll i = 1; i < H->child.size(); i++) inorder2(H->child[i]);
// }

// Đưa các địa chỉ vào trong list
void inorder2(node *H, list <node*> &L)
{
	// if (!H) return;
	// maxChild = max(maxChild, H->num);
	// height = max(H->deep, height);
	if (H->child.size()) inorder2(H->child[0], L);
	L.push_back(H);
	// cout << H->name << " ";
	
	
	for (ll i = 1; i < H->child.size(); i++) inorder2(H->child[i], L);
}

// Đưa các giá trị vào trong list
void inorder3(node *H, list <string> &L)
{
	// if (!H) return;
	// maxChild = max(maxChild, H->num);
	// height = max(H->deep, height);
	if (H->child.size()) inorder3(H->child[0], L);
	L.push_back(H->name);
	// cout << H->name << " ";
	
	
	for (ll i = 1; i < H->child.size(); i++) inorder3(H->child[i], L);
}

class GiaPha
{
    public:

        node* root; //quản lý node gốc
        int n; // quản lý số lượng node

        // 1 list chứa địa chỉ các node
        // Dùng bộ lặp của list để in ra các giá trị trong gia phả
	    list <node*> L; 
    
        GiaPha()
        {
            n = 0;
            root = NULL;
        }

        void nhap()
        {
            cin >> n;
            for (int i = 1; i < n; i++)
            {
                string x, y;
                cin.ignore(1);
                cin >> x >> y;
                if (i == 1) root = new node(x);
                update(root, x, y);
            }
        }

		typedef typename list<node*>::iterator iterator;
		iterator begin()
		{
			L.clear();
			inorder2(root, L);
			return L.begin();
		}

		iterator end()
		{
			return L.end();
		}
};


void sol()
{
	// node *root = NULL;
	// ll n; cin >> n;
	// n--;
	
	// string x, y; cin >> x >> y;
	// root = new node(x, 0, 1);

    // node *tmp = new node(y, 0, 2);
	// root->child.push_back(tmp);
    // root->num++;

	// n--;
	// while(n--)
	// {
	// 	string a, b; cin >> a >> b;
	// 	update(root, a, b);
	// }
	
	// inorder2(root);
	// cout << endl;
	// cout << maxChild << endl << height;

	GiaPha G;
	G.nhap();

    // In ra địa chỉ theo trung thứ tự
	for (GiaPha::iterator it = G.begin(); it != G.end(); it++)
		cout << (*it) << " ";

    // In ra giá trị theo trung thứ tự
    for (auto i : G) cout << i->name << " ";
}

int main()
{
	sol();
}