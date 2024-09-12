#include<bits/stdc++.h>
using namespace std;


class node
{
	public:
	int elem;
	node *left, *right;
	node (int x)
	{
		left = right = NULL;
		elem = x;
	}
};

void update(node*&H, int x)
{
	if (!H) H = new node(x);
	if (x == H->elem) return;
	else if (x < H->elem) update(H->left, x);
	else update(H->right, x);
}

void inorder(node*H, string p = "\n")
{
	if (!H) return;
	inorder(H->left, p + "\t");
	cout << p << H->elem;
	inorder(H->right, p + "\t");
}

int max(node*H)
{
    if (!H) return INT_MIN;
    if (!H->right) return H->elem;
    else max(H->right);
}

int min(node*H)
{
    if (!H) return INT_MAX;
    if (!H->left) return H->elem;
    else min(H->left);
}

void remove(node*&H, int x)
{
    if(!H) return;
    if (H->elem != x)
        remove(x < H->elem ? H->left : H->right, x);
    else 
    {
        if (!H->left) H = H->right;
        else if (!H->right) H = H->left;
        else 
        {
            H->elem = max(H->left);
            remove(H->left, H->elem);
        }
    }
}

void sol()
{
	int n, x; cin >> n;
	node* root = NULL;
	while(n--)
	{
		cin >> x;
		update(root, x);
	}

	inorder(root);
    cout << "\nMax = " << max(root);
    cout << "\nMin = " << min(root);

    remove(8);
    inorder(root);
}

node* find(node* H, int x)
{
	if (!H or H->elem == x)
		return H;
	return find(x < H->lem ? H->left : H->right, x);
}

int main()
{
    freopen("Input.txt", "r", stdin);
	sol();
}

