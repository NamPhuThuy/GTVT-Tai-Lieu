#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

int** insertMT(int n, int** a)
{	
	a = (int**) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*) malloc(n * sizeof(int)); 
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("pt[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	return a;
}

void displayMT(int n, int**a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", a[i][j]);
		}
		printf("\n");
	}
}

bool isUpperTriangularMT(int n, int** a)
{
	bool check;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][j] == 0)
			{
				check = true;
			}
			else 
			{
				check = false;
				return check;
			}
		}
	}
	
	return check;
}

int productBelowSecondaryDiagonal(int n, int** a)
{
	int prod = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i + j > n-1)
			{
				prod *= a[i][j];
			}
		}
	}
	
	return prod;
}

//int* sumColMT(int n, int** a)
//{
//	int* sumCol;
//	sumCol = (int*) malloc(n * sizeof(int));
//	
//	for (int j = 0; j < n; j++)
//	{
//		int sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			sum += a[i][j];
//		}
//		sumCol[j] = sum;
//	}
//	
//	return sumCol;
//}

//void displayArr(int n, int* a)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}

int** sumTwoMT(int n, int** a, int** b)
{
	int** sum;
	sum = (int**) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		sum[i] = (int*) malloc(n * sizeof(int));
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
	
	return sum;
}

int sumEleMT(int n, int** a)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
	}
	
	return sum;
}

int compare(int a, int b)
{
	if (a > b) return 1;
	else if ( a == b) return 0;
	else return -1;
}

int findMaxEleMT(int n, int** a)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max) max = a[i][j];
		}
	}
	
	return max;
}

int main()
{
	// Nhap vao ma tran vuong A, kieu so nguyen kich thuoc nxn
	int n;
	re:
	printf("Nhap bac cua ma tran vuong: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Bac toi thieu cua ma tran la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	printf("Nhap lan luot cac phan tu vao ma tran A:\n");
	int** a = insertMT(n, a);
	printf("Ma tran vuong A vua nhap la:\n");
	displayMT(n, a);
	
	// Kiem tra xem ma tran co phai ma tran tam giac tren hay khong
	if (isUpperTriangularMT(n, a) == true) printf("\nMa tran la mot ma tran tam giac tren!\n");
	else printf("Ma tran khong phai la mot ma tran tam giac tren!\n");
	
	// Tinh tich cac phan tu nam phia duoi duong cheo phu
	printf("\nTich cac phan tu nam phia duoi duong cheo phu bang %d\n", productBelowSecondaryDiagonal(n, a));
	
	// Hay cho biet cac cot co tong bang nhau
//	int* s = sumColMT(n, a);
//	displayArr(n, s);

	// Nhap vao mot ma tran vuong B, kieu so nguyen, cung cap voi ma tran A
	// Tinh tong 2 ma tran A + B
	printf("\nNhap lan luot cac phan tu vao ma tran B:\n");
	int** b = insertMT(n, b);
	printf("Ma tran vuong B vua nhap la:\n");
	displayMT(n, b);
	
	int** sumMT = sumTwoMT(n, a, b);
	printf("\nTong cua 2 ma tran A va B bang:\n");
	displayMT(n, sumMT);
	
	// Cho biet ma tran nao co tong lon hon
	int sumA = sumEleMT(n, a);
	int sumB = sumEleMT(n, b);
	if (compare(sumA, sumB) == 1) printf("\nTong phan tu cua ma tran A lon hon ma tran B\n");
	else if (compare(sumA, sumB) == 0) printf("\nTong phan tu cua 2 ma tran A va B bang nhau\n");
	else printf("\nTong phan tu cua ma tran B lon hon ma tran A\n");
	
	// Cho biet Max(max(A), max(B)) trong do max(A), max(B) la gia tri lon nhat
	// cua ma tran A va ma tran B
	int maxA = findMaxEleMT(n, a);
	int maxB = findMaxEleMT(n, b);
	if (compare(maxA, maxB) == 1) printf("\nMax(max(A), max(B)) = max(A)\n");
	else if (compare(maxA, maxB) == 0) printf("\nMax(max(A), max(B)) = max(A) = max(B)\n");
	else printf("\nMax(max(A), max(B)) = max(B)\n");
	
	free(a);
	free(b);
	free(sumMT);
	return 0;
}