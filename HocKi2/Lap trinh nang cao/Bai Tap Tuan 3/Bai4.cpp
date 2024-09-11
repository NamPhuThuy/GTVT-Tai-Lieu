#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#define PI 3.14159
struct Diem
{
	float x;
	float y;
};

void nhapDiem(Diem* a, int i)
{
	printf("Nhap toa do diem thu %d:\n", i);
	printf("a[x%d][y%d] = ", i, i);
	scanf("%f%f", &a->x, &a->y);
}

Diem* nhapDiem(int n)
{
	Diem* a = (Diem*) malloc(n * sizeof(Diem));
	for (int i = 0; i < n; i++)
	{
		nhapDiem(&a[i], i);
	}
	return a;
}

void xuatDiem(int n, Diem* a)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1)
		{
			printf("(%.2f, %.2f), ", a[i].x, a[i].y);
		}
		else printf("(%.2f, %.2f)\n", a[i].x, a[i].y);
	}
}

int countThirdQuadrant(int n, Diem* a)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x < 0 && a[i].y < 0) count += 1;
	}
	
	return count;
}

float findRadius(int n, Diem* a)
{
	float max = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (temp > max) max = temp;
	}
	
	return max;
}

float sumPolylines(int n, Diem* a)
{
	float poly = 0;
	for (int i = 0; i < n-1; i++)
	{
		poly += sqrt(pow(a[i+1].x - a[i].x, 2) + pow(a[i+1].y - a[i].y, 2));
	}
	
	return poly;
}

Diem* countOutsideCircle(int n, Diem* a, int* count, float r)
{
	*count = 0;
	Diem* outP = (Diem*) malloc(n * sizeof(Diem));
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (temp > r)
		{
			*count += 1;
			outP[size] = a[i];
			size += 1;
		}
	}
	
	if (*count == 0)
	{
		free(outP);
		return NULL;
	}
	
	return outP;
}

bool checkPointSecondQuadrant(Diem a)
{
	if (a.x < 0 && a.y > 0) return 1;
	return 0;	
}

Diem findPointSecondQuadrantNearestO(int n, Diem* a, int* check)
{
	*check = 0;
	int index;
	float min = FLT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (checkPointSecondQuadrant(a[i]) == true)
		{
			float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
			if (temp < min) 
			{
				min = temp;
				index = i;
				*check = 1;
			}
		}
	}
	
	return a[index];
}

int countCutHorizontalAxis(int n, Diem* a, int* check)
{
	*check = 0;
	int count = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((a[i].y < 0 && a[j].y > 0) || (a[i].y > 0 && a[j].y < 0))
			{
				*check = 1;
				count += 1;
			}
		}
	}
	
	return count;
}

int countStraightSecondQuadrant(int n, Diem* a, int* check)
{
	*check = 0;
	int count = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((checkPointSecondQuadrant(a[i]) == true) && (checkPointSecondQuadrant(a[j]) == true))
			{
				count += 1;
				*check = 1;
			}
		}
	}
	return count;
}

int main()
{
	// Nhap lan luot toa do cua cac diem
	int n;
	printf("Nhap so luong diem: ");
	scanf("%d", &n);
	printf("\nNhap lan luot toa do cua %d diem:\n", n);
	Diem* a = nhapDiem(n);
	printf("\nToa do cac diem vua nhap la:\n");
	xuatDiem(n, a);
	
	// Dem so diem thuoc duong phan giac goc phan tu thu ba
	int count3 = countThirdQuadrant(n, a);
	printf("\nCo tat ca %d diem thuoc goc phan tu 3\n", count3);
	
	// Tim dien tich hinh tron tam O nho nhat chua tat ca cac diem
	float rad = findRadius(n, a);
	printf("\nDien tich hinh tron tam O nho nhat chua tat ca cac diem bang %.2f\n", PI * pow(rad, 2));
	
	// Tinh do dai duong gap khuc di qua tat ca cac diem
	float poly = sumPolylines(n, a);
	printf("\nDo dai duong gap khuc di qua tat ca cac diem bang %.2f\n", poly);
	
	// Nhap vao ban kinh R, dem va in ra man hinh cac diem nam
	// ngoai duong tron tam O, ban kinh R
	float r;
	printf("\nNhap vao do dai ban kinh R: ");
	scanf("%f", &r);
	int count;
	Diem* outP = countOutsideCircle(n, a, &count, r);
	if (count == 0) printf("\nKhong ton tai diem nao nam ngoai duong tron (O; %.2f)\n", r);
	else 
	{
		printf("Co tat ca %d diem nam ngoai duong tron (O; %.2f)\n", count, r);
		printf("Cac diem do la: ");
		xuatDiem(count, outP);
	}
	
	
	// Tim mot diem thuoc goc phan tu thu 2 gan goc toa do nhat
	int check;
	Diem p1 = findPointSecondQuadrantNearestO(n, a, &check);
	if (check == 0) printf("\nKhong ton tai diem thuoc goc phan tu thu hai!\n");
	else printf("\nDiem thuoc goc phan tu thu 2 gan goc toa do nhat la: (%.2f, %.2f)\n", p1.x, p1.y);
	
	// Dem so doan thang cat truc hoanh
	int count1 = countCutHorizontalAxis(n, a, &check);
	if (check == 0) printf("\nKhong ton tai doan thang cat truc hoanh!\n");
	else printf("\nCo tat ca %d doan thang cat truc hoanh!\n", count1);
	
	// Dem so doan thang thuoc goc phan tu thu hai
	int count2 = countStraightSecondQuadrant(n, a, &check);
	if (check == 0) printf("\nKhong ton tai doan thang thuoc goc phan tu thu hai!\n");
	else printf("\nCo tat ca %d doan thang thuoc goc phan tu thu hai!\n", count2);
	
	free(a);
	free(outP);
	return 0;
}