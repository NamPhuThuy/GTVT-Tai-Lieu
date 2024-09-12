#include<bits/stdc++.h>
using namespace std;

class Point
{
    private:
        double x, y;
        

    public:
    	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
        double getX(){return x;}
        double getY(){return y;}

        void setX(double _x){this->x = _x;}
        void setY(double _y){this->y = _y;}
        friend ostream& operator << (ostream& out, Point& a);
        friend istream& operator >> (istream& in, Point& a);
        
        void operator = (Point& );
};

ostream& operator << (ostream& out, Point& a)
{
    out << "(" << a.x << ", " << a.y << ")" << " ";
    return out;
}

istream& operator >> (istream& in, Point& a)
{
    in >> a.x >> a.y;
    return in;
}

void Point::operator = (Point& a)
{
    this->setX(a.getX());
    this->setY(a.getY());
}

class Line : public Point
{
    private:
        Point a, b;
        
    
    public:
    	
    	Line(Point _a = Point(0, 0), Point _b = Point(0, 0))
		{
			a = _a; 
			b = _b;
		}
        double Length();

        Point &getFirstPoint(){return a;}
        Point &getLastPoint(){return b;}
        friend ostream& operator << (ostream& out, Line& a);
        friend istream& operator >> (istream& in, Line& a);
        Line operator = (Line&);
};

istream& operator >> (istream& in, Line& a)
{
    in >> a.a >> a.b;
    return in;
}

ostream& operator << (ostream& out, Line& a)
{
    out << a.a << a.b;
    return out;
}

double Line::Length()
{
    double tmp = getFirstPoint().getX() - getLastPoint().getX(), tmp2 = getFirstPoint().getY() - getLastPoint().getY();
    return sqrt(tmp*tmp + tmp2*tmp2);
}

Line Line::operator = (Line& a)
{
	Line ans;
	ans.getFirstPoint() = a.getFirstPoint();
	ans.getLastPoint() = a.getLastPoint();
	return ans;
} 

class Func
{
    private:
        Line *arr;
        int n; 
        

    public: 
    	Func(Line *_arr = NULL, int _n = 0) : arr(_arr), n(_n){};
    	int &getN(){return n;}
        Line* getArr(){return arr;}
		
    	friend ostream& operator << (ostream& out, Func& a);
        friend istream& operator >> (istream& in, Func& a);
        
};

istream& operator >> (istream& in, Func& a)
{
    cout << "Nhap so doan thang: ";
    in >> a.n;
    cout << a.n << endl;
    a.arr = new Line[a.n + 1];
    for (int i = 0; i < a.n; i++)
    {
        cout << "Nhap doan thang thu " << i + 1 << ": ";
        in >> a.arr[i];
    }
    return in;
}

ostream& operator << (ostream& out, Func& a)
{
    for (int i = 0; i < a.n; i++)
    {
        out << "\nHai diem tao ra doan thang thu " << i << " la : ";
        out << a.arr[i];
    }
    return out;
}

int main()
{
	Point a, b;
	cout << "Nhap 2 diem a, b: \n";
    cin >> a >> b;
   
    cout << "Hai diem vua nhap: \n";
    cout << a << b << endl;

	Line A(a, b);
	cout << "Do dai doan thang ab:\n" << A.Length() << endl;
	cout << "Doan thang ab: \n" << A;
	
	Line C;
	cout << "\nNhap doan thang C:\n";
	cin >> C;
	cout << "Doan thang vua nhap:\n";
	cout << C;
	cout << "Do dai doan thang C: " << C.Length();


    cout << "Nhap danh sach doan thang: \n";
    Func f = Func();
    cin >> f;
    cout << f;
}
   
