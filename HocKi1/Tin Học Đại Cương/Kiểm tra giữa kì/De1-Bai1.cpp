#include <stdio.h>
#include <math.h>
void NHAP(float a[], int n)
{
	printf("\nNhap %d phan tu vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu a[%d] = ", i+1);
		scanf("%f", &a[i]);
	}
}
void XUAT(float a[], int n)
{
	printf("\nDay so vua nhap la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%.2f, ", a[i]);
		else printf("%.2f\n", a[i]);
	}
}
void TBN(float a[], int n)
{
	float tich = 1, dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) 
		{
			tich *= a[i];
			dem++;
		}
	}
	if (dem == 0) printf("\nDay so khong co so duong!");
	else
	{
		float TBN = pow(tich, 1.0/dem);
		printf("\nTrung binh nhan cac so duong cua day so bang %.2f", TBN);
	}
}
void MAX(float a[], int n)
{
	float max = sin(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (max < sin(a[i])) max = sin(a[i]);
	}
	printf("\nGia tri lon nhat cua day sin(a1), sin(a2), ..., sin(an) la %.2f", max);
}
void DDD(float a[], int n)
{
	int test = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i-1] < a[i]) test++;
		else if (a[i-1] > a[i]) test--;
	}
	if (test != n-1) printf("\nDay so ban dau duoc nhap la 1 day don dieu!");
	else if (test == n-1 || test == -(n-1)) printf("\nDay so ban dau duoc nhap khong phai la 1 day don dieu!");
}
main()
{
	int n;
	re:
	printf("Nhap so luong phan tu cua day so: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	float a[n];
	NHAP(a, n);
	XUAT(a, n);
	TBN(a, n);
	MAX(a, n);
	DDD(a, n);
}
