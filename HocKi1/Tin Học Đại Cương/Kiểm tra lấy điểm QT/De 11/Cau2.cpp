#include <stdio.h>
void NHAP(float a[100][100], int m, int n)
{
	printf("\nNhap cac phan tu vao Ma tran co %dx%d:\n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d] = ", i, j);
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
	int cot = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				cot = j + 1;
			}
		}
	}
	printf("\nPhan tu co gia tri lon nhat bang %.2f va nam o cot %d!\n", max, cot);
}
void YC2(float a[100][100], int m, int n)
{
	float maxhang = 0;
	int hang = 0;
	for (int i = 0; i < m; i++)
	{
		float tonghang = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0) tonghang += a[i][j];
		}
		printf("\nTong cac phan tu duong cua hang thu %d bang %.2f", i+1, tonghang);
		if (maxhang < tonghang) 
		{
			maxhang = tonghang;
			hang = i+1;
		}
	}
	printf("Vay hang co tong phan tu duong lon nhat la hang %d!\n", hang);
}
void YC3(float a[100][100], int m, int n)
{
	float tich = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0) tich *= a[i][j];
		}
	}
	printf("\nTich cua cac phan tu duong trong Ma tran A bang %.2f", tich);
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
	YC2(a, m, n);
	YC3(a, m, n);
}