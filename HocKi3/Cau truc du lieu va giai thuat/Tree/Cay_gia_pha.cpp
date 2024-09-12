#include<bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
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

// Cập nhật node theo cách duyệt trung thứ tự
void update(node *&H, string a, string b)
{
	if (H->child.size()) update(H->child[0], a, b);

	// Khi tìm thấy node a thì thực hiện gán node b là con của node a
	if (H->name == a) 
	{
		node *tmp = new node(b, 0, H->deep + 1);

		H->child.push_back((node*)tmp);
		H->num++;
        return;
	}

	for (ll i = 1; i < H->child.size(); i++) update(H->child[i], a, b);
}

// Duyệt trung thứ tự để in ra cây gia phả: con cả -> gốc -> các con còn lại
void inorder2(node *&H)
{
	// đánh dấu số lượng con nhiều nhất có cùng 1 cha
	maxChild = max(maxChild, H->num);
	// lưu độ sâu lớn nhất trong cây
	height = max(H->deep, height);

	//Nếu node H có con thì thực hiện duyệt con cả trước
	if (H->child.size()) inorder2(H->child[0]);
	cout << H->name << " ";
	// Sau đó duyệt nốt các con còn lại
	for (ll i = 1; i < H->child.size(); i++) inorder2(H->child[i]);
}

void sol()
{
	ll n; cin >> n;
	
	// y là con là x
	string x, y; cin >> x >> y;

	// Tạo nút gốc, tên: x, số con: 0, độ sâu: 1
	node *root = new node(x, 0, 1);

	// Đứa con đầu của gốc, tên: y, số con: 0, độ sâu: 2
    node *tmp = new node(y, 0, 2);

	// Thêm vào danh sách con của gốc và tăng số con của gốc thêm 1 
	root->child.push_back(tmp);
    root->num++;

	// Trừ 2 vì đã có thao tác tạo nút gốc cùng con của nó, và n người thì chỉ có n-1 quan hệ 
	n -= 2;
	while(n--)
	{
		// Nhập vào tên của 2 người a, b
		string a, b; cin >> a >> b;
		// Cập nhật thêm b là con của a 
		update(root, a, b);
	}
	
	inorder2(root);
	cout << endl;
	cout << "Node co nhieu con nhat: " << maxChild << endl;
	cout << "Tree's height: " << height << endl;
}

int main()
{
	freopen("Test_cay_gia_pha.txt", "r", stdin);
	sol();
}