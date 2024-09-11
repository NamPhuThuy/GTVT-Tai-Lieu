#include<stdio.h>
#include<string.h>
#include<math.h>

const int max = 100;

void insertArr(double A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &A[i]);
	}
}

double sum1(double A[][max], int u, int v, int n)
{
	double sum = A[u][v];
	int a = u, b = v;
	while(u > 0 && v < n-1) sum += (A[--u][++v]);
	while(a < n-1 && b > 0) sum += (A[++a][--b]);
	return sum;
}

double determinant(double A[][max])
{
	return A[0][0]*A[1][1]*A[2][2] + A[0][1]*A[1][2]*A[2][0] + A[1][0]*A[2][1]*A[0][2] - A[2][0]*A[1][1]*A[0][2] - A[1][0]*A[0][1]*A[2][2] - A[2][1]*A[1][2]*A[0][0];
}

int main()
{
	int n; scanf("%d", &n);
	double A[max][max];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		scanf("%lf", &A[i][j]);
	
	int u, v; scanf("%d%d", &u, &v);
	printf("%lf\n", sum1(A, u, v, n));
	
	if (n == 3) printf("%lf", determinant(A));
}
