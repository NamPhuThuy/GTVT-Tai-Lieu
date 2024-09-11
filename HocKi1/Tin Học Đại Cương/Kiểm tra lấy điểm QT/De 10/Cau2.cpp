#include <stdio.h>
#include <string.h>
struct Phieu
{
	char msv[20];
	char ten[20];
	char truong;
	float diem;
};
void Nhap(Phieu a[100], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		printf("Thi sinh thu %d:\n", i+1);
		printf("\tMa sinh vien: "); fflush(stdin); gets(a[i].msv);
		printf("\tHo ten: "); fflush(stdin); gets(a[i].ten);
		re2:
		printf("\tTruong (A, B, C): "); fflush(stdin); scanf("%c", &a[i].truong);
		if (a[i].truong != 'A' && a[i].truong != 'B' && a[i].truong != 'C')
		{
			printf("Du lieu nhap khong thoa man. Vui long nhap lai!\n");
			goto re2;
		}
		printf("\tDiem: "); scanf("%f", &a[i].diem);
		printf("\n");
	}
}
void Xuat(Phieu a[100], int n)
{
	
	printf("       STT      Ma SV     Ho ten     Truong       Diem\n");
	for (int i = 0; i < n; i++)
	{		
		printf("%10d %10s %10s %10c %10.1f\n", i+1, a[i].msv ,a[i].ten, a[i].truong, a[i].diem);
	}
}
void Hon15(Phieu a[100], int n)
{
	printf("       STT      Ma SV     Ho ten     Truong       Diem\n");	
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem >= 15 && a[i].truong == 'B')
		{				
			printf("%10d %10s %10s %10c %10.1f\n", i+1, a[i].msv ,a[i].ten, a[i].truong, a[i].diem);
		}
	}
	printf("\n");
}
void SapXep(Phieu a[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Phieu temp = a[i];
			if (a[i].diem < a[j].diem)
			{
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	Xuat(a, n);
}
void TimSinhVien(Phieu a[], int n, char tensv[])
{
	printf("       STT      Ma SV     Ho ten     Truong       Diem\n");	
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].ten, tensv) == 0)
		{
			printf("%10d %10s %10s %10c %10.1f\n", i+1, a[i].msv, a[i].ten, a[i].truong, a[i].diem);
		}
	}
}
main()
{
	int n; printf("Nhap so luong thi sinh dau vao: "); scanf("%d", &n);
	Phieu a[100];
	printf("Nhap lan luot du lieu cua %d thi sinh:\n", n);
	Nhap(a, n);
	printf("Danh sach thi sinh la:\n");
	Xuat(a, n);
	
	//
	printf("\nDanh sach cac thi sinh co diem thi >= 15 cua truong B la: \n");
	Hon15(a, n);
	
	//
	printf("\nDanh sach thi sinh duoc sap xep lai theo thu tu giam dan cua diem:\n");
	SapXep(a, n);
	
	// 
	char tensv[20]; printf("Nhap ten cua sinh vien can tim: "); fflush(stdin); gets(tensv);
	printf("Thong tin cua sinh vien %s la: \n", tensv);
	TimSinhVien(a, n, tensv);
}
