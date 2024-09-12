#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


template <class T>
class node
{
    public:
		T value;
		ll n; // n: số con của node kể cả node: 1 + size(left) + size(right) 
		node *left, *right;
		node(T x, node<T> *L = NULL, node<T> *R = NULL, ll _n = 1)
		{
			n = _n;
			value = x;
			left = L;
			right = R;
		}
};

template<class T>
void update(node<T> *H, T x)
{
	// Nếu chưa có node nào, khởi tạo node gốc mang giá trị là x
	if(!H) H = new node<T>(x);

	// Nếu phần tử chuẩn bị thêm có giá trị >= gốc
	else if (H->value <= x)
	{
		// Tạo 1 node mới có con bên trái là gốc cũ, bên phải không có con
		// Số phần tử bằng số phần tử của gốc cũ + 1
		// Sau đó node này sẽ được coi là gốc mới 
		H = new node<T>(x, H, 0, H->n + 1);
	} 
	// Nếu phần tử mới < gốc
	else 
	{
		H->n++;
		// Nếu bên trái gốc không có con nào thì thêm vào bên trái
		if (!H->left) H->left = new node<T>(x);
		// Hoặc bên phải không có thì thêm bên phải
		else if (!H->right) H->right = new node<T>(x);
		// Nếu cả 2 bên đều có con rồi thì so sánh xem bên nào ít con hơn thì thêm vào bên đấy
		else update(H->left->n < H->right->n ? H->left:H->right, x);
	}
}

template<class T>
// Xóa đi node H
void remove(node<T> *&H)
{
	// Nếu cây chưa có phần tử nào thì thoát 
	if (!H) return;


	H->n--;
	// Nếu bên trái không có phần tử nào thì con bên phải H sẽ thay thế vị trí của H
	if (!H->left) H = H->right;
	// Tương tự nếu bên trái không có con
	else if (!H->right) H = H->left;
	// Nếu cả 2 bên đều có con
	else 
	{
		// Nếu giá trị node con bên trái < bên phải
		if (H->left->value < H->right->value)
		{
			// Giá trị của node này gán = giá trị node con bên phải
			H->value = H->right->value;
			// Thực hiện xóa node con bên phải
			remove(H->right);
		}
		// Tương tự nếu bên trái > bên phải
		else 
		{
			H->value = H->left->value;
			remove(H->left);
		}
	}
}

//My Code
void sol()
{
	node<int> *root = NULL;
	for (auto i : {60, 42, 73, 56, 81, 12, 43}) update(root, i);
	while(root)
	{
		cout << root->value << " ";
		remove(root);
	}
}

int main()
{
	sol();
}

