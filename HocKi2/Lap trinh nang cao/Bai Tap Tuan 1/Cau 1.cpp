#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>

struct CTY
{
	char maCT[5];
	char tenCT[30];
	int namTL;
	int soNV;
};

void nhapCT(CTY* a, int i)
{
	printf("\nCong ty thu %d:\n", i+1);
	
	// Nhap ma cong ty
	printf("Nhap ma cong ty: ");
	fflush(stdin);
	gets(a->maCT);
	
	// Nhap ten cong ty
	printf("Nhap ten cong ty: ");
	fflush(stdin);
	gets(a->tenCT);
	
	// Nhap nam thanh lap
	printf("Nhap nam thanh lap: ");
	scanf("%d", &a->namTL);
	
	// Nhap so nhan vien
	printf("Nhap so nhan vien: ");
	scanf("%d", &a->soNV);
}

CTY* nhapDS(int* n, CTY* a)
{
	// Nhap n
	re:
	printf("Nhap so luong cong ty: ");
	scanf("%d", n);
	if (*n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	// Cap phat bo nho dong
	a = (CTY*) malloc((*n+1) * sizeof(CTY));
	
	// Nhap lan luot n cong ty
	for (int i = 0; i < *n; i++)
	{
		nhapCT(&a[i], i);
	}
	
	return a;
}

void xuatCT(CTY a)
{
	printf("%10s %30s %10d %7d\n", a.maCT, a.tenCT, a.namTL, a.soNV);
}

void xuatDS(int n, CTY* a)
{
	for (int i = 0; i < n; i++)
	{
		xuatCT(a[i]);
	}
}

int timLauNamNhat(int n, CTY* a)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i].namTL) min = a[i].namTL;
	}
	return min;
}

CTY* timCTLauNam(int n, CTY* a, int* k, int min)
{
	CTY* b;
	b = (CTY*) malloc((n+1) * sizeof(CTY));
	*k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].namTL == min)
		{
			b[*k] = a[i];
			*k += 1;
		}
	}
	return b;
}

CTY* timCT(int n, CTY* a, int* k, int* x, int* y, int* check)
{
	printf("Nhap so luong lap trinh vien: ");
	scanf("%d", x);

	printf("Nhap nam thanh lap: ");
	scanf("%d", y);
	
	CTY* b;
	b = (CTY*) malloc((n+1) * sizeof(CTY));
	*k = 0;
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].soNV > *x && a[i].namTL < *y)
		{
			b[*k] = a[i];
			*k += 1;
			*check = 1;
		}
	}
	
	return b;
}

int main()
{
	int n;
	CTY* a = nhapDS(&n, a);	
	printf("Danh sach thong tin cua %d cong ty vua nhap la:\n", n);
	xuatDS(n, a);
	
	int nam1 = timLauNamNhat(n, a);
	int k;
	CTY* a1 = timCTLauNam(n, a, &k, nam1);
	printf("Cac cong ty thanh lap lau nam nhat la:\n");
	xuatDS(k, a1);
	
	int x, y, check;
	CTY* a2 = timCT(n, a, &k, &x, &y, &check);
	if (check == 0) printf("Khong co cong ty nao thoa man!\n");
	else 
	{
		printf("Cac cong ty co nhieu hon %d nhan vien va thanh lap truoc nam %d la:\n", x, y);
		xuatDS(k, a2);
	}
	
	free(a);
	return 0;
}
