#include<bits/stdc++.h>
using namespace std;

// Lớp cơ sở ảo
// class A
// {
//     int a;  
// };

// class C : virtual public A
// {

// };

// class B : virtual public A
// {

// };

// class D :  public B,  public C
// {

// };


// Phương thức ảo
class A
{
    public: 
    void f()
    {
        cout << "A\n";
    }
};


class B : public A
{
    public: 
    void f()
    {
        cout << "B\n";
    }
};

class C : public B
{
    public: 
    void f()
    {
        cout << "C\n";
    }
};

void dahinh (A *p)
{
    p->f();
}

int main()
{

    A *p, a; B b; C c;
    
    dahinh(&a);
    dahinh(&b);
    dahinh(&c);
    
    // a.f(); b.f(); c.f();


    // p = &a; p->f();
    // p = &b; p->f();
    // p = &c; p->f();
}