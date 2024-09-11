#include <stdio.h>
#include <math.h>
void NHAP(int a[100], int n)
{
	printf("\nNhap %d phan tu vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void XUAT(int a[100], int n)
{
	printf("\nDay so vua duoc nhap bao gom cac phan tu: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
}
void YC1(int a[100], int n)
{
	int demch = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) demch++;
	}
	printf("\nDay so co tat ca %d phan tu chan!\n", demch);
}
void YC2(int a[100], int n)
{
	int x; printf("\nNhap gia tri cua so nguyen x: "); scanf("%d", &x);
	int demlx = 0;
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > x)
		{
			demlx++;
			tong += a[i];
		}
	}
	printf("Trung binh cong cua cac so co gia tri tuyet doi lon hon x bang %.2f\n", tong*1.0 / demlx);
}
void YC3(int a[100], int n)
{
	int tang = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i-1] > a[i])
		{
			tang++;
		}
	}
	if (tang == n-1) printf("\nDay so la day so tang dan!");
	else printf("\nDay so khong phai la day so tang dan!");
}
main()
{
	int n; printf("Nhap so luong phan tu dau vao cua day so: "); scanf("%d", &n);
	int a[100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}