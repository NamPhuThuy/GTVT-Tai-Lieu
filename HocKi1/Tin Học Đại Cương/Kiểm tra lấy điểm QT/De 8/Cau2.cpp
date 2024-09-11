#include <stdio.h>
#include <string.h>
struct PHIEU
{
	char ten[20];
	char quequan[20];
	char truong;
	char sbd[20];
	float diem;
};
void NHAP(PHIEU a[100], int n)
{
	printf("\nNhap lan luot du lieu cua %d thi sinh:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Thi sinh thu %d:\n", i+1);
		printf("Ho ten: "); fflush(stdin); gets(a[i].ten);
		printf("Que quan: "); fflush(stdin); gets(a[i].quequan);
		printf("Truong: "); scanf("%c", &a[i].truong);
		printf("So bao danh: "); fflush(stdin); gets(a[i].sbd);
		printf("Diem: "); scanf("%f", &a[i].diem);
		printf("\n");
	}
}
void XUAT(PHIEU a[100], int n)
{
	printf("Danh sach thi sinh la:\n");
	printf("       STT     Ho ten   Que quan     Truong        SBD       Diem\n");
	for (int i = 0; i < n; i++)
	{		
		printf("%10d %10s %10s %10c %10s %10.1f\n", i+1, a[i].ten, a[i].quequan, a[i].truong, a[i].sbd, a[i].diem);
	}
}
void YC1(PHIEU a[100], int n)
{
	printf("\nDanh sach cac thi sinh co diem thi >= 15 la: \n");
	printf("       STT     Ho ten   Que quan     Truong        SBD       Diem\n");	
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem >= 15)
		{				
			printf("%10d %10s %10s %10c %10s %10.1f\n", i+1, a[i].ten, a[i].quequan, a[i].truong, a[i].sbd, a[i].diem);
		}
	}
	printf("\n");
}
void YC2(PHIEU a[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			PHIEU temp = a[i];
			if (a[i].diem < a[j].diem)
			{
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\nDanh sach thi sinh duoc sap xep lai theo thu tu giam dan cua diem:\n");
	printf("       STT     Ho ten   Que quan     Truong        SBD       Diem\n");
	for (int i = 0; i < n; i++)
	{		
		printf("%10d %10s %10s %10c %10s %10.1f\n", i+1, a[i].ten, a[i].quequan, a[i].truong, a[i].sbd, a[i].diem);
	}
}
void YC3(PHIEU a[100], int n)
{
	int dem1 = 0, dem2 = 0, dem3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == 'A') dem1++;
		else if (a[i].truong == 'B') dem2++;
		else if (a[i].truong == 'C') dem3++;
	}
	printf("\nThong ke so sinh vien du thi:\n");
	printf("Truong A co %d sinh vien!\n", dem1);
	printf("Truong B co %d sinh vien!\n", dem2);
	printf("Truong C co %d sinh vien!\n", dem3);
}
main()
{
	int n; printf("Nhap so luong thi sinh dau vao: "); scanf("%d", &n);
	PHIEU a[100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}