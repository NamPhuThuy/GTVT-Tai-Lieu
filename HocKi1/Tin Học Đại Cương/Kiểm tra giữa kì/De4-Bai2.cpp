#include <stdio.h>
void NHAP(int a[][100], int n, int m)
{
	printf("Nhap cac phan tu vao ma tran A:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Phan tu A[%d][%d] = ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
}
void XUAT(int a[][100], int n, int m)
{
	printf("Ma tran vua nhap la:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}
void MAX(int a[][100], int n, int m)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < 10)
			{
				if (max < a[i][j]) max = a[i][j];
			}
		}
	}
	if (max > 10) printf("\nMa tran khong co phan tu nao nho hon 10!\n");
	else printf("\nPhan tu lon nhat trong cac so nho hon 10 cua ma tran la %d\n", max);
}
void TICH(int a[][100], int n, int m)
{
	int tich = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j) tich *= a[i][j];
		}
	}
	printf("\nTich cua cac phan tu nam o vi tri co chi so hang bang cho so cot bang %d\n", tich);
}
void TBC(int a[][100], int n, int m)
{
	float tbc = 0;	
	for (int j = 0; j < m; j++)
	{
		float tichcot = 1;
		for (int i = 0; i < n; i++)
		{
			tichcot *= a[i][j];
			tbc += tichcot;
		}
	}
	printf("\nTrung binh cong cua tich cac cot cua ma tran A bang %.2f\n", tbc/m);
}
void KIEMTRA(int a[][100], int n, int m)
{
	if (m == n) 
	{
		int tongbt = 0;
		printf("\nMa tran A la mot ma tran vuong!");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i+j) < (n-1))
				{
					tongbt += a[i][j];
				}
			}
		}
		printf("\nTong cua cac phan tu nam phia ben tren duong cheo phu bang %d", tongbt);
	}
	else printf("\nMa tran A khong phai la mot ma tran vuong!");
}
main()
{
	printf("Tuy chinh kich co cua Ma tran A:\n");
	int n;
	re:
	printf("\tSo hang cua ma tran A: ");
	scanf("%d", &n);
	if (n <= 1)
	{
		printf("So hang cua ma tran toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	int m;
	re1:
	printf("\tSo cot cua ma tran A: ");
	scanf("%d", &m);
	if (m <= 1)
	{
		printf("So cot cua ma tran toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	int a[100][100];
	NHAP(a, n, m);
	XUAT(a, n, m);
	MAX(a, n, m);
	TICH(a, n ,m);
	TBC(a, n, m);
	KIEMTRA(a, n, m);
}