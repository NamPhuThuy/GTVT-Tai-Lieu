#include <stdio.h>
#include<string.h>
#include<math.h>

const int max = 1e3;

double Cal(double A[], double B[], double x, int m, int n)
{
	double ans = 0, ans1 = 0;
	for (int i = 0; i < m; i++)
	{
		ans += (A[i]*pow(x, m-i));
	}
	
	printf("P[%lf] = %lf \n", x, ans);
	
	for (int i = 0; i < n; i++)
	{
		ans1 += (B[i]*pow(x, n-i));
	}
	
	printf("Q[%lf] = %lf\n", x, ans1);
	printf("P[%lf] + Q[%lf] = %lf\n", x, x, ans+ans1);
}

void insertArr(double A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &A[i]);
	}
}


int main()
{
	double A[max], B[max];
	int m, n; scanf("%d%d", &m, &n);
	
	insertArr(A, m);
	insertArr(B, n);
	
	printf("P = ");
	for (int i = 0; i < m-1; i++) printf("%lfx^%d + ", A[i], i+1);
	printf("%lfx^%d\n", A[m-1], m);
	
	
	printf("Q = ");
	for (int i = 0; i < n-1; i++) printf("%lfx^%d + ", B[i], i+1);
	printf("%lfx^%d\n", B[n-1], n);
	
	double C[max];
	for (int i = 0; i < max; i++) C[i] = 0;
	for (int i = 0; i < n; i++) C[i] += B[i];
	for (int i = 0; i < m; i++) C[i] += A[i];
	int o;
	(m>n)? (o=m) : (o=n);
	
	printf("R = ");
	for (int i = o-1; i > 0; i--) printf("%lfx^%d + ", C[i], i + 1);
	printf("%lfx%d\n", C[0], o);
	
	double x; scanf("%lf", &x);
	Cal(A, B, x, m, n);
	
}
