#include<bits/stdc++.h>
using namespace std;


template<class T>
struct node
{
	T elem; // Gía trị của node
	node *next; // Con trỏ, trỏ tới node tiếp theo
	node(T e, node *N = NULL) 
	{
		elem = e;
		next = N;
	}
};

template <class T>
class slist_ite  //Bộ lặp xuôi
{
	node<T> *curr;
	public:
		node<T>*&getCurr(){return curr;}
		slist_ite(node<T>*c = NULL) {curr = c;}

		slist_ite<T>& operator=(slist_ite<T> const &it)  //toan tu gan
		{
			//cout<<"gan";
			this->curr=it.curr;
			return *this;
		}

		bool operator!=(slist_ite<T> it)
		{
			return curr!=it.curr;
		}
		T &operator*(){return curr->elem;}

		slist_ite<T> operator++()  //++it
		{
			curr = curr->next;
			return curr;
		}

		slist_ite<T> operator++(int)  //it++
		{
			node<T>*p=curr;
			curr=curr->next;
			return p;
		}
};
template<class T>
class slist               //danh sach lien ket don
{
	node<T> *Head,*Tail;   //Hai con tro nam lay dau va duoi
	int n;                  //size
	public:
		slist() {Head=Tail=NULL; n=0;}
		~slist()
		{
			if(n>0)
			{
				for(node<T>*p=Head->next;p!=NULL;p=p->next)
				{
					delete Head;
					Head=p;
				}
				delete Head;
				n=0;
				Head=Tail=0;
			}
		}
		int size() {return n;}
		bool empty() {return n==0;}
		T &front() {return Head->elem;}
		T &back() {return Tail->elem;}
		T &operator[](int k)             //list trong STL khong co ham nay
		{
			node<T> *p=Head;
			while(k--) p=p->next;
			return p->elem;
		}
		void push_front(T x)
		{
			if(n==0) Head=Tail=new node<T>(x);
			else Head=new node<T>(x,Head);
			n++;
		}
		void push_back(T x)
		{
			if(n==0) Head=Tail=new node<T>(x);
			else Tail=Tail->next=new node<T>(x);
			n++;
		}
		void pop_back()
		{
			if(n==1) {delete[]Head; Head=Tail=NULL;}
			else
			{
				node<T>*p=Head; 
				while(p->next!=Tail) p=p->next;
				delete Tail;
				Tail=p;
				Tail->next=NULL;
			}
			n--;
		}
		void pop_front()
		{
			if(n == 1) 
				{delete[]Head; Head=Tail=NULL;}
			else 
			{
				node<T>*p=Head; 
				Head=Head->next; 
				delete p;
			}
				
			n--;
		}
		typedef slist_ite<T> iterator;
		iterator begin(){return Head;}
		iterator end(){return NULL;}
		void insert(iterator it,T x)
		{
			node<T>*q=it.getCurr();
			node<T>*p=new node<T>(q->elem,q->next);
			q->next=p;
			q->elem=x;
			if(q==Tail) Tail=p;
			n++;
		}

		void erase(iterator it)
		{
			node<T> *p = it.getCurr();
			if (p == Head)
			{
				pop_front();
				it = Head;
			}
			else if (p == Tail)
			{
				pop_back();
				it = Tail;
			}
			else 
			{
				node<T> *q = Head;
				while (q->next != p)
					q = q->next;
				q->next = p->next;
				delete p;
				n--;
			}
		}

		// ok = true: sort tăng dần, ok = false: sort giảm dần
		void sort(bool ok = true)
		{
			if (n <= 1) return;
			for (node<T> *p = Head; p != NULL; p = p->next)
				for (node<T> *q = p->next; q != NULL; q = q->next)
					if((p->elem > q->elem) == ok) swap(p->elem, q->elem);
		}
};

int main()
{
	slist <int> L;
	for(int x:{1, 23, 655, 0, 90, 111, 200})
	x % 2 == 0 ? L.push_front(x) : L.push_back(x);

	cout<<"\nL: "; for(slist<int>::iterator it=L.begin();it!=L.end();it++) cout<<*it<<" ";
	
	slist<int>::iterator it1;
	it1 = L.begin();
	L.insert(it1,-5);
	cout<<"\nL: "; 
	for(auto z:L) cout<<z<<" ";
	
	it1=L.begin(); 
	for(int i=1;i<=5;i++) it1++;
	L.insert(it1,-3);
	cout<<"\nL: "; 
	for(auto z:L) cout<<z<<" ";
	
	it1=L.begin(); 
	for(int i=1;i<L.size();i++) it1++;
	cout<<"\n"<<*it1<<"\n";
	
	L.insert(it1,-7);
	cout<<"\nL: "; 
	for(auto z:L) cout<<z<<" ";
	
	L.push_back(100);
	cout<<"\nL: "; 
	for(auto z:L) cout<<z<<" ";

	L.erase(L.begin());
	cout<<"\nL: "; 
	for(auto z:L) cout<<z<<" ";



}


