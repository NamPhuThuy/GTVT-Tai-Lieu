#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#define PI 3.14152
struct Diem
{
    float x;
    float y;
};

void nhapDiem(Diem *a, int i)
{
    printf("Diem a[%d]:\n", i);
    printf("\tHoanh do: "); scanf("%f", &a[i].x);
    printf("\tTung do: "); scanf("%f", &a[i].y);
}

Diem* nhapDS(int *n)
{
    printf("Nhap so luong diem tren mat phang: ");
    scanf("%d", n);
    Diem *a = (Diem*)malloc(*(n+1) * sizeof(Diem));
    printf("Nhap lan luot toa do cua %d diem:\n", *n);
    for (int i = 0; i < *n; i++)
    {
        nhapDiem(a, i);
    }
    return a;
}

void xuatDiem(Diem a, int i)
{
    printf("a[%d] = (%.2f, %.2f)\n", i, a.x, a.y);
}

void xuatDS(int n, Diem *a)
{
    for (int i = 0; i < n; i++)
    {
        xuatDiem(a[i], i);
    }
}

float* tinhDoDaiXaO(int n, Diem* a)
{
	float* sO;
	sO = (float*) malloc((n+1) * sizeof(float));
	for (int i = 0; i < n; i++)
	{
		*(sO + i) = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
	}
	return sO;
}

void sapXep(Diem *a, int n, float *sO)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			Diem temp = a[i];
			if (sO[i] > sO[j])
			{
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

float tongDoDaiO(Diem* a, int n , float* sO)
{
	float s;
	for (int i = 0; i < n; i++)
	{
		s += sO[i];
	}
	return s;
}

float tinhSDtr(Diem* a, int n)
{
	float r = sqrt(pow(a[n-1].x, 2) + pow(a[n-1].y, 2));
	float dt = PI * pow(r, 2);
	return dt;
}
int main()
{
    int n;
    Diem *a;
    
    a = nhapDS(&n);
    printf("Danh sach toa do diem:\n");
    xuatDS(n, a);

	float *sO = tinhDoDaiXaO(n, a);
	sapXep(a, n, sO);
	printf("Danh sach diem sau khi sap xep theo thu tu xa dan goc toa do la:\n");
	xuatDS(n, a);
	
	float s = tongDoDaiO(a, n , sO);
	printf("Tong khoang cach tu tat ca cac diem den goc toa do bang %.2f\n", s);
	
	printf("Diem o gan goc toa do nhat la: "); xuatDiem(a[0], 0);
	
	float dt = tinhSDtr(a, n);
	printf("Dien tich cua hinh tron tam O nho nhat chua tat ca cac diem bang: %.2f\n", dt);
    free(a); 

    return 0;
}