#include <stdio.h>
#include <math.h>
struct DIEM
{
	float x;
	float y;
};
void NHAP(DIEM a[100], int n)
{
	printf("\nNhap lan luot toa do cua %d diem:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("(x%d, y%d) = ", i, i);
		scanf("%f%f", &a[i].x, &a[i].y);
	}
}
void XUAT(DIEM a[100], int n)
{
	printf("\nCac diem vua nhap la: ");
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
		if (a[i].y > a[i].x) dem1++;
	}
	printf("\nCo tat ca %d diem nam phia tren duong phan giac cua goc phan tu thu nhat.", dem1);
	printf("\nDo la: ");
	for (int i = 0; i < n; i++)
	{
		if (a[i].y > -a[i].x) printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
	}
	printf("\n");
}
void YC2(DIEM a[100], int n)
{
	float x1, x2, y1, y2;
	for (int i = 0; i < n; i++)
	{
		if (x1 < a[i].x) x1 = a[i].x;
		if (x2 > a[i].x) x2 = a[i].x;
		if (y1 < a[i].y) y1 = a[i].y;
		if (y2 > a[i].y) y2 = a[i].y;
	}
	float c1 = x1 + abs(x2);
	float c2 = y1 + abs(y2);
	printf("Dien tich cua hcn nho nhat co 4 canh cua chieu dai va chieu rong song song voi truc toa do chua tat ca cac diem bang %.2f", c1 * c2);
}
main()
{
	int n; printf("Nhap so luong diem dau vao: "); scanf("%d", &n);
	DIEM a[100];
	YC1(a, n);
	YC2(a, n);
}