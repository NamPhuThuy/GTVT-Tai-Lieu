#include <stdio.h>
#include <math.h>

#define PI 3.14
struct DiemType
{
	float x;
	float y;
};
void NhapDay(DiemType a[], int n)
{
	printf("Nhap lan luot toa do cua cac diem:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\t(x%d, y%d) = ", i+1, i+1);
		scanf("%f%f", &a[i].x, &a[i].y);
	}
}
void XuatDay(DiemType a[], int n)
{
	printf("Day diem la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("(%.2f, %.2f), ", a[i].x, a[i].y);
		else printf("(%.2f, %.2f).", a[i].x, a[i].y);
	}
}
float TinhDuongGapKhuc(DiemType a[], int n)
{
	float dgk = 0, kc = 0;
	for (int i = 1; i < n; i++)
	{
		kc = sqrt(pow(a[i].x - a[i-1].x, 2) + pow(a[i].y - a[i-1].y, 2)); 
		dgk += kc;
	}
	return dgk;
}
int DemDiemBenTrongDtron(DiemType a[], int n, float r)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		float dodai = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2)); 
		if (dodai < r) dem++;
	}
	return dem;
}
void InCacDiemBenTrongDtron(DiemType a[], int n, float r)
{
	for (int i = 0; i < n; i++)
	{
		float dodai = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (dodai < r)
		{
			if (i != n-1) printf("(%.2f, %.2f), ", a[i].x, a[i].y);
			else printf("(%.2f, %.2f).\n", a[i].x, a[i].y);
		}
	}
}
float TinhSDtronMin(DiemType a[], int n)
{
	float dienTich = 0;
	float banKinhMax = sqrt(pow(a[0].x, 2) + pow(a[0].y, 2));
	for (int i = 0; i < n; i++)
	{
		float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (temp > banKinhMax) banKinhMax = temp;
	}
	dienTich = PI * pow(banKinhMax, 2);
	return dienTich;
}
int main()
{
	// Nhap n va kiem tra xem n nhap vao co thoa man hay khong.
	int n;
	re1:
	printf("Nhap so luong diem cua day: ");
	scanf("%d", &n);
	if (n <= 0) 
	{
		printf("So luong diem toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	DiemType a[100];
	// Nhap va xuat day diem bang cach su dung ham khong co gia tri tra ve
	NhapDay(a, n);
	XuatDay(a, n);
	
	// Tinh do dai duong gap khuc bang cach su dung ham co gia tri tra ve
	printf("\nTong do dai duong gap khuc di qua tat ca cac diem bang %.3f\n", TinhDuongGapKhuc(a, n));
	
	// Nhap ban kinh va in ra cac diem nam phia trong duong tron (O;R)
	float r;
	re2:
	printf("Nhap ban kinh R: ");
	scanf("%f", &r);
	if (r <= 0)
	{
		printf("Ban kinh R co do dai toi thieu phai lon hon 0. Vui long nhap lai!/n");
		goto re2;
	}
	printf("Co tat ca %d diem nam ben trong duong tron (O; %.2f)\n", DemDiemBenTrongDtron(a, n, r), r);
	printf("Cac diem do lan luot la: ");
	InCacDiemBenTrongDtron(a, n, r);
	
	// Tinh dien tich hinh tron toam O ban kinh nho nhat chua tat ca cac diem
	printf("Dien tich hinh tron nho nhat chua tat ca cac diem bang %.3f", TinhSDtronMin(a, n));
}