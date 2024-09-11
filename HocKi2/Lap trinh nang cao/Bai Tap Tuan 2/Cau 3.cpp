#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

struct DaThuc
{
	int n;
	float* hs;
};

DaThuc nhapDT(DaThuc a)
{
	printf("Nhap bac cua da thuc: ");
	scanf("%d", &a.n);
	a.hs = (float*) malloc((a.n+1) * sizeof(float));
	printf("Nhap lan luot cac he so cua da thuc:\n");
	for (int i = 0; i <= a.n; i++)
	{	
		printf("a[%d] = ", i);
		scanf("%f", &a.hs[i]);
	}
	return a;
}

void xuatDT(DaThuc a)
{
	for (int i = 0; i <= a.n; i++)
	{
		if (i == 0) printf("%.2f + ", a.hs[i]);
		else if (i != a.n) printf("%.2f*x^%d + ", a.hs[i], i);
		else printf("%.2f*x^%d\n", a.hs[i], i);
	}
}

float tinhBT(DaThuc a, float x)
{
	float bt = 0;
	for (int i = 0; i <= a.n; i++)
	{
		bt += a.hs[i] * pow(x, i);
	}
	
	float dh = 0;
	for (int i = 1; i <= a.n; i++)
	{
		dh += a.hs[i] * i * pow(x, i-1);
	}
	
	float ct = x + sqrt(bt + dh + 2023);
	
	return ct;
}

float timHeSoMax(DaThuc a)
{
	float max = FLT_MIN;
	for (int i = 0; i <= a.n; i++)
	{
		if (a.hs[i] > max) max = a.hs[i];
	}
	return max;
}

float tinhTongHeSoAm(DaThuc a, int* check)
{
	*check = 0;
	float tong = 0;
	for (int i = 0; i <= a.n; i++)
	{
		if (a.hs[i] < 0)
		{
			tong += a.hs[i];
			*check = 1;
		}
	}
	return tong;
}

float* xuatHeSoDaThucHieu(DaThuc a, DaThuc b, int* k)
{
	if (a.n > b.n)
	{
		float* dt;
		dt = (float*) malloc((a.n + 1) * sizeof(float));
		*k = a.n;
		
		for (int i = 0; i <= b.n; i++)
		{
			dt[i] = a.hs[i] - b.hs[i];
		}
		for (int i = b.n + 1; i <= a.n; i++)
		{
			dt[i] = a.hs[i];
		}
		return dt;
	}
	else if (a.n < b.n) 
	{
		float* dt;
		dt = (float*) malloc((b.n + 1) * sizeof(float));
		*k = b.n;
		
		for (int i = 0; i <= a.n; i++)
		{
			dt[i] = a.hs[i] - b.hs[i];
		}
		for (int i = a.n + 1; i <= b.n; i++)
		{
			dt[i] = b.hs[i];
		}
		return dt;
	}
	else return 0;
}

void xuatDay(float* a, int k)
{
	for (int i = 0; i <= k; i++)
	{
		if (i != k) printf("%.2f, ", a[i]);
		else printf("%.2f.\n", a[i]);
	}
}
int main()
{
	// Nhap, xuat da thuc P
	DaThuc p = nhapDT(p);
	printf("Da thuc P vua nhap la: ");
	xuatDT(p);
		
	// Nhap so thuc x, tinh bieu thuc S
	float x;
	printf("\nNhap so thuc x bat ky: ");
	scanf("%f", &x);
	float ct = tinhBT(p, x);
	printf("Gia tri cua bieu thuc bang %.2f\n", ct);
	
	// Nhap da thuc Q bac m, in ra man hinh he so cua da thuc hieu trong truong hop khac bac
	printf("\n");
	DaThuc q = nhapDT(q);
	printf("Da thuc Q vua nhap la: ");
	xuatDT(q);
	int k;
	float* dt = xuatHeSoDaThucHieu(p, q, &k);
	if (dt == 0) printf("Hai da thuc P va Q cung bac!\n");
	else
	{
		printf("Day he so da thuc hieu P(x) - Q(x) la: ");
		xuatDay(dt, k);
	} 
	
	// Tim he so lon nhat cua da thuc
	float max = timHeSoMax(p);
	printf("\nHe so lon nhat cua da thuc P la: %.2f\n", max);
	
	// Tinh tong cac he so am co trong da thuc
	int check;
	float tong = tinhTongHeSoAm(p, &check);
	if (check == 0) printf("\nDa thuc P khong chua he so am!\n");
	else printf("\nTong cac he so am cua da thuc P bang %.2f\n", tong);
	
	free(p.hs);
	free(q.hs);
	free(dt);
	
	return 0;
}