#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MatHang
{
	char maHang[10];
	long donGia;
};

struct HoaDon
{
	char maHang[10];
	int sl;
	char ngayban[7];
};

void nhapMH(MatHang* a, int i)
{
	printf("Mat hang thu %d:\n", i);
	printf("Nhap ma hang: ");
	fflush(stdin); gets(a->maHang);
	
	printf("Nhap don gia: ");
	scanf("%ld", &a->donGia);
}

MatHang* nhapMH(MatHang* a, int* m)
{
	printf("Nhap so luong mat hang: ");
	scanf("%d", m);
	
	a = (MatHang*) malloc((*m+1) * sizeof(MatHang));
	for (int i = 0; i < *m; i++)
	{
		nhapMH(&a[i], i);
	}
	return a;
}

void xuatMH(MatHang* a, int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("%10s %30ld\n", a[i].maHang, a[i].donGia);
	}
}

void nhapHD(HoaDon* a, int i)
{
	printf("Hoa don thu %d:\n", i);
	printf("Nhap ma hang: ");
	fflush(stdin); gets(a->maHang);
	printf("Nhap so luong: ");
	scanf("%d", &a->sl);
	printf("Nhap ngay ban (ddmmyy): ");
	fflush(stdin); gets(a->ngayban);
}

HoaDon* nhapHD(HoaDon* b, int *n)
{
	printf("\nNhap so luong hoa don: ");
	scanf("%d", n);
	
	b = (HoaDon*) malloc((*n+1) * sizeof(HoaDon));
	for (int i = 0; i < *n; i++)
	{
		nhapHD(&b[i], i);
	}
	return b;
}

void xuatHD(HoaDon* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%10s %5d %10s\n", b[i].maHang, b[i].sl, b[i].ngayban);
	}
}

int demHDCoSLLonHon10(HoaDon* b, int n, int* check)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i].sl > 10)
		{
			dem += 1;
			*check = 1;
		}
	}
	return dem;
}

long tinhTienBanDuoc(MatHang* a, HoaDon* b, int m, int n, int* check)
{
	char ngay[7];
	printf("Nhap ngay can tinh tong tien thu duoc khi ban hang (ddmmyy): ");
	fflush(stdin); gets(ngay);
	long tongTien = 0;
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		if ((strcmp(ngay, b[i].ngayban)) == 0)
		{
			for (int j = 0; j < m; j++)
			{
				if ((strcmp(b[i].maHang, a[j].maHang)) == 0)
				{
					tongTien += (a[j].donGia * b[i].sl);
				}
			}
			*check = 1;
		}
	}
	return tongTien;
}

int main()
{
	// Nhap, xuat danh sach mat hang
	int m;
	MatHang* a = nhapMH(a, &m);
	printf("\nDanh sach cac mat hang:\n");
	xuatMH(a, m);
	
	// Nhap xuat n hoa don
	int n;
	HoaDon* b = nhapHD(b, &n);
	printf("\nDanh sach cac hoa don:\n");
	xuatHD(b, n);
	
	// Dem so hoa don co so luong lon hon 10
	int check;
	int dem = demHDCoSLLonHon10(b, n, &check);
	if (check == 0) printf("\nKhong co hoa don nao co so luong lon hon 10!\n");
	else printf("\nCo tat ca %d hoa don co so luong lon hon 10!\n", dem);
	
	// Tinh so tien ban duoc trong mot ngay cho truoc
	long tt = tinhTienBanDuoc(a, b, m, n, &check);
	printf("Tong so tien la: %ld", tt);
	
	free(a);
	free(b);
	
	return 0;
}