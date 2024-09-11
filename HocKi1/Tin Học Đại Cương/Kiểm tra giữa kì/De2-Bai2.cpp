#include <stdio.h>
struct BENHNHAN
{
	char hoten[30];
	int tuoi;
	char benh;
};
void NHAP(BENHNHAN bn[], int n)
{
	printf("Nhap thong tin cua %d benh nhan dau vao:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Benh nhan thu %d:\n", i+1);
		printf("\tHo va ten: "); fflush(stdin); gets(bn[i].hoten);
		re1:
		printf("\tTuoi: "); scanf("%d", &bn[i].tuoi);
		if (bn[i].tuoi <= 0)
		{
			printf("So tuoi toi thieu la 1. Vui long nhap lai!\n");
			goto re1;
		}
		re2:
		printf("\tBenh viem gan (A, B, C): "); fflush(stdin); scanf("%c", &bn[i].benh);
		if (bn[i].benh != 'A' && bn[i].benh != 'B' && bn[i].benh != 'C')
		{
			printf("Yeu cau nhap dung loai benh. Hay nhap lai!\n");
			goto re2;
		}
	}
}
void XUAT(BENHNHAN bn[], int n)
{
	printf("\nDanh sach thong tin benh nhan:\n");
	printf("|  STT|           Ho va ten|      Tuoi|  Viem gan|\n");
	for (int i = 0; i < n; i++)
	{
		printf("|%5d|%20s|%10d|%10c|\n", i+1, bn[i].hoten, bn[i].tuoi, bn[i].benh);
	}
}
void MIN(BENHNHAN bn[], int n)
{
	int min = bn[0].tuoi;
	int index = 0, dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'B')
		{
			if (min > bn[i].tuoi) 
			{
				min = bn[i].tuoi;
				index = i;
			}
			dem++;
		}
	}
	if (dem == 0) printf("\nKhong co benh nhan nao mac benh viem gan B!\n");
	else
	{
		printf("\nBenh nhan mac benh viem gan B nho tuoi nhat la:\n");
		printf("|  STT|           Ho va ten|      Tuoi|  Viem gan|\n");
		printf("|%5d|%20s|%10d|%10c|\n", index+1, bn[index].hoten, bn[index].tuoi, bn[index].benh);
	}
}
void DEM(BENHNHAN bn[], int n)
{
	int dema = 0, demb = 0, demc = 0;
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'A') dema++;
		else if (bn[i].benh == 'B') demb++;
		else if (bn[i].benh == 'C') demc++;
	}
	printf("\nSo luong benh nhan cua tung loai benh la:\n");
	printf("\tViem gan A: %d\n", dema);
	printf("\tViem gan B: %d\n", demb);
	printf("\tViem gan C: %d\n", demc);
}
void SAPXEP(BENHNHAN bn[], int n)
{
	printf("\nDanh sach benh nhan sap xep theo benh A -> B -> C:\n");
	printf("|  STT|           Ho va ten|      Tuoi|  Viem gan|\n");
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'A') printf("|%5d|%20s|%10d|%10c|\n", i+1, bn[i].hoten, bn[i].tuoi, bn[i].benh);
	}
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'B') printf("|%5d|%20s|%10d|%10c|\n", i+1, bn[i].hoten, bn[i].tuoi, bn[i].benh);
	}
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'C') printf("|%5d|%20s|%10d|%10c|\n", i+1, bn[i].hoten, bn[i].tuoi, bn[i].benh);
	}
}
main()
{
	int n;
	re:
	printf("Nhap so luong benh nhanh dau vao: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong benh nhan toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	BENHNHAN bn[n];
	NHAP(bn, n);
	XUAT(bn, n);
	MIN(bn, n);
	DEM(bn, n);
	SAPXEP(bn, n);
}