#include <stdio.h>
#include <math.h>
struct DIEM
{
	float x;
	float y;
};
void NHAP(DIEM a[100], int n)
{
	printf("\nNhap toa do cua %d diem can xet:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("(x%d, y%d) = ",i , i);
		scanf("%f%f", &a[i].x, &a[i].y);
	}
}
void XUAT(DIEM a[100], int n)
{
	printf("\n%d diem vua duoc nhap bao gom: ", n);
	for (int i = 0; i < n; i++)
	{
		printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
	}
	printf("\n");
}
void YC1(DIEM a[100], int n)
{
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x < 0 && a[i].y < 0) dem1++;
	}
	printf("\nCo tat ca %d diem thuoc goc phan tu thu 3!\n", dem1);
}
void YC2(DIEM a[100], int n)
{
	int dem2 = 0;
	float R; printf("\nNhap do dai cua ban kinh R: "); scanf("%f", &R);
	for (int i = 0; i < n; i++)
	{
		float bk = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (bk > R)
		{
			dem2++;
		}
	}
	printf("Co tat ca %d diem nam ngoai duong tron tam O ban kinh R, do la: ");
	for (int i = 0; i < n; i++)
	{
		float bk = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (bk > R)
		{
			printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
		}
	}
	printf("\n");
}
void YC3(DIEM a[100], int n)
{
	float x1 = a[0].x, x2 = a[0].x, y1 = a[0].y, y2 = a[0].y;
	for (int i = 0; i < n; i++)
	{
		if (x1 < a[i].x) x1 = a[i].x;
		if (x2 > a[i].x) x2 = a[i].x;
		if (y1 < a[i].y) y1 = a[i].y;
		if (y2 > a[i].y) y2 = a[i].y;
	}
	float c1 = x1 + abs(x2);
	float c2 = y1 + abs(y2);
	printf("\nDien tich cua hinh chu nhat nho nhat, co cac canh song song voi he truc toa do nho nhat, chua tat ca cac diem bang %.2f", c1 * c2);
}
main()
{
	int n; printf("Nhap so luong diem can xet: "); scanf("%d", &n);
	DIEM a[n];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}