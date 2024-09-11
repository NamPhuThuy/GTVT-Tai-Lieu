#include <stdio.h>
#include <math.h>
void NHAP(float a[100], int n)
{
	printf("\nNhap %d phan tu vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu a[%d] = ", i+1);
		scanf("%f", &a[i]);
	}
}
void XUAT(float a[100], int n)
{
	printf("\nDay so vua nhap bao gom cac phan tu: ");
	for (int i = 0; i < n; i++)
	{
		printf("%.2f  ", a[i]);
	}
}
void YC1(float a[100], int n)
{
	float max = a[0];
	for (int i = 1; i < n; i++)
	{
		float temp = a[i] / (i+1);
		if (max < temp) max = temp;
	}
	printf("\n\nGia tri lon nhat cua day so de yeu cau la: %.2f", max);
}
void YC2(float a[100], int n)
{
	int tongd = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) tongd += a[i];
	}
	printf("\n\nTong cua cac phan tu duong trong day so bang %.2f", tongd);
}
void YC3(float a[100], int n)
{
	float x; printf("\n\nNhap vao so thuc x: "); scanf("%f", &x);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > x) dem++;
	}
	printf("\nCo tat ca %d phan tu co gia tri tuyet doi lon hon x!", dem);
}
main()
{
	int n; printf("Nhap so luong phan tu cua day so thuc: "); scanf("%d", &n);
	float a[n];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}