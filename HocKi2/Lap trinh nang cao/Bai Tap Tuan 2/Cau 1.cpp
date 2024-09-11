#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

int** nhapMT(int* n, int** a)
{
	printf("Nhap cap cua ma tran: ");
	scanf("%d", n);
	
	a = (int**) malloc((*n+1) * sizeof(int*));
	for (int i = 0; i < *n; i++)
	{
		a[i] = (int*) malloc((*n+1) * sizeof(int));
	}
	
	printf("Nhap lan luot gia tri cua cac phan tu:\n");
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	return a;
}

void xuatMT(int n, int** a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", a[i][j]);
		}
		printf("\n");
	}
}

int timMaxDCC(int n, int** a)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] > max) max = a[i][i];
	}
	return max;
}

float tinhTBCNhoHonX(int n, int** a, int x, int* check)
{
	int tong = 0, dem = 0;
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < x)
			{
				tong += a[i][j];
				dem += 1;
				*check = 1;
			}
		}
	}
	return (float)tong / dem;
}

int* tinhTongTungHang(int n, int** a, int* b)
{
	b = (int*) malloc((n + 1) * sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		int tong = 0;
		for (int j = 0; j < n; j++)
		{
			tong += a[i][j];
		}
		b[i] = tong;
	}
	
	return b;
}

void xuatHangTongMax(int n, int* b, int** a)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < a[i][j]) max = a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == max)
			{
				printf("%d  ", i);
			}
		}
	}
	printf("\n");
}

int* chuyenMTThanhDS(int n, int** a)
{
	int* ds;
	ds = (int*) malloc((n*n) * sizeof(int));
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ds[index++] = a[i][j];
		}
	}
	return ds;
}

void hoanVi(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sapXepDS(int n, int* ds)
{
	int soPT = n*n;
	for (int i = 0; i < soPT-1; i++)
	{
		for (int j = i+1; j < soPT; j++)
		{
			if (ds[i] > ds[j])
			{
				hoanVi(&ds[i], &ds[j]);
			}
		}
	}
}

int** chuyenDSThanhMT(int n, int* ds)
{
	int** a1;
	a1 = (int**) malloc((n+1) * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a1[i] = (int*) malloc((n+1) * sizeof(int));
	}
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a1[i][j] = ds[index++];
		}
	}
	return a1;
}

int main()
{
	int n;
	int** a = nhapMT(&n, a);
	printf("Ma tran cap %dx%d vua nhap la:\n", n, n);
	xuatMT(n, a);
	
	// Tim gia tri lon nhat tren duong cheo chinh
	int maxDCC = timMaxDCC(n, a);
	printf("\nGia tri lon nhat tren duong cheo chinh la: %d\n", maxDCC);
	
	// Tim gia tri trung binh cac phan tu nho hon gia tri x (x cho truoc)
	int x;
	printf("\nNhap gia tri x bat ky: ");
	scanf("%d", &x);
	int check;
	float tbc = tinhTBCNhoHonX(n, a, x, &check);
	printf("Trung binh cong cua cac phan tu nho hon gia tri x bang %.2f\n", tbc);
	
	// Tinh hang co tong lon nhat
	int* b = tinhTongTungHang(n, a, b);
	printf("\nHang co tong cac phan tu lon nhat la: ");
	xuatHangTongMax(n, b, a);
	
	// Sap xep ma tran theo thu tu tang dan tu trai sang phai, tu tren xuong duoi
	int* ds = chuyenMTThanhDS(n, a);
	sapXepDS(n, ds);
	int** a1 = chuyenDSThanhMT(n, ds);
	printf("\nMa tran sau khi sap xep theo yeu cau la:\n");
	xuatMT(n, a1);
	
	free(a);
	free(a1);
	free(b);
	
	return 0;
}