#include <stdio.h>
void NHAP(int a[100][100], int n)
{
	printf("\nNhap cac phan tu vao Ma tran vuong A cap %d:\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d]: ", i, i);
			scanf("%d", &a[i][j]);
		}
	}
}
void XUAT(int a[100][100], int n)
{
	printf("\nMa tran A vua duoc nhap vao la:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}
void YC1(int a[100][100], int n)
{
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0) dem1++;
		}
	}
	printf("\nCo tat ca %d phan tu chan trong Ma tran A!\n");
}
void YC2(int a[100][100], int n)
{
	float tongdcc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) tongdcc += a[i][j];
		}
	}
	printf("\nTrung binh cong cac phan tu nam tren duong cheo chinh bang %.2f\n", tongdcc*1.0 / n);
}
void YC3(int a[100][100], int n)
{
	int max = a[0][0];
	int pos1 = 0, pos2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				pos1 = i;
				pos2 = j;
			}
		}
	}
	printf("\nPhan tu co gia tri lon nhat trong ma tran la: A[%d][%d] = %d", pos1, pos2, max);
}
main()
{
	int n; printf("Nhap bac cua Ma tran A: "); scanf("%d", &n);
	int a[100][100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}