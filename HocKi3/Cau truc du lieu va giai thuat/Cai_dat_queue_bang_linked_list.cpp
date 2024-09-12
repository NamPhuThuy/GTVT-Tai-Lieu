#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T>
class node
{
    public:
        T value;
        node *next; // con trỏ chứa địa chỉ của ô tiếp theo

        node(T x)
        {
            value = x; 
            next = NULL;
        }
};

template <class T>
class Queue
{
    node <T> *Head, *Tail; // Chứa địa chỉ của phần tử đầu và cuối
    ll n; // Số lượng phần tử

    public:
        Queue()
        {
            Head = Tail = NULL; 
            n = 0;
        }

        ~Queue()
        {
            // Khi mà vẫn còn node Head thì sẽ tiếp tục thực hiện xóa
            while(Head != NULL)
            {
                node<T> *p = Head;
                Head = Head->next;
                delete p;
            }
        }

        ll size(){return n;}
        bool empty(){return n == 0;}

        // "&": Ngoài việc đọc thì ta có thể thay đổi dứ liệu của front() và back()
        T &front() {return Head->value;}
        T& back() {return Tail->value;}
        void push(T x)
        {
            // Chọn cách để thêm phần tử mới vào
            int choose = 2;
            
            // cách 1
            if (choose == 1)
            {
                // Nếu như queue có nhiều hơn 1 phần tử
                if (n > 0)
                {
                    node <T> *p = new node<T>(x);
                    // Phần tử kế tiếp của đuôi hiện tại sẽ được gán bằng p
                    Tail->next = p;

                    // Sau đó, p sẽ trở thành đuôi mới
                    Tail = p;
                }
                // Nếu queue rỗng
                else 
                {
                    //Khởi tạo Head
                    Head = new node <T>(x);

                    //Tail và Head sẽ cùng trỏ đến 1 phần tử
                    Tail = Head;
                }
            }

            // cách 2
            if (choose == 2)
            {
                // Cũng tương tự như trên nhưng viết tắt hơn 
                if (n == 0) Head = Tail = new node<T>(x);
                else Tail = Tail->next = new node<T>(x);
                n++;
            } 
        }

        void pop()
        {
            // Tạo 1 con trỏ p trỏ tới node Head 
            node<T> *p = Head;

            // node sau node Head hiện tại được gán thành node Head mới 
            Head = Head->next;

            // Xóa node p: tương đương node Head cũ
            delete p;

            // Giảm số lượng phần tử đi 1 đơn vị
            n--;
        }
};

int main()
{	
	Queue<ll> q;
    for (ll x : {1 , 2 , 3 , 4 , 5, 6, 7}) q.push(x);
    q.front() = 9;
    q.back() = 10;
    while(q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
