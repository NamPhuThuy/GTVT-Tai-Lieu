#include <stdio.h>
#include <math.h>
void NHAP(int a[], int n)
{
	printf("\nNhap %d so nguyen vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("So nguyen thu %d: a%d = ", i+1, i+1);
		scanf("%d", &a[i]);
	}
}
void XUAT(int a[], int n)
{
	printf("Day so nguyen vua nhap la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1)
		{
			printf("%d, ", a[i]);
		}
		else printf("%d\n", a[i]);
	}
}
void MAX(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max && a[i] % 4 == 0)
		{
			max = a[i];
		}
	}
	if (max % 4 == 0) printf("\nGia tri lon nhat cua nhung so chia het cho 4 trong day la: %d\n", max);
	else printf("\nDay so khong co gia tri nao chia het cho 4!\n");
}
void TINH(int a[], int n)
{
	float tong = 0;
	int test = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] == 0)
		{
			test = 1;
			break;
		}
		else
		{
			tong += a[i]*1.0 / a[i+1];
		}
	}
	if (test == 1)
	{
		printf("\nKhong tinh duoc gia tri cua bieu thuc vi co phan tu bang 0!\n");
	}
	else 
	{
		if (a[n-1] == 0) printf("\nKhong tinh duoc gia tri cua bieu thuc vi co phan tu bang 0!\n");
		else 
		{
			tong += a[n-1]*1.0 / a[0];
		printf("\nGia tri cua bieu thuc a1/a2 + a2/a3 + ...+ an-1/an + an/a1 bang %.2f", tong);
		}	
	}
}
void CHINHPHUONG(int a[], int n)
{
	int test1 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = sqrt(a[i]);
		if (temp * temp == a[i]) test1++;
		else test1--;
	}
	if (test1 == n) printf("\nDay nhap vao ban dau la mot day chinh phuong!");
	else printf("\nDay nhap vao ban dau khong phai la mot day chinh phuong!");
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
	int a[n];
	NHAP(a, n);
	XUAT(a, n);
	MAX(a, n);
	TINH(a, n);
	CHINHPHUONG(a, n);
}