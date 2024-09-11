#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
struct Sinhvien
{
	int maSV;
	char ten[30];
	int namsinh;
	float dToan, dLy, dHoa, dTB;
};

void nhapSV(Sinhvien* a, int i)
{
	printf("Sinh vien thu %d:\n", i);
	printf("Ma sinh vien: "); scanf("%d", &a->maSV);
	
	printf("Ten sinh vien: "); fflush(stdin); gets(a->ten);
	
	printf("Nam sinh: "); scanf("%d", &a->namsinh);
	
	printf("Diem Toan: "); scanf("%f", &a->dToan);
	
	printf("Diem Ly: "); scanf("%f", &a->dLy);
	
	printf("Diem Hoa: "); scanf("%f", &a->dHoa);
	
	a->dTB = (a->dToan + a->dLy + a->dHoa) / 3;
}

Sinhvien* nhapSV(int n)
{
	Sinhvien* a = (Sinhvien*) malloc(n * sizeof(Sinhvien));
	printf("Nhap thong tin cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++)
	{
		nhapSV(&a[i], i+1);
	}
	
	return a;
}

void xuatSV(Sinhvien a)
{
	printf("%10d %30s %10d %10.2f %10.2f %10.2f %10.2f\n", a.maSV, a.ten, a.namsinh, a.dToan, a.dLy, a.dHoa, a.dTB);
}
void xuatSV(int n, Sinhvien* a)
{
	printf("     Ma SV                         Ten SV   Nam sinh  Diem Toan    Diem Ly   Diem Hoa    Diem TB\n");
	for (int i = 0; i < n; i++)
	{
		xuatSV(a[i]);
	}
}

Sinhvien* findMaxAverageGrade(int n, Sinhvien* a, int* count)
{
	float maxG = FLT_MIN;
	Sinhvien* temp = (Sinhvien*) malloc(n * sizeof(Sinhvien));
	for (int i = 0; i < n; i++)
	{
		if (a[i].dTB > maxG)
		{
			maxG = a[i].dTB;
		}
	}
	
	*count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].dTB == maxG)
		{
			temp[*count] = a[i];
			*count += 1;
		}
	}
	
	return temp;
}

Sinhvien* sortAverageGrade(int n, Sinhvien* a)
{
	Sinhvien* sort = (Sinhvien*) malloc(n * sizeof(Sinhvien));
	for (int i = 0; i < n; i++)
	{
		sort[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			Sinhvien temp = a[i];
			if (sort[i].dTB > sort[j].dTB)
			{
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	
	return sort;
}

Sinhvien* findAvegradeGradeGreaterThanX(int n, Sinhvien* a, int* count, int x, int y)
{
	Sinhvien* temp = (Sinhvien*) malloc(n * sizeof(Sinhvien));
	*count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].dTB > x && a[i].dToan >= y && a[i].dLy >= y && a[i].dHoa >= y)
		{
			temp[*count] = a[i];
			*count += 1;
		}
	}
	
	return temp;
}

Sinhvien* findOldest(int n, Sinhvien* a, int* count)
{
	Sinhvien* old = (Sinhvien*) malloc(n * sizeof(Sinhvien));
	*count = 0;
	int ns = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (a[i].namsinh < ns)
		{
			ns = a[i].namsinh;
			old[*count] = a[i];
			*count += 1;
		}
	}
	
	return old;
}

Sinhvien findCodeSV(int n, Sinhvien* a, int* check, int ma)
{
	*check = 0;
	Sinhvien temp;
	for (int i = 0; i < n; i++)
	{
		if(a[i].maSV == ma)
		{
			temp = a[i];
			*check = 1;
		}
	}
	
	return temp;
}

int main()
{
	// Nhap so luong dau vao
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	
	// Nhap danh sach sinh vien ra man hinh
	Sinhvien* a = nhapSV(n);	
	
	// Xuat danh sach sinh vien ra man hinh
	printf("\nDanh sach thong tin sinh vien:\n");
	xuatSV(n, a);
	
	// Tim sinh vien co diem trung binh cao nhat
	int cnt;
	Sinhvien* maxG = findMaxAverageGrade(n, a, &cnt);
	printf("\nDanh sach sinh vien co diem trung binh cao nhat:\n");
	xuatSV(cnt, maxG);
	
	// Sap xep danh sach lop theo thu tu tang dan cua diem trung binh
	Sinhvien* sortAvgG = sortAverageGrade(n, a);
	printf("\nDanh sach sinh vien sau khi sap xep theo thu tu tang dan diem trung binh:\n");
	xuatSV(n, sortAvgG);
	
	// Tim kiem va in ra cac sinh vien co diem trung binh
	// lon hon 5 va khong co mon nao duoi 3
	Sinhvien* avgG5 = findAvegradeGradeGreaterThanX(n, a, &cnt, 5, 3);
	if (cnt == 0) printf("\nKhong ton tai sinh vien co diem tb lon hon 5 va khong co mon nao duoi 3\n");
	else
	{
		printf("\nDanh sach sinh vien co diem tb lon hon 5 va khong co mon nao duoi 3:\n");
		xuatSV(cnt, avgG5);
	}
	
	// Tim sinh vien co tuoi lon nhat
	Sinhvien* old = findOldest(n, a, &cnt);
	printf("\nDanh sach sinh vien co tuoi lon nhat:\n");
	xuatSV(cnt, old);
	
	//Nhap vao ma sinh vien. Tim va in ra cac thong tin lien quan den sinh vien do (neu co)
	int ma, check;
	printf("\nNhap vao ma sinh vien can tim: ");
	scanf("%d", &ma);
	Sinhvien code = findCodeSV(n, a, &check, ma);
	if (check == 0) printf("Khong ton tai sinh vien can tim\n");
	else 
	{
		printf("     Ma SV                         Ten SV   Nam sinh  Diem Toan    Diem Ly   Diem Hoa    Diem TB\n");
		xuatSV(code);
	}
	
	free(a);
	free(maxG);
	free(sortAvgG);
	free(avgG5);
	free(old);
	
	return 0;
}