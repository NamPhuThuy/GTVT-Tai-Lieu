#include <stdio.h>
#include <float.h>
#include <limits.h>
void NhapMaTran(int a[][100], int m, int n)
{
	printf("Nhap lan luot cac phan tu cua ma tran:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\tPhan tu a[%d][%d] = ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
}
void XuatMaTran(int a[][100], int m, int n)
{
	printf("Ma tran vua nhap la:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%7d", a[i][j]);
		}
		printf("\n");
	}	
}
int TinhTongCotLe(int a[][100], int m, int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 0)
			{
				tong += a[i][j];
			}
		}
	}
	return tong;
}
float TinhTBCChanLon10(int a[][100], int m, int n)
{
	float TBC = 0, dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0 && a[i][j] > 10)
			{
				TBC += a[i][j];
				dem++;
			}
		}
	}
	TBC = TBC / dem;
	return TBC;
}
int TimMax(int a[][100], int m, int n)
{
	int max = INT_MIN;
	for (int i= 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < a[i][j]) max = a[i][j];
		}
	}
	return max;
}
int main()
{
	int m, n;
	// Nhap va kiem tra so hang
	re1:
	printf("Nhap so hang cua Ma tran: ");
	scanf("%d", &m);
	if (m <= 0)
	{
		printf("So luong hang toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	// Nhap va kiem tra so cot
	re2:
	printf("Nhap so cot cua Ma tran: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong cot toi thieu la 1. Vui long nhap lai!\n");
		goto re2;
	}
	int a[100][100];
	NhapMaTran(a, m, n);
	XuatMaTran(a, m, n);
	
	// Tinh tong cac phan tu thuoc cot le cua ma tran
	printf("Tong cac phan tu thuoc cot le cua ma tran bang %d\n", TinhTongCotLe(a, m, n));
	
	// Tinh trung binh cong cac phan tu chan lon hon 10 trong ma tran
	printf("TBC cac phan tu chan lon hon 10 cua ma tran bang %.3f\n", TinhTBCChanLon10(a, m, n));
	
	// Tim gia tri lon nhat cua ma tran
	printf("Gia tri lon nhat cua ma tran la %d", TimMax(a, m, n));
}
