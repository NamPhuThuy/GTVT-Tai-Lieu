	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
struct ThiSinh
{
	int ma;
	char ten[30];
	float diemTB;
	char truong;
};

void nhapTS(ThiSinh* ts, int i)
{
	printf("Thi sinh thu %d:\n", i);
	
	printf("   Ma thi sinh: "); 
	scanf("%d", &ts->ma);
	
	printf("   Ten thi sinh: "); 
	getchar();
	fgets(ts->ten, sizeof(ts->ten), stdin);
	ts->ten[strcspn(ts->ten, "\n")] = '\0';
	
	printf("   Diem trung binh: "); 
	scanf("%f", &ts->diemTB);
	
	re:
	printf("   Truong (A/B/C): ");
	fflush(stdin);
	scanf("%c", &ts->truong);
	if (ts->truong != 'A' && ts->truong != 'B' && ts->truong != 'C')
	{
		printf("Vui long chon 1 trong 3 truong A, B va C!\n");
		goto re;
	}
}

ThiSinh* nhapDS(int* n, ThiSinh* ts)
{
	// Nhap n
	re:
	printf("Nhap so luong thi sinh: ");
	scanf("%d", n);
	if (*n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	// Cap phat dong bo nho dem
	ts = (ThiSinh*) malloc((*n + 1) * sizeof(ThiSinh));
	
	// Nhap n thi sinh vao mang
	for (int i = 0; i < *n; i++)
	{
		// Su dung ham nhap cho 1 thi sinh
		nhapTS(&ts[i], i);
	}
	
	return ts;
}

void xuatTS(ThiSinh ts)
{
	printf("%10d %30s %10.2f %10c\n", ts.ma, ts.ten, ts.diemTB, ts.truong);
}
void xuatDS(int n, ThiSinh* ts)
{
	for (int i = 0; i < n; i++)
	{
		xuatTS(ts[i]);
	}
}

float timDiemMax(int n, ThiSinh* ts)
{
	float max = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < ts[i].diemTB) max = ts[i].diemTB;
	}
	
	return max;
}

void timTSBangDiem(int n, ThiSinh* ts, float x)
{
	for (int i = 0; i < n; i++)
	{
		if (ts[i].diemTB == x)
		{
			xuatTS(ts[i]);
		}
	}
}

void xepDiemTangDan(int n, ThiSinh* ts)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			ThiSinh temp = ts[i];
			if (ts[i].diemTB > ts[j].diemTB)
			{
				ts[i] = ts[j];
				ts[j] = temp;
			}
		}
	}
}

int* ktLon5Truong(int n, ThiSinh* ts, int* check)
{
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		if (ts[i].diemTB > 5 && ts[i].truong == 'B')
		{
			*check = 1;
			break;
		}
	}
	return check;
}

int main()
{
	
	// Thuc hien nhap, xuat n thi sinh
	int n;
	ThiSinh* ts = nhapDS(&n, ts);
	printf("Danh sach thi sinh vua nhap:\n");
	xuatDS(n, ts);
	
	// Tim kiem tat ca cac thi sinh co diem cao nhat
	float max1 = timDiemMax(n, ts);
	printf("\nDanh sach cac thi sinh co diem cao nhat la:\n");
	timTSBangDiem(n, ts, max1);
	
	// Sap xep thi sinh theo diem tang dan
	printf("Danh sach thi sinh sau khi sap xep theo thu tu diem tang dan:\n");
	xepDiemTangDan(n, ts);
	xuatDS(n, ts);
	
	// Tim kiem va in ta man hinh cac thi sinh co diem trung binh
	// lon hon 5 diem cua truong B
	int* check = ktLonHon5Truong
	printf("\nCac thi sinh cua truong B co diem trung binh lon hon 5 la:\n");
	timLon5TruongB(n, ts, check);
	if (check == 0) printf("\nKhong ton tai thi sinh nao cua truong B co diem trung binh lon hon 5!\n");
	
}