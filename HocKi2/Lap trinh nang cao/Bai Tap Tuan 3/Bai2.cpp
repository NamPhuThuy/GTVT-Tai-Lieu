#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <string.h>

struct Thisinh
{
	char hoten[30];
	float diem;
	char truong;	
};

void nhapTS(Thisinh* a, int i)
{
	printf("Thi sinh thu %d:\n");
	printf("Ho ten: ");
	fflush(stdin); gets(a->hoten);
	printf("Diem: ");
	scanf("%f", &a->diem);
	printf("Truong (A/B/C): ");
	fflush(stdin); scanf("%c", &a->truong);
}

Thisinh* nhapDS(int n)
{
	Thisinh* a = (Thisinh*) malloc(n * sizeof(Thisinh));
	for (int i = 0; i < n; i++)
	{
		nhapTS(&a[i], i);
	}
	return a;
}

void xuatTS(Thisinh* a)
{
	printf("%30s %7.2f %7c\n", a->hoten, a->diem, a->truong);
}

void xuatDS(int n, Thisinh* a)
{
	for (int i = 0; i < n; i++)
	{
		xuatTS(&a[i]);
	}
}

float sumGradeEachSchool(int n, Thisinh* a, char truong)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong) sum += a[i].diem;
	}
	
	return sum;
}

int compare3Values(float a, float b, float c)
{
	if (a > b && a > c) 
	{
        return -1;
    } else if (b > a && b > c) 
	{
    	return 0;
    } else 
	{
        return 1;
    }
}

int countTSEachSchool(int n, Thisinh* a, char truong)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong) count++;
	}
	
	return count;
}

Thisinh findMaxGradeTSA(int n, Thisinh* a, char truong)
{
	float maxG = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong)
		{
			if (a[i].diem > maxG) maxG = a[i].diem;
		}
	}
	
	Thisinh temp;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong && a[i].diem == maxG)
		{
			temp = a[i];
		}
	}
	return temp;
}

Thisinh* findTSOfSchool(int n, Thisinh* a, char truong, int* check, int* count)
{
	*check = 0;
	*count = 0;
	Thisinh* temp;
	temp = (Thisinh*) malloc(n * sizeof(Thisinh));
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong)
		{
			temp[*count] = a[i];
			*check = 1;
			(*count) += 1;
		}
	}
	if (*count == 0)
	{
		free(temp);
		return NULL;
	}
	
	return temp;
}

Thisinh* findTSByName(int n, Thisinh* a, char hoten[], int* check, int* count)
{
	*check = 0;
	*count = 0;
	Thisinh* temp;
	temp = (Thisinh*) malloc(n * sizeof(Thisinh));
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].hoten, hoten) == 0)
		{
			temp[*count] = a[i];
			*check = 1;
			(*count) += 1;
		}
	}
	
	if (*count == 0)
	{
		free(temp);
		return NULL;
	}
	
	return temp;
}

bool isGreaterThanX(int n, Thisinh* a, float x, int* check, char truong)
{
	*check = 0;
	bool allGreater = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == truong)
		{
			*check = 1;
			if (a[i].diem < x)
			{
				allGreater = false;
				break;
			}
		}
	}
	
	return allGreater;
}

int main()
{
	// Nhap thong tin cho n thi sinh
	int n;
	printf("Nhap so luong thi sinh: ");
	scanf("%d", &n);
	
	printf("\nNhap lan luot thong tin cua cac thi sinh:\n");
	Thisinh* ts = nhapDS(n);
	printf("\nDanh sach thong tin cua cac thi sinh:\n");
	printf("                     Ho va ten    Diem  Truong\n");
	xuatDS(n, ts);
	
	// Tinh tong so diem cua moi truong va xac dinh truong co tong diem cao nhat
	float sumGA = sumGradeEachSchool(n, ts, 'A');
	float sumGB = sumGradeEachSchool(n, ts, 'B');
	float sumGC = sumGradeEachSchool(n, ts, 'C');
	printf("\nTong diem 3 truong A, B va C lan luot la: %.2f, %.2f, %.2f\n", sumGA, sumGB, sumGC);
	if (compare3Values(sumGA, sumGB, sumGC) == -1) printf("\nTong diem truong A la cao nhat\n");
	else if (compare3Values(sumGA, sumGB, sumGC) == 0) printf("\nTong diem truong B la cao nhat\n");
	else printf("\nTong diem truong C la cao nhat\n");
	
	// Thong ke so luong sinh vien tham du cua moi truong
	int countA = countTSEachSchool(n, ts, 'A');
	int countB = countTSEachSchool(n, ts, 'B');
	int countC = countTSEachSchool(n, ts, 'C');
	printf("\nTruong A co %d thi sinh tham gia du thi\n", countA);
	printf("Truong B co %d thi sinh tham gia du thi\n", countB);
	printf("Truong C co %d thi sinh tham gia du thi\n", countC);
	
	// Tim thi sinh co diem cao nhat truong A
	Thisinh maxA = findMaxGradeTSA(n, ts, 'A');
	printf("\nThi sinh co diem cao nhat cua truong A:\n");
	printf("                     Ho va ten    Diem  Truong\n");
	xuatTS(&maxA);
	
	// Nhap vao ten truong, in ra cac thi sinh thuoc truong do
	int check, size;
	char ttruong;
	printf("\nNhap ten truong (A/B/C): ");
	fflush(stdin);
	scanf("%c", &ttruong);
	Thisinh* fschool = findTSOfSchool(n, ts, ttruong, &check, &size);
	if (check == 0) printf("\nKhong ton tai thi sinh!\n");
	else 
	{
		printf("Thong tin cac thi sinh thuoc truong %c:\n", ttruong);
		printf("                     Ho va ten    Diem  Truong\n");
		xuatDS(size, fschool);
	}
	
	// Nhap vao ten 1 thi sinh, in ra thong tin thi sinh do
	char thoten[30];
	printf("\nNhap ten cua thi sinh can tim: ");
	fflush(stdin); gets(thoten);
	Thisinh* fname = findTSByName(n, ts, thoten, &check, &size);
	if (check == 0) printf("\nKhong ton tai thi sinh!\n");
	else 
	{
		printf("Thong tin cac thi sinh can tim la:\n");
		printf("                     Ho va ten    Diem  Truong\n");
		xuatDS(size, fname);
	}
	
	// Kiem tra xem toan bo thi sinh cua truong B co diem deu lon hon x
	// hay khong, voi x nhap tu ban phim
	float x;
	printf("\nNhap diem can xet: ");
	scanf("%f", &x);
	bool test = isGreaterThanX(n, ts, x, &check, 'B');
	if (check == 0) printf("\nKhong ton tai thi sinh cua truong B\n");
	else 
	{
		if (test == true) printf("\nToan bo thi sinh cua truong B deu co diem lon hon %.2f\n", x);
		else printf("\nTon tai thi sinh cua truong B co diem nho hon %.2f\n", x);
	}
	
	free(ts);
	free(fname);
	free(fschool);
	
	return 0;
}