#include <stdio.h>
void NHAP(int a[100][100], int m, int n)
{
	printf("\nNhap cac phan tu vao Ma tran A co %dx%d:\n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void XUAT(int a[100][100], int m, int n)
{
	printf("\nMa tran A co %dx%d vua nhap la:\n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}
void YC1(int a[100][100], int m, int n)
{
	int tongch = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 != 0) tongch += a[i][j];
		}
	}
	printf("\nTong cac phan tu nam tren cot co chi so chan bang %d\n", tongch);
}
void YC2(int a[100][100], int m, int n)
{
	int test1 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j-i] == 0)
			{
				test1 = 0;
			}
			else test1++;
			j++;
		}
	}
	if (test1 == 0) printf("Ma tran A la mot Ma tran tam giac vuong!");
	else printf("Ma tran A khong phai la mot Ma tran tam giac vuong!");
}
void YC3(int a[100][100], int m, int n)
{
	int tongh = 0;
	for (int i = 0; i < m; i++)
	{
		int tongh = 0;
		for (int j = 0; j < n; j++)
		{
			tongh += a[i][j];
		}
		printf("Tong cua hang %d bang %d\n", i+1, tongh);
	}
}
main()
{
	int m, n;
	printf("Nhap so hang cua Ma tran A: "); scanf("%d", &m);
	printf("Nhap so cot cua Ma tran A: "); scanf("%d", &n);
	int a[100][100];
	NHAP(a, m, n);
	XUAT(a, m, n);
	YC1(a, m, n);
	YC3(a, m, n);
}