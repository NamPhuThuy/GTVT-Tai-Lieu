

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    virtual void f()
    {
        cout << "A\n";
    }
};


class B : public A
{
    public: 
    virtual void f()
    {
        cout << "B\n";
    }
};

class C : public B
{
    public: 
    virtual void f()
    {
        cout << "C\n";
    }
};
//My Code
void sol( )
{
    

}

int main()
{
    A a; a.f();
    B b; b.f();
    C c; c.f();
}