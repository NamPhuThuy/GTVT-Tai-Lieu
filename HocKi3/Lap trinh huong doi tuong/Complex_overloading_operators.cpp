#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
	
    Complex()
    {
        this->real = 0;
        this->imag = 0;
    }

    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void setReal(double real){this->real = real;}
    double getReal(){return this->real;}

    void setImag(double imag){this->imag = imag;}
    double getImag(){return this->imag;}

    Complex operator + (Complex a)
    {
        Complex ans;
        ans.setReal(this->real + a.getReal());
        ans.setImag(this->imag + a.getImag());
        return ans;
    }

    Complex operator - (Complex a)
    {
        Complex ans;
        ans.setReal(this->real - a.getReal());
        ans.setImag(this->imag - a.getImag());
        return ans;
    }

    Complex operator * (Complex a)
    {
        Complex ans;
        ans.setReal(this->real*a.getReal() - this->imag*a.getImag());
        ans.setImag(this->real*a.getImag() + a.getReal()*this->imag);
        return ans;
    }

    Complex operator / (Complex a)
    {
        Complex tmp = Complex(this->real, this->imag), tmp2 = Complex(a.getReal(), -a.getImag());
        Complex numerator = tmp * tmp2;
        double denominator = pow(a.getReal(), 2) + pow(a.getImag(), 2);

        Complex ans = Complex(numerator.getReal() / denominator, numerator.getImag() / denominator);
        return ans;
    }

    // Friend functions
    friend istream& operator >> (istream& input, Complex &a);
    friend ostream& operator << (ostream& output, Complex &a);
};

istream& operator >> (istream& input, Complex &a)
{
	input >> a.real >> a.imag;
	return input;
}

ostream& operator << (ostream& output, Complex & a)
{
	cout << a.real;
    if (a.imag < 0) cout << " - " << -a.imag << "i";
    else cout << " + " << a.imag << "i";
	return output;
}

int main()
{	
    Complex Arr[4];
   
    cout << "Insert complex numbers array: \n";
    for (int i = 0; i < 4; i++)
    {
        cin >> Arr[i];
    }

    Complex ans = (Arr[0] + Arr[1]) * Arr[2] / (Arr[0] - Arr[3]) + Arr[1];
   
	Complex tmp = (Arr[0] + Arr[1]);
    cout << "A[0] + A[1] = "; cout << tmp << endl;
    cout << ans;
}
