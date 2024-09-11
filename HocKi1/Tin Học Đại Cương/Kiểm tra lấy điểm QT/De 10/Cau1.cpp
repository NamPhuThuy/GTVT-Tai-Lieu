#include <stdio.h>
#include <limits.h>
void Nhap(int a[100], int n)
{
	printf("\nNhap %d phan tu vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("\n");
}
void Xuat(int a[100], int n)
{
	printf("Day so vua nhap bao gom cac phan tu: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
}
int DemChan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) dem++;
	}
	return dem;
}
int TimMaxChan(int a[100], int n)
{
	int maxc = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (maxc < a[i] && a[i] % 2 == 0) 
		{
			maxc = a[i];
		}
	}
	return maxc;
}
int DemCap(int a[100], int n)
{
	int dem1 = 0;
	for (int i = 1; i < n; i++)
	{
		int tong = a[i] + a[i-1];
		int tich = a[i] * a[i-1];
		if (tich % tong == 3) dem1++;
	}
	return dem1;	
	
}
void InCap(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int tong = a[i] + a[i-1];
		int tich = a[i] * a[i-1];
		if (tich % tong == 3)
		{
			printf("(%d, %d)  ", a[i-1], a[i]);
		}
	}
}
int DemHonX(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) dem++;
	}
	return dem;
}
int TongHonX(int a[100], int n, int x)
{
	int  tonglx = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) tonglx += a[i];
	}
	return tonglx;
}
main()
{
	int n; printf("Nhap so luong cua cac phan tu: "); scanf("%d", &n);
	int a[100];
	Nhap(a, n);
	Xuat(a, n);
	
	// 
	if (DemChan(a, n) != 0)
	{
		printf("Phan tu chan lon nhat cua day so la %d", TimMaxChan(a, n));
	}
	else printf("Day so khong gia tri chan nao\n");

	//
	if (DemCap(a, n) != 0)
	{
		printf("\nCo tat ca %d cap so lien tiep ma tich chia tong du 3.\n", DemCap(a, n));
		printf("Cac cap do la: "); InCap(a, n);
	}
	else printf("\nKhong co cap so nao lien tiep co tich chia tong du 3\n");
	

	//
	int x; printf("\nNhap gia tri cua so nguyen x: "); scanf("%d", &x);
	if (DemHonX(a, n, x) != 0)
	{
		printf("Tong cua cac phan tu co gia tri lon hon x bang %d", TongHonX(a, n, x));
	}
	else printf("Khong co phan tu trong day so co gia tri lon hon x");
}