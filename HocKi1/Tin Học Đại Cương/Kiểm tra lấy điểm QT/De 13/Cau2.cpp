#include <stdio.h>
void NHAP(float a[100][100], int n)
{
	printf("\nNhap cac phan tu vao Ma tran vuong A cap %d:\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
}
void XUAT(float a[100][100], int n)
{
	printf("\nMa tran vuong A cap %d vua nhap la:\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%7.2f ", a[i][j]);
		}
		printf("\n");
	}
}
void YC1(float a[100][100], int n)
{
	
}
main()
{
	int n; printf("Nhap cap cua Ma tran A: "); scanf("%d", &n);
	float a[100][100];
	NHAP(a, n);
	XUAT(a, n);
	
}