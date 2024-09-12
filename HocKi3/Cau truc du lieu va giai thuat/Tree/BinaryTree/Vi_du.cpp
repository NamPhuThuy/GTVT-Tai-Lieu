#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Nhập vào n, tạo cây nhị phân có gốc mang giá trị n
// Với mỗi node cha có giá trị k, tạo 2 node con có tổng bằng k 
// và chênh nhau 4 đơn vị
//My Code
class node
{
    public:

    ll elem;
    node *left, *right, *next;
    node(ll val = 0)
    {
        elem = val;
        next = NULL;
        if (val % 2 == 1 || val <= 4) left = right = NULL;
        else 
        {
            left = new node(val/2 - 2);
            right = new node(val/2 + 2);
        }
    }
};

void inorder(node*H, list<node*> &L)
{
    if (!H) return;
    inorder(H->left, L);
    // cout << H->elem << " ";
    L.push_back(H);
    if (L.size() == 2)
    {
        L.front()->next = L.back();
        L.pop_front();
    }
    
    inorder(H->right, L);
}

class node_ite  //Bộ lặp xuôi
{
	public:
        node *curr;

		node*&getCurr() {return curr;}
		node_ite(node*c = NULL) {curr=c;}

		node_ite& operator = (node_ite const &it)  //toan tu gan
		{
			//cout<<"gan";
			this->curr = it.curr;
			return *this;
		}

		bool operator!=(node_ite it)
		{
            return curr != it.curr;
        }
        
		ll &operator*(){return curr->elem;}

		node_ite operator++()  //++it
		{
			curr = curr->next;
			return curr;
		}

		node_ite operator++(int)  //it++
		{
			node*p = curr;
			curr = curr->next;
			return p;
		}
};


class Group
{
    node *root;
    public:
        void nhap()
        {
            ll n;
            cin >> n;
            root = new node(n);
        }

    // Thiết lập bộ lặp
    typedef node_ite iterator;
    iterator begin()
    {
        list <node*> L;
        inorder(root, L);
        node *p = root;
        while(p->left) p = p->left;
        return p;
    }

    iterator end()
    {
        return NULL;
    }
};


void sol()
{
    Group G;
    G.nhap();
    for (auto i : G) cout << i << " ";
}

int main()
{
	sol();
}

