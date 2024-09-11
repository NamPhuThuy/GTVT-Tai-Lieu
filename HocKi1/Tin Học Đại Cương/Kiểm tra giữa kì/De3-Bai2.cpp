#include <stdio.h>
void NHAP(float a[][100], int n)
{
	printf("Nhap cac phan tu vao ma tran A:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Phan tu A[%d][%d] = ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}
}
void XUAT(float a[][100], int n)
{
	printf("Ma tran vua nhap la:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5.2f ", a[i][j]);
		}
		printf("\n");
	}
}
void TBC(float a[][100], int n)
{
	float tbc = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if((i+j) > (n-1))
			{
				if (a[i][j] < 0)
				{
					tbc += a[i][j];
					dem++;
				}			
			}
		}
	}
	if (dem == 0) printf("\nKhong co so nao am nam duoi duong cheo phu cua ma tran A!\n");
	else printf("\nTrung binh cong cua cac so am nam duoi duong cheo phu cua ma tran A bang %.2f\n", tbc/dem);	
}
void TGD(float a[][100], int n)
{
	int test1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				if (a[i][j] == 0)
				{
					test1 = 0;
				}
				else 
				{
					test1 = 1;
					break;
				}
			}
		}
	}
	if (test1 == 0) printf("\nMa tran A la mot ma tran tam giac duoi!\n");
	else printf("\nMa tran A khong phai la mot ma tran tam giac duoi!\n");
}
void CV(float a[][100], int n)
{
	float b[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[j][i];
		}
	}
	printf("\nMa tran chuyen vi cua ma tran A la:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5.2f ", b[i][j]);
		}
		printf("\n");
	}
}
void DX(float a[][100], int n)
{
	int demdx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				if (a[i][j] == a[j][i]) demdx++;
			}
		}
	}
	printf("\nCo tat ca %d cap 2 phan tu doi xung qua duong cheo chinh cua ma tran A co gia tri bang nhau!", demdx);
}
main()
{
	int n;
	re:
	printf("Nhap bac cua ma tran A: ");
	scanf("%d", &n);
	if (n <= 1)
	{
		printf("Bac cua ma tran vuong toi thieu la 2. Vui long nhap lai!\n");
		goto re;
	}
	float a[100][100];
	NHAP(a, n);
	XUAT(a, n);
	TBC(a, n);
	TGD(a, n);
	CV(a, n);
	DX(a, n);
}