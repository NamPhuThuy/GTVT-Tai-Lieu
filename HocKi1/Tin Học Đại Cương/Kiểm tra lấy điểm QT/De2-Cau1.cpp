#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
struct ToaDo
{
	float x;
	float y;
};
void NhapDay(ToaDo a[], int n)
{
	printf("Nhap lan luot cac diem vao day:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\t(x%d, y%d) = ", i+1, i+1);
		scanf("%f%f", &a[i].x, &a[i].y);
	}
}
void InDay(ToaDo a[], int n)
{
	printf("Day diem vua nhap la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1)
		{
			printf("(%.2f, %.2f), ", a[i].x, a[i].y);
		}
		else printf("(%.2f, %.2f).\n", a[i].x, a[i].y);
	}
}
int DemGoc3(ToaDo a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x < 0 && a[i].y < 0) dem++;
	}
	return dem;
}
void TimMaxO(ToaDo a[], int n)
{
	float max = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		float kc = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (kc > max) max = kc;
	}
	for (int i = 0; i < n; i++)
	{
		float kc = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (kc == max)
		{
			printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
		}
	}
	printf("\n");
}
int DemCatOx(ToaDo a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i].y * a[j].y < 0 || a[i].x == 0 || a[j].x == 0 )
			{
				dem++;
			}
		}
	}
	return dem;
}
int main()
{
	// Nhap so luong diem cua day so
	int n;
	re1:
	printf("Nhap so luong diem cua day: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	// 
	ToaDo a[n];
	NhapDay(a, n);
	InDay(a, n);
	
	// Dem so diem thuoc goc phan tu thu 3
	printf("Co tat ca %d diem thuoc goc phan tu thu 3.\n", DemGoc3(a, n));
	
	// Tim cac diem xa goc toa do nhat
	printf("Cac diem nam xa goc toa do nhat la: ");
	TimMaxO(a, n);
	
	// Dem so doan thang cat truc hoanh
	printf("Co tat ca %d doan thang cat truc hoanh.", DemCatOx(a, n));
}