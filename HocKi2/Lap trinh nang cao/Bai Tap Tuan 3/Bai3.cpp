#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Monhoc
{
	char maMH[5];
	char tenMH[20];
	int soTC;
};

struct Kyhoc
{
	char maKH[5];
	int soMH;
	Monhoc* ds;
};

void nhapMH(Monhoc* a, int i)
{
	printf("Mon hoc thu %d:\n", i);
	printf("   Ma mon hoc: ");
	fflush(stdin); gets(a->maMH);
	printf("   Ten mon hoc: ");
	fflush(stdin); gets(a->tenMH);
	printf("   So tin chi: ");
	scanf("%d", &a->soTC);
}

Monhoc* nhapMH(int n)
{
	Monhoc* a = (Monhoc*) malloc(n * sizeof(Monhoc));
	for (int i = 0; i < n; i++)
	{
		nhapMH(&a[i], i+1);
	}
	return a;
}

void xuatMH(int n, Monhoc* a)
{
	printf(" MaMH                TenMH  SoTC\n");
	for (int i = 0; i < n; i++)
	{
		printf("%5s %20s %5d\n", a[i].maMH, a[i].tenMH, a[i].soTC);
	}
}

void nhapKH(Kyhoc* a, int i)
{
	printf("Ky hoc thu %d:\n", i);
	printf("   Ma ky hoc: ");
	fflush(stdin); gets(a->maKH);
	printf("   So mon hoc: ");
	scanf("%d", &a->soMH);
	printf("   Danh sach cac mon hoc:\n");
	a->ds = nhapMH(a->soMH);
}

Kyhoc* nhapKH(int n)
{
	Kyhoc* a = (Kyhoc*) malloc(n * sizeof(Kyhoc));
	for (int i = 0; i < n; i++)
	{
		nhapKH(&a[i], i+1);
	}
	return a;
} 

void xuatKH(int n, Kyhoc* a)
{
	for (int i = 0; i < n; i++)
	{
		printf("Ma ki hoc: %s\n", a[i].maKH);
		printf("So mon hoc: %d\n", a[i].soMH);
		printf("Danh sach cac mon hoc:\n");
		xuatMH(a[i].soMH, a[i].ds);
	}
}

int main()
{
	int n, m;
	printf("Nhap so luong cac mon hoc: ");
	scanf("%d", &n);
	printf("\nNhap lan luot thong tin cua %d mon hoc:\n", n);
	Monhoc* a = nhapMH(n);
	printf("\nDanh sach cac mon hoc:\n");
	xuatMH(n, a);
	
	printf("Nhap so luong ky hoc: ");
	scanf("%d", &m);
	printf("\nNhap lan luot thong tin cua %d ky hoc:\n", m);
	Kyhoc* b = nhapKH(m);
	printf("\nDanh sach cac ky hoc:\n");
	xuatKH(m, b);
}