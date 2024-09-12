#include<bits/stdc++.h>
using namespace std;
int nghichdao(int a,int n)
{
	for(int i=2;i<=a+n;i++)
	{
		if((a*i)%n==1) return i;
	}
}
int binhphuong(int a,int m,int n)
{
	int res =1,nho=a;
	long kq;
	while(1)
	{
		int mu = m/2;
		if(mu==0) break;
		
		if(m%2)
		{
			res = (res*a)%n;
//			res = (res*nho)%n;
		} 
		kq = a*a % n;
		m/=2;
				
		a = kq;

	}

	return (a*res)%n;
}
int main(){
	int q,a,xa;
//	cout<<"Nhap q: "; cin>>q;
//	cout<<"Nhap a: "; cin>>a;
//	cout<<"Nhap xa: "; cin>>xa;
	string filename = "inputElg.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "kh doc dc" << filename << endl;
        return 1;
    }
    
	
	int k,M;
//	
//	cout<<"Nhap k: "; cin>>k;
//	cout<<"Nhap M: "; cin>>M;
	inputFile >> q>>a>>xa>>k>>M;
		int ya = binhphuong(a,xa,q);
	
	int K = binhphuong(ya,k,q);
	int c1 = binhphuong(a,k,q);
	int c2 = (K*M)%q;
	
	// giai ma
	int K_ = binhphuong(c1,xa,q);
	int M_ = ((c2%q)*(nghichdao(K_,q)))%q;
	
	cout<<"PU = {"<<q<<","<<a<<","<<ya<<"}\n";
	cout<<"(C1,C2) = ("<<c1<<","<<c2<<")\n";
	cout<<"M_ = "<<M_;
	string filename1 = "outputElg.txt";
ofstream outputFile(filename1);
    outputFile << q << " " << a << " " << ya << "\n " << c1 << " " << c2 << " \n" << M_ ;

    // Ðóng t?p sau khi hoàn thành
    outputFile.close();

    // M? t?p d? ghi
    outputFile.close();
	inputFile.close();
}

