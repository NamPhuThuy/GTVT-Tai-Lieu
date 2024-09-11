#include <stdio.h>
void NHAP(int a[100], int n)
{
	printf("\nNhap %d phan tu nguyen duong vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		re:
		printf("Phan tu a[%d] = ", i+1);
		scanf("%d", &a[i]);
		if (a[i] < 0) goto re;
	}
}
void XUAT(int a[100], int n)
{
	printf("\nDay so nguyen duong vua duoc nhap la: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void YC1(int a[100], int n)
{
	int x; printf("\nNhap so nguyen x: "); scanf("%d", &x);
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) dem1 = 0;
		else if (a[i] != x) dem1 = 1;
	}
	if (dem1 == 0) printf("So nguyen x co nam trong day so!\n");
	else if(dem1 == 1) printf("So nguyen x khong nam trong day so!\n");
}
void YC2(int a[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp = a[i];
			if (a[i] > a[j])
			{
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	if (n == 1) printf("\nDay so chi co 1 phan tu nen phan tu lon nhat la: %d\n", a[0]);
	else if (n == 2) printf("\nDay so chi co 2 phan tu nen 2 phan tu lon nhat lan luot la: %d va %d\n", a[n-1], a[n-2]);
	else if (n >= 3)printf("\n3 phan tu lon nhat trong day so lan luot la: %d, %d va %d\n", a[n-1], a[n-2], a[n-3]);
}
void YC3(int a[100], int n)
{
	float S = 0;
	for (int i = 1; i < n; i++)
	{
		S += (a[i-1] + a[i])*1.0 / (a[i-1] - a[i]);
	}
	if (n == 1) printf("\nTong cua bieu thuc da cho bang 1");
	else if (n >= 2) printf("\nTong cua bieu thuc da cho bang %.2f", S);
}
main()
{
	int n; printf("Nhap so luong phan tu cua day: "); scanf("%d", &n);
	int a[100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}