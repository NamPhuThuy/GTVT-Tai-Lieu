#include <stdio.h>
#include <math.h>
struct DIEM
{
	float x;
	float y;
};
void NHAP(DIEM a[100], int n)
{
	printf("\nNhap toa do cua %d diem:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("(x%d, y%d) = ", i, i);
		scanf("%f%f", &a[i].x, &a[i].y);
	}
}
void XUAT(DIEM a[100], int n)
{
	printf("\nCac diem vua duoc nhap la: ");
	for (int i = 0; i < n; i++)
	{
		printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
	}
	printf("\n");
}
void YC1(DIEM a[100], int n)
{
	float max = sqrt(pow(a[1].x - a[0].x, 2) + pow(a[1].y - a[0].y, 2));
	int pos1 = 0; int pos2 = 1;
	for (int i = 1; i < n; i++)
	{
		float dt = sqrt(pow(a[i].x - a[i-1].x, 2) + pow(a[i].y - a[i-1].y, 2));
		if (max < dt) 
		{
			max = dt;
			pos1 = i-1;
			pos2 = i;
		}
	}
	printf("\nDoan thang dai nhat duoc tao boi 2 diem co toa do lan luot la (%.2f, %.2f) va (%.2f, %.2f) co do dai bang %.2f\n", a[pos1].x, a[pos1].y, a[pos2].x, a[pos2].y, max);
}
void YC2(DIEM a[100], int n)
{
	float a1, b; printf("\nNhap lan luot 2 so thuc a va b: "); scanf("%f%f", &a1, &b);
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].y == a1 * a[i].x + b) dem1++;		
	}
	if (b < 0) printf("Co ta ca %d diem thuoc duong thang y = %.2fx - %.2f\n", dem1, a1, abs(b));
	else if (b > 0) printf("Co ta ca %d diem thuoc duong thang y = %.2fx + %.2f\n", dem1, a1, b);
	else if (b == 0) printf("Co ta ca %d diem thuoc duong thang y = %.2fx\n", dem1, a1);
}
void YC3(DIEM a[100], int n)
{
	int dem2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].y > a[i].x) dem2++; 
	}
	printf("\nCo tat ca %d diem nam phia tren duong phan giac cua goc phan tu thu nhat!", dem2);
}
main()
{
	int n; printf("Nhap so luong diem nhap vao: "); scanf("%d", &n);
	DIEM a[100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
}