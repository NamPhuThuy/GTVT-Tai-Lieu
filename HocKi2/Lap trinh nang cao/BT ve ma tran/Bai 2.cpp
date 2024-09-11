#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* nhapDT(int *n, float* a, char name)
{
	re:
	printf("Nhap bac cua da thuc %c: ", name);
	scanf("%d", n);
	if (n < 0)
	{
		printf("Bac toi thieu phai lon hon 0. Vui long nhap lai!\n");
		goto re;
	}
	
	a = (float*) malloc((*n+1) * sizeof(float));
	for (int i = 0; i < *n+1; i++)
	{
		printf("Nhap he so a[%d]: ", i);
		scanf("%f", (a+i));
	}
	return a;
}

void xuatDT(int n, float* a)
{
	for (int i = 0; i < n+1; i++)
	{
		if (i == 0) printf("%.2f + ", *(a+i));
		else if (i != n) printf("%.2f * x^%d + ", *(a+i), i);
		else printf("%.2f * x^%d\n", *(a+i), i);
	}
}

float tinhDTX(int n, float* a, float x)
{	
	float kq = 0;
	for (int i = 0; i < n+1; i++)
	{
		kq += a[i] * pow(x, i);
	}
	return kq;
}

int main()
{
	int n, m;
	float* a = nhapDT(&n, a, 'P');
	printf("Da thuc P(x) = "); 
	xuatDT(n, a);
	
	float* b = nhapDT(&m, b, 'Q');
	printf("Da thuc Q(x) = ");
	xuatDT(m, b);
	
	float x;
	printf("Nhap so thuc x bat ky: ");
	scanf("%f", &x);
	float kqP = tinhDTX(n, a, x);
	float kqQ = tinhDTX(m, b, x);
	printf("Ket qua cua phep chia da thuc P(x)/Q(x) = %.2f\n", kqP / kqQ);
}