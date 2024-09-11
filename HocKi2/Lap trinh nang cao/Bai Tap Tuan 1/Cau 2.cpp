#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

struct DAYNGUYEN
{
	int soPT;
	int* a;
};

void nhap(DAYNGUYEN* ar)
{
	printf("Nhap so luong phan tu cua day so: ");
	scanf("%d", &ar->soPT);
	
	ar->a = (int*) malloc(ar->soPT * sizeof(int));
	
	for (int i = 0; i < ar->soPT; i++)
	{
		printf("Phan tu a[%d] = ", i);
		scanf("%d", &ar->a[i]);
	}
}

void xuat(DAYNGUYEN ar)
{
	for (int i = 0; i < ar.soPT; i++)
	{
		if (i != ar.soPT - 1) printf("%d, ", ar.a[i]);
		else printf("%d.\n", ar.a[i]);
	}
}

int timMax(DAYNGUYEN ar)
{
	int max = INT_MIN;
	for (int i = 0; i < ar.soPT; i++)
	{
		if (max < ar.a[i]) max = ar.a[i];
	}
	return max;
}

int tinhTong(DAYNGUYEN ar)
{
	int tong = 0;
	for (int i = 0; i < ar.soPT; i++)
	{
		tong += ar.a[i];
	}
	return tong;
}

float tinhTBCLonHonX(DAYNGUYEN ar, int* x, int* check)
{
	float tbc = 0;
	int dem = 0;
	*check = 0;
	
	printf("Nhap so nguyen x bat ky: ");
	scanf("%d", x);
	
	for (int i = 0; i < ar.soPT; i++)
	{
		if (ar.a[i] > *x)
		{
			tbc += ar.a[i];
			dem += 1;
			*check = 1;
		}
	}
	return tbc/dem;
}

int main()
{
	DAYNGUYEN ar;
	nhap(&ar);
	printf("Day so vua nhap la: ");
	xuat(ar);
	
	int max = timMax(ar);
	printf("Gia tri lon nhat cua day so la: %d\n", max);
	
	int tong = tinhTong(ar);
	printf("Tong cac phan tu cua day so bang: %d\n", tong);
	
	int x;
	int check = 0;
	float tbc = tinhTBCLonHonX(ar, &x, &check);
	if (check == 0) printf("Khong co phan tu nao lon hon x = %d trong day so!\n", x);
	else printf("Trung binh cong cua cac phan tu lon hon x = %d trong day so bang: %.2f", x, tbc);
	
	free(ar.a);
	return 0;
}