#include <stdio.h>
#include <string.h>
struct GIANGVIEN
{
	char hoten[30];
	char chuyenmon;
	int thamnien;
};
void NHAP(GIANGVIEN gv[], int n)
{
	printf("\nNhap du lieu dau vao:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Giang vien thu %d:\n", i+1);
		printf("\tHo ten: "); fflush(stdin); gets(gv[i].hoten);
		lap1:
		printf("\tChuyen mon (T, V, A): "); scanf("%c", &gv[i].chuyenmon);
		if (gv[i].chuyenmon != 'T' && gv[i].chuyenmon != 'V' && gv[i].chuyenmon != 'A') 
		{
			printf("Vui long nhap dung chuyen mon (T - Toan, V - Van, A - Anh)!\n");
			goto lap1;
		}
		lap2:
		printf("\tTham nien: "); scanf("%d", &gv[i].thamnien);
		if (gv[i].thamnien <= 0)
		{
			printf("So nam cong tac toi thieu la 1. Vui long nhap lai!\n");
			goto lap2;
		}
	}
}
void XUAT(GIANGVIEN gv[], int n)
{
	printf("\nDanh sach giang vien:\n");
	printf("|  STT|           Ho va ten|  Chuyen mon|   Tham nien|\n");
	for (int i = 0; i < n; i++)
	{
		printf("|%5d|%20s|%12c|%12d|\n", i+1, gv[i].hoten, gv[i].chuyenmon, gv[i].thamnien);
	}
}
void TBTN(GIANGVIEN gv[], int n)
{
	float tbT = 0, tbV = 0, tbA = 0;
	int demt = 0, demv = 0, dema = 0;
	for (int i = 0; i < n; i++)
	{
		if (gv[i].chuyenmon == 'T') 
		{
			tbT += gv[i].thamnien;
			demt++;
		}
		else if (gv[i].chuyenmon == 'V') 
		{
			tbV += gv[i].thamnien;
			demv++;
		}
		else if (gv[i].chuyenmon == 'A') 
		{
			tbA += gv[i].thamnien;
			dema++;
		}
	}
	printf("\nTrung binh tham nien theo tung loai chuyen mon:\n");
	if (demt == 0) printf("Chuyen mon Toan: Khong co!\n");
	else printf("Chuyen mon Toan: %.2f\n", tbT/demt);
	if (demv == 0) printf("Chuyen mon Van: Khong co!\n");
	else printf("Chuyen mon Van: %.2f\n", tbV/demv);
	if (dema == 0) printf("Chuyen mon T: Khong co!\n");
	else printf("Chuyen mon Anh: %.2f\n", tbA/dema);
}
void MAX(GIANGVIEN gv[], int n)
{
	int max = gv[0].thamnien;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < gv[i].thamnien)
		{
			max = gv[i].thamnien;
			index = i;
		}
	}
	printf("\nNguoi co tham nien cao nhat la: %s", gv[index].hoten);
}
void KIEMTRA(GIANGVIEN gv[], int n)
{
	char hotentim[30];
	printf("\nNhap ten cua nguoi can tim: ");
	fflush(stdin); gets(hotentim);
	int test = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(gv[i].hoten, hotentim) == 0) 
		{
			printf("\nThong tin cua nguoi can tim la:\n");
			printf("|  STT|           Ho va ten|  Chuyen mon|   Tham nien|\n");
			printf("|%5d|%20s|%12c|%12d|\n", i+1, gv[i].hoten, gv[i].chuyenmon, gv[i].thamnien);
			test = 0;
			break;
		}
		else 
		{
			test = 1;
		}
	}
	if (test == 1) printf("\nKhong ton tai!");
}
main()
{
	int n;
	re:
	printf("Nhap so luong giang vien dau vao: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	GIANGVIEN gv[n]; 
	NHAP(gv, n);
	XUAT(gv, n);   
	TBTN(gv, n);
	MAX(gv, n);
	KIEMTRA(gv, n);                                         
}