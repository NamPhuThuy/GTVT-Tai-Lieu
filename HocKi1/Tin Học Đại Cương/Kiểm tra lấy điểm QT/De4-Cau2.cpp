#include <stdio.h>
#include <string.h>
struct SINHVIEN
{
	char msv[20];
	char ten[20];
	int namsinh;
	float diem;
};
void NHAP(SINHVIEN sv[100], int n)
{
	printf("\nNhap du lieu cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Sinh vien thu %d:\n", i+1);
		
		printf("Ma sinh vien: "); fflush(stdin); gets(sv[i].msv);
		printf("Ten: "); fflush(stdin); gets(sv[i].ten);
		printf("Nam sinh: "); scanf("%d", &sv[i].namsinh);
		printf("Diem: "); scanf("%f", &sv[i].diem);
		printf("\n");
	}
}
void XUAT(SINHVIEN sv[100], int n)
{
	printf("Danh sach sinh vien:\n");
	printf("\nSTT      Ma SV        Ten   Nam sinh       Diem");
	for (int i = 0; i < n; i++)
	{		
		printf("\n  %d %10s %10s %10d %10.1f\n", i+1, sv[i].msv, sv[i].ten, sv[i].namsinh, sv[i].diem);
	}
}
void YC1(SINHVIEN sv[100], int n)
{
	int min = sv[0].namsinh;
	int pos1 = 1;
	for (int i = 1; i < n; i++)
	{
		if (min > sv[i].namsinh) 
		{
			min = sv[i].namsinh;
			pos1 = i+1;
		}
	}
	printf("\nSinh vien lon tuoi nhat la: %s", sv[pos1].ten);
}
void YC2(SINHVIEN sv[100], int n)
{
	char timmsv[20];
	printf("Nhap ma SV cua sinh vien can tim: "); fflush(stdin); gets(timmsv);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sv[i].msv, timmsv) == 0)
		{
			printf("Thong tin cua sinh vien %s:\n", timmsv);
			printf("Ma SV: %s\n", sv[i].msv);
			printf("Ten: %s\n", sv[i].ten);
			printf("Nam sinh: %d\n", sv[i].namsinh);
			printf("Diem: %.1f\n", sv[i].diem);
		}
	}
}
void YC3(SINHVIEN sv[100], int n)
{
	float diemjuan; printf("\nNhap diem chuan: "); scanf("%f", &diemjuan);
	printf("Nhung sinh vien trung tuyen la: ");
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diem >= diemjuan) printf("%s  ", sv[i].ten);
	}
}
main()
{
	int n; printf("Nhap so luong sinh vien can xet: "); scanf("%d", &n);
	SINHVIEN sv[n];
	NHAP(sv, n);
	XUAT(sv, n);
	YC1(sv, n);
	YC2(sv, n);
	YC3(sv, n);
}