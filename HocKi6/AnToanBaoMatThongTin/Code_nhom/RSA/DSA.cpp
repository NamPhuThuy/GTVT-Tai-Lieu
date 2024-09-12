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
	//int p,q,h,xa,k;
	int HM = 2;
// 	cout<<"Nhap p: "; cin>>p;
//	cout<<"Nhap q: "; cin>>q;
//	cout<<"Nhap h: "; cin>>h;
//	cout<<"Nhap xa: "; cin>>xa;
//	cout<<"Nhap k: "; cin>>k;
	string filename = "inputDSA.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "kh doc dc" << filename << endl;
        return 1;
    }

    // Khai báo bi?n d? luu giá tr? t? t?p
    int p, q, h, xa, k;

    inputFile >> p >> q >> h >> xa >> k;
	
	int g = binhphuong(h,(p-1)/q,p);
	cout<<"gia tri g = "<<g<<'\n';
	
	int y = binhphuong(g,xa,p);
	cout<<"gia tri y = "<<y<<'\n';
	
	int r = (binhphuong(g,k,p))%q;
	cout<<"gia tri r = "<<r<<'\n';
	
	int s = (nghichdao(k,q)*((HM+xa*r)%q))%q;
	cout<<"gia tri s = "<<s<<'\n';
	
	int w = nghichdao(s,q);
	cout<<"gia tri w = "<<w<<'\n';
	
	int u1 = (HM*w)%q;
	cout<<"gia tri u1 = "<<u1<<'\n';
	int u2 = (r*w)%q;
	cout<<"gia tri u2 = "<<u2<<'\n';
	
	int v = ((binhphuong(g,u1,p)*binhphuong(y,u2,p))%p)%q;
	
	cout<<"gia tri v = "<<v<<'\n';
	cout<<"gia tri r = "<<r<<'\n';
	
	string filename1 = "outputDSA.txt";
	ofstream outputFile(filename1);
	  outputFile << g << " " << y << " " << r << " " << s << " " << w << " " << u1 << " " << u2;
	outputFile.close();

	
}

