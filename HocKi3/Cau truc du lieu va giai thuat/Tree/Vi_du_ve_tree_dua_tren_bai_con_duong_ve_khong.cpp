#include<bits/stdc++.h>
using namespace std;


struct node
{
    int elem;
    vector <node*> child;

    node (int n)
    {
        elem = n;
        for (int a = 1; a*a <= n; a++)
        if (n % a == 0) 
            child.push_back(new node((a-1)*(n/a + 1)));
    }
};

// In các gốc -> lần lượt các con
void preorder(node *H)
{
    if (!H) return;
    cout << H->elem << " ";
    for (auto i : H->child) preorder(i); 
}

// In các con rồi mới đến các gốc
void postorder(node *H)
{
    if (!H) return;
    for (auto i : H->child) postorder(i); 
    cout << H->elem << " ";
    
}

// In con cả -> gốc -> các con còn lại
void inorder(node *H)
{
    if (!H) return;
    if (H->child.size()) inorder(H->child[0]);
    cout << H->elem << " ";

    for (int i = 1; i < H->child.size(); i++) inorder(H->child[i]);
}

// In các phần tử dưới dạng cây
void inorder2(node *H, string p = "\n")
{
    if (!H) return;
    if (H->child.size()) inorder2(H->child[0], p + "\t");
    cout << p <<  H->elem << " ";

    for (int i = 1; i < (int)H->child.size(); i++) inorder2(H->child[i], p + "\t");
}

int main()
{
	node* root = new node(24);
    inorder2(root);
    // cout << root->elem << endl;
    // cout << root->child[2]->child[1]->child[1]->elem;
}
