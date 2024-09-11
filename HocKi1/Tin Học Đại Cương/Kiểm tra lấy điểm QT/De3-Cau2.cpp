#include <stdio.h>
#include <string.h>
struct SINHVIEN
{
	char msv[20];
	char ten[20];
	float diem;
	char truong;
};
void NHAP(SINHVIEN sv[100], int n)
{
	printf("\nNhap du lieu cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Sinh vien thu %d:\n", i+1);
		
		printf("Ma sinh vien: "); fflush(stdin); gets(sv[i].msv);
		printf("Ten: "); fflush(stdin); gets(sv[i].ten);
		printf("Diem: "); scanf("%f", &sv[i].diem);
		printf("Truong: "); fflush(stdin); scanf("%c", &sv[i].truong);
		printf("\n");
	}
}
void XUAT(SINHVIEN sv[100], int n)
{
	printf("Danh sach sinh vien:\n");
	printf("\nSTT      Ma SV        Ten       Diem     Truong");
	for (int i = 0; i < n; i++)
	{		
		printf("\n  %d %10s %10s %10.1f %10c\n", i+1, sv[i].msv, sv[i].ten, sv[i].diem, sv[i].truong);
	}
}
void YC1(SINHVIEN sv[100], int n)
{
	float tong1 = 0, tong2 = 0, tong3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].truong == '1') tong1 += sv[i].diem;
		else if (sv[i].truong == '2') tong2 += sv[i].diem;
		else if (sv[i].truong == '3') tong3 += sv[i].diem;	
	}
	printf("\nTong diem cua truong 1 bang: %.1f\n", tong1);
	printf("Tong diem cua truong 2 bang: %.1f\n", tong2);
	printf("Tong diem cua truong 3 bang: %.1f\n", tong3);
	float max = tong1; char tmax = '1';
	if (max < tong2)
	{
		max = tong2;
		tmax = '2';
	}
	if (max < tong3)
	{
		max = tong3;
		tmax = '3';
	}
	printf("Truong %c co tong diem lon nhat! (%.1f)\n", tmax, max);	
}
void YC2(SINHVIEN sv[100], int n)
{
	char tim[20];
	printf("\nNhap ten cua sinh vien can tim: \n");
	fflush(stdin); gets(tim);
	for (int i = 0; i < n; i++)
	{
		if ((strcmp(sv[i].ten, tim) == 0))
		{
			printf("Thong tin cua sinh vien %s:\n", tim);
			printf("Ma SV: %s\n", sv[i].msv);
			printf("Ten: %s\n", sv[i].ten);
			printf("Truong: %c\n", sv[i].truong);
			printf("Diem: %.1f\n", sv[i].diem);
		}
	}
}
void YC3(SINHVIEN sv[100], int n)
{
	float maxsv = sv[0].diem;
	int pos = 1;
	for (int i = 0; i < n; i++)
	{
		if (maxsv < sv[i].diem) 
		{
			maxsv = sv[i].diem;
			pos = i + 1;
		}
	}
	printf("/nSinh vien co diem cao nhat la: %s", sv[pos].ten);
}
main()
{
	int n; printf("Nhap so luong sinh vien can xet: "); scanf("%d", &n);
	SINHVIEN sv[100];
	NHAP(sv, n);
	XUAT(sv, n);
	YC1(sv, n);
}