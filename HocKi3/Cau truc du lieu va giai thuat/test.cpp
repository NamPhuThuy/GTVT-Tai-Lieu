#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{
	public:
	T elem;
	node *left, *right, *next;
	node (T x)
	{
		left = right = next = NULL;
		elem = x;
	}
};

template <class T>
void update(node<T>*&H, int x)
{
	if (!H) H = new node<T>(x);
	if (x == H->elem) return;
	else if (x < H->elem) update(H->left, x);
	else update(H->right, x);
}

template <class T>
void inorder(node<T>*H, string p = "\n")
{
	if (!H) return;
	inorder(H->left, p + "\t");
	cout << p << H->elem;
	inorder(H->right, p + "\t");
    
}

template <class T>
void remove(node<T>*&H, int x)
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


template <class T>
class node_ite  //Bộ lặp xuôi
{
	node<T> *curr;
	public:
		node<T>*&getCurr() {return curr;}
		node_ite(node<T>*c = NULL) {curr = c;}

		node_ite<T>& operator = (node_ite<T> const &it)  //Toán tử gán
		{
			cout << "phep gan";
			this->curr = it.curr;
			return *this;
		}

		bool operator!=(node_ite<T> it){return curr != it.curr; cout << "ehey";} // Toán tử copy
		T &operator*(){return curr->value;} // done

		node_ite<T> operator++()  //++it, done
		{
			curr = curr->next;
			return curr;
		}

		node_ite<T> operator++(int)  //it++, done
		{
			node<T>*p = curr;
			curr = curr->next;
			return p;
		}
};

// Bộ lặp ngược 
template <class T> 
class dlist_rite  
{
	node<T> *curr;
	public:
		node<T>*&getCurr() {return curr;}
		dlist_rite(node<T>*c = NULL) {curr=c;}

		dlist_rite<T>& operator = (dlist_rite<T> const &it)  //toan tu gan
		{
			//cout<<"gan";
			this->curr = it.curr;
			return *this;
		}

		bool operator!=(dlist_rite<T> it)
		{
			return curr != it.curr;
		}

		T &operator*(){return curr->value;}

		dlist_rite<T> operator++()  //++it
		{
			curr = curr->prev;
			return curr;
		}

		dlist_rite<T> operator++(int)  //it++
		{
			node<T>*p = curr;
			curr = curr->prev;
			return p;
		}
};

void sol()
{
	int n, x; cin >> n;
	node<T>* root = NULL;
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

int main()
{
    freopen("Input.txt", "r", stdin);
	sol();
}

