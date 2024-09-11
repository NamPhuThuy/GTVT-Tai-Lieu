#include<stdio.h>
#include <math.h>

// 5 4 
// 1 2 2 3 1
// 3 2 1 2 1 
// 1 2 


int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
void insertPolynomial(float a[], int m)
{
	for(int i = 0; i < m; i++)
	{
		scanf("%f", &a[i]);
	}
}
void printPolynomial(float a[], int m)
{
	for(int i = 0; i < m; i++)
	{
		printf("%.2f*x^%d ", a[i], i);
	}
	printf("\n");
}

void sumOfPolynomials(float a[], float b[], float c[], int m, int n)
{
	if(m > n)
    {
		for(int i = 0; i < n; i++)
		{ 
			c[i] = a[i] + b[i];
		}
		
		for (int i = n; i < m; i++) c[i] = a[i];
	}
	else
	{
		for(int i = 0; i < m; i++) 
		{
       		c[i] = a[i] + b[i];
	   	}
	   	for (int i = m; i < n; i++) c[i] = b[i];
	}
}
double value(float a[], int m, float d)
{
	double sum = 0;
	for(int i = 0; i < m; i++)
	{
		sum += (a[i]*d);
	}
	return sum;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	float P[1000], Q[1000], R[1000], x1, x2, sum;
	int m, n; scanf("%d%d", &m, &n);
	printf("\nnhap da thuc P\n");
	insertPolynomial(P, m);
	printf("P = "); printPolynomial(P, m);

	printf("\nnhap da thuc Q\n");
	insertPolynomial(Q, n);
	printf("Q = "); printPolynomial(Q, n);

	sumOfPolynomials(P, Q, R, m, n);
	printf("\nR = "); printPolynomial(R, max(m, n));
	scanf("%f%f", &x1, &x2);

	sum = value(P,m,x1) + value(Q,n,x2);
	printf("\ntong hai da thuc la = %f ",sum);
	
}
