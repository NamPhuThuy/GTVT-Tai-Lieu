#include <stdio.h>
#include <math.h>
void NHAP(float a[100], int n)
{
	printf("\nNhap %d he so cua da thuc P(x) bac %d:\n", n+1, n);
	for (int i = 0; i <= n; i++)
	{
		printf("He so thu %d: ", i+1);
		scanf("%f", &a[i]);
	}
}
void XUAT(float a[100], int n)
{
	printf("\nDa thuc P(x) bac %d la: P(x) = ", n);
	for (int i = n; i >= 0; i--)
	{
		int pos1 = abs(i-n);
		if (i != 0) printf("(%.2f)x^%d + ", a[pos1], i);
		else if (i == 0) printf("(%.2f)", a[pos1]);
	}
}
void YC1(float a[100], int n)
{
	float x; printf("Nhap gia tri cua so thuc x: "); scanf("%f", &x);
	float s = 0;
	float S = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i != n) s += a[i]*pow(x, n-i);
		else if (i == n) s += a[i];
	}
}
main()
{
	int n; printf("Nhap bac cua da thuc P(x): "); scanf("%d", &n);
	float a[100];
	NHAP(a, n);
	XUAT(a, n);
}