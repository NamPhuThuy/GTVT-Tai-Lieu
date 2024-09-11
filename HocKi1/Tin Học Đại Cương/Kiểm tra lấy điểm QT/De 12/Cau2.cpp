#include <stdio.h>
void NHAP(float a[100][100], int m, int n)
{
	printf("\nNhap cac phan tu vao Ma tran co %dx%d:\n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d] = ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}
}
void XUAT(float a[100][100], int m, int n)
{
	printf("\nMa tran A vua nhap la:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%7.2f", a[i][j]);
		}
		printf("\n");
	}
}
void YC1(float a[100][100], int m, int n)
{
	float max = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			if (max < a[i][j])
			{
				max = a[i][j];
			}		
		}		
	}
	
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			if (max == a[i][j])
			{
				dem++;
			}		
		}		
	}
	printf("\nPhan tu co gia tri lon nhat bang %.2f!", max);
	printf("\nCo tat ca %d phan tu co gia tri bang gia tri lon nhat!", dem);
	
	printf("\nCac phan tu co gia tri bang gia tri lon nhat nam o cac vi tri: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			if (max == a[i][j])
			{
				printf("A[%d][%d]  ", i+1, j+1);
			}		
		}				
	}	
}

main()
{
	int m, n;
	printf("Nhap so hang cua Ma tran A: "); scanf("%d", &m);
	printf("Nhap so cot cua Ma tran A: "); scanf("%d", &n);
	float a[100][100];
	NHAP(a, m, n);
	XUAT(a, m, n);
	YC1(a, m, n);
}