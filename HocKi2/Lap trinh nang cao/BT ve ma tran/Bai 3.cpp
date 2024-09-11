#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>
int* nhapDS(int *n, int* a)
{
	re:
	printf("Nhap so luong phan tu cua day so: ");
	scanf("%d", n);
	if (*n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	a = (int*) malloc((*n+1) * sizeof(int));
	for (int i = 0; i < *n; i++)
	{
		printf("Phan tu a[%d]: ", i);
		scanf("%d", (a+i));
	}
	return a;
}

void xuatDS(int n, int* a)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.\n", *(a+i));
	}
}

bool isIncreasing(int n, int* a)
{
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (*(a+i) < *(a+j)) 
			{
				check = false;
				break;
			}
		}
	}
	return check;
}

int findMaxEvenElement(int n, int* a, int* check)
{
	*check = 0;
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) > max && *(a+i) % 2 == 0)
		{
			max = *(a+i);
			*check = 1;
		}
	}
	return max;
}

int findMinAbsElement(int n, int* a)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (abs(*(a+i)) < min) min = abs(*(a+i));
	}
	return min;
}

int findMaxElement(int n, int* a)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		float temp = *(a+i) / (i+1);
		if (temp > max)
		{
			max = temp;
		}
	}
	return max;
}
int main()
{
	int n;
	int* a = nhapDS(&n, a);
	printf("\nDay so vua nhap la: ");
	xuatDS(n, a);
	
	if (isIncreasing(n, a)) printf("\nDay so co tinh tang dan!\n");
	else printf("\nDay so khong co tinh tang dan!\n");
	
	int check;
	int max1 = findMaxEvenElement(n, a, &check);
	if (check == 0) printf("\nDay so khong ton tai phan tu nao co gia tri chan!\n");
	else printf("\nGia tri chan lon nhat cua day so la: %d\n", max1);
	
	int min1 = findMinAbsElement(n, a);
	printf("\nGia tri nho nhat cua |a1|, |a2|, ..., |an| la: %d\n", min1);
	
	int max2 = findMaxElement(n, a);
	printf("\nGia tri nho nhat thoa man la: %d", max2);
}