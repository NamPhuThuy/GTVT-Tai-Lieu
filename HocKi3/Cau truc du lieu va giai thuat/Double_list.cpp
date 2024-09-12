#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
    public:
        T value;
        node *next, *prev;
        node(T e = 0, node *P = NULL, node *N = NULL) 
        {
            value = e;
            prev = P;
            next = N;
        }
};

template <class T>
class dlist_ite  //Bộ lặp xuôi
{
	node<T> *curr;
	public:

		node<T>*&getCurr() {return curr;}
		dlist_ite(node<T>*c = NULL) {curr = c;}

		dlist_ite<T>& operator = (dlist_ite<T> const &it)  //Toán tử gán
		{
			cout << "phep gan";
			this->curr = it.curr;
			return *this;
		}

		bool operator!=(dlist_ite<T> it){return curr != it.curr; cout << "ehey";} // Toán tử copy
		T &operator*(){return curr->value;} // done

		dlist_ite<T> operator++()  //++it, done
		{
			curr = curr->next;
			return curr;
		}

		dlist_ite<T> operator++(int)  //it++, done
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


template<class T>
class dlist   // Danh sách liên kết kép
{
	node<T> *Head, *Tail; // Hai con trỏ quản lý phần tử đầu và cuối
	int n;                // Kích thước dlist
	public:
		// Constructors / Destructor
		dlist() 
		{
			Head = Tail = NULL; 
			n = 0;
		}

        dlist(int k, T x) // đang lỗi, khởi tạo dlist có k phần tử x
        {
            Head = Tail = NULL;
            // n = k;
            while(k--) push_back(x);
        }

		~dlist()
		{
            while(Head)
            {
                node<T> *p = Head;
                Head = Head->next;
                delete p;
            }
		}

		int size() {return n;}
		bool empty() {return n == 0;}
		T &front() {return Head->value;}
		T &back() {return Tail->value;}
		T &operator[](int k)            
		{
			node<T> *p = Head;
			while(k--) p = p->next;
			return p->value;
		}

        T id(int k)
        {
            node<T> *p = Head;
			while(k--) p = p->next;
			return p->value;
        }

		void push_back(T x)
		{
			if(n == 0) Head = Tail = new node<T>(x);
			else 
            {
				// Lệnh được thực hiện từ phải qua trái
                // Tạo 1 node mới, giá trị là x, phần tử đứng trước là Tail, phần tử đứng sau là NULL
				// Node mới này được đặt là node kế tiếp của Tail hiện tại 
				// Sau đó node mới này được coi là Tail (mới)
                Tail = Tail->next = new node<T>(x, Tail, NULL);
            }
			n++;
		}

        void push_front(T x)
		{
			if(n == 0) Head = Tail = new node<T>(x);
			else Head = Head->prev = new node<T>(x, NULL, Head);
			n++;
		}

		void pop_back()
		{
			if(n == 1)
            {
                delete Head;
                Head = Tail = NULL;
            } 
			else
			{
				Tail = Tail->prev;
                delete Tail->next;
                Tail->next = NULL;
			}
			n--;
		}

		void pop_front()
		{
			if(n == 1)
            {
                delete Head;
                Head = Tail = NULL; 
            } 
			else
			{
				Head = Head->next;
                delete Head->prev;
                Head->prev = NULL;
			}
			n--;
		}

		typedef dlist_ite<T> iterator;
		iterator begin(){return Head;} // done
		iterator end(){return NULL;} // done

        typedef dlist_rite<T> reverse_iterator;
		reverse_iterator rbegin(){return Tail;}
		reverse_iterator rend(){return NULL;}

		void insert(iterator it, T x) // done
		{
			// it.getCurr() trả về node mà it trỏ tới 
			node<T>*p = it.getCurr();

			// Nếu vị trí cần trỏ vào là vị trí của node Head thì thực hiện push_front()
			if (p == Head) push_front(x);
			// Nếu không thì:
            else 
            {	
				// Tạo node q chứa node phía trước của node p
                node<T> *q = p->prev;
				// Tạo node mới có giá trị x, node trước là q node sau là p
                q->next = p->prev = new node<T>(x, q, p);
            }

			// Ví dụ vị trí cần chèn là 3, nó sẽ đẩy node đang ở vị trí số 3 lên 4
			// Tạo node mới A có prev là node 2, next là node 4
			// Sau đó gán next của node 2 là A, prev của node 4 là A
            n++;
		}

		void erase(iterator it) // done
		{
			node<T> *p = it.getCurr();
			if (p == Head) pop_front();
			else if (p == Tail) pop_back();
			else 
			{
				node<T> *q = p->prev, *r = p->next;
                q->next = r;
                r->prev = q;
				delete p;
			}
            n--;
		}

// 		// ok = true: sort tăng dần, ok = false: sort giảm dần
		void sort(bool ok = true) // done
		{
			if (n <= 1) return;
			for (node<T> *p = Head; p != NULL; p = p->next)
				for (node<T> *q = p->next; q != NULL; q = q->next)
					if((p->value > q->value) == ok) swap(p->value, q->value);
		}
};

int main()
{
    dlist <int> L2;
    for (int x : {7, 8, 9}) L2.push_back(x);
    for (int x : {1, 2, 3}) L2.push_front(x);

	// dlist <int> L = L2;
	

	cout << "\nHavent sorted: ";
	for (int i = 0; i < L2.size(); i++) cout << L2[i] << " ";

    L2.sort();

	cout << "\nSorted: ";
    for (int i = 0; i < L2.size(); i++) cout << L2[i] << " ";

	dlist<int>::iterator it = L2.begin();
	it++; it++;
	L2.erase(it);
    cout << "\nDuyet xuoi: "; 
    for (auto i : L2) cout << i << " ";

    cout << "\nDuyet nguoc: ";
	// for (dlist<int>::iterator it = L2.end(); it != L2.begin(); it--) cout << *it << " ";
	// cout << *L2.begin();
}


