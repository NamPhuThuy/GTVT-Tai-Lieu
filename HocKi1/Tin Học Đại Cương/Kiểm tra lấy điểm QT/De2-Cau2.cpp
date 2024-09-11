#include <stdio.h>
#include <string.h>
struct Sach
{
	char maSach[10];
	char tenSach[100];
	char tenTacGia[50];
	float giaTien;
};
void NhapSach(Sach a[], int n)
{
	printf("Nhap lan luot thong tin cua %d cuon sach:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Cuon sach %d:\n", i+1);
		printf("\tMa sach: "); fflush(stdin); gets(a[i].maSach);
		printf("\tTen sach: "); gets(a[i].tenSach);
		printf("\tTen tac gia: "); gets(a[i].tenTacGia);
		printf("\tGia tien: "); scanf("%f", &a[i].giaTien);
	}
}
void XuatSach(Sach a[], int n)
{
	printf("Danh sach %d cuon sach:\n");
	printf("   Ma sach             Ten sach          Ten tac gia   Gia tien\n");
	for (int i = 0; i < n; i++)
	{
		printf("%10s %20s %20s %10.3f\n", a[i].maSach, a[i].tenSach, a[i].tenTacGia, a[i].giaTien);
	}
}
void TimSach(Sach a[], int n)
{
	char timTacGia[50];
	printf("Nhap ten tac gia: ");
	fflush(stdin); gets(timTacGia);
	printf("Nhung cuon sach cua tac gia %s la: ", timTacGia);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].tenTacGia, timTacGia) == 0)
		{
			printf("%s; ", a[i].tenSach);
		}
	}
	printf("\n");
}

int main()
{
	int n;
	re1:
	printf("Nhap so luong sach: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}	
	
	Sach a[n];
	NhapSach(a, n);
	XuatSach(a, n);
	TimSach(a, n);
	
}