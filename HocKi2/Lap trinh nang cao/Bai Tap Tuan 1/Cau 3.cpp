#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>

int** nhapMT(int* m, int* n, int** a)
{
	printf("Nhap so hang cua ma tran: ");
	scanf("%d", m);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", n);
	
	a = (int**) malloc((*m + 1) * sizeof(int*));
	for (int i = 0; i < *m; i++)
	{
		a[i] = (int*) malloc((*n+1) * sizeof(int));
	}
	
	printf("Nhap lan luot gia tri cua cac phan tu:\n");
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	return a;
}

void xuatMT(int m, int n, int** a)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", a[i][j]);
		}
		printf("\n");
	}
}

float tinhTBCChan(int m, int n, int** a, int* check)
{
	float tong = 0;
	int dem = 0;
	*check = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				tong += a[i][j];
				dem += 1;
				*check = 1;
			}
		}
	}
	return tong/dem;
}

float tinhTBNLe(int m, int n, int** a, int* check)
{
	float tong = 0;
	int dem = 0;
	*check = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				tong += a[i][j];
				dem += 1;
				*check = 1;
			}
		}
	}
	return pow(tong, 1.0/dem);
}

int* tinhTongTungHang(int m, int n, int** a, int* b)
{
	b = (int*) malloc((m + 1) * sizeof(int));
	
	for (int i = 0; i < m; i++)
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

void xuatDay(int m, int* a)
{
	for (int i = 0; i < m; i++)
	{
		if (i != m-1) printf("%d, ", a[i]);
		else printf("%d.\n", a[i]);
	}
}

int timMaxDay(int m, int* a)
{
	int max = INT_MIN;
	int vitri = 0;
	for (int i = 0; i < m; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			vitri = i;
		}
	}
	return vitri;
}

int main()
{
	int m, n;
	int** a = nhapMT(&m, &n, a);
	printf("Ma tran vua nhap la:\n");
	xuatMT(m, n, a);
	
	int check;
	float tbc = tinhTBCChan(m, n, a, &check);
	if (check == 0) printf("Ma tran khong co phan tu chan nao!\n");
	else printf("Trung binh cong cua cac phan tu chan trong ma tran bang %.2f\n", tbc);
	
	float tbn = tinhTBNLe(m, n, a, &check);
	if (check == 0) printf("Ma tran khong co phan tu le nao!\n");
	else printf("Trung binh nhan cua cac phan tu le trong ma tran bang %.2f\n", tbn);
	
	int* b = tinhTongTungHang(m, n, a, b);
	printf("Tong tung hang lan luot la: ");
	xuatDay(m, b);
	
	int vt = timMaxDay(m, b);
	printf("Hang co tong lon nhat trong ma tran la Hang %d\n", vt);
	
	free(a);
	free(b);
	return 0;
}