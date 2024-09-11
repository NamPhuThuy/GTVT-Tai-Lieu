// Ð? bài: Nh?p vào m?t ma tr?n vuông ki?u nguyên
// Yêu c?u:
// yc1: In ra màn hình du?i d?ng b?ng
// yc2: Tìm min c?a ma tr?n
// yc3: Tìm min các ph?n t? âm c?a ma tr?n
// yc4: Tìm max t?ng hàng
// yc5: Tìm max t?ng c?t
// yc6: Tìm max các ph?n t? n?m du?i du?ng chéo chính
// yc7: Tìm max các ph?n t? n?m trên du?ng chéo chính
// yc8: Tính t?ng t?ng c?t, cho bi?t các c?t có t?ng l?n nh?t
// yc9: Tính t?ng t?ng hàng, cho bi?t các hàng có t?ng nh? nh?t
// yc10: 

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

void insertMatrix(int **a, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void displayMatrix(int **a, int rows, int cols)
{
	printf("Ma tran la:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}		
}

int findMin(int **a, int rows, int cols)
{
	int min = INT_MAX;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (min > a[i][j]) min = a[i][j];
		}
	return min;
}

int findNegaMin(int **a, int rows, int cols, int *check)
{
	int min = INT_MAX;
	*check = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] < 0)
			if (min > a[i][j]) 
			{
				min = a[i][j];
				*check = 1;
			}		
		}
	return min;
}

int *sumCols(int **a, int rows, int cols, int *k)
{
	int *sc;
	sc = (int*) malloc((cols+1) * sizeof(int));
	*k = 0;
	for (int j = 0; j < cols; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += a[i][j];
		}
		sc[*k] = sum;
		*k += 1;
	}
	return sc;
}

int *findMaxArray(int *a, int k, int *l)
{
	int max = INT_MIN;
	for (int i = 0; i < k; i++)
	{
		if (max < *(a+i)) max = *(a+i);
	}
	
	int *ac;
	ac = (int*) malloc((k+1) * sizeof(int));
	*l = 0;
	for (int i = 0; i < k; i++)
	{
		if (*(a+i) == max)
		{
			ac[*l] = i;
			*l += 1;
		}
	}
	return ac;
}

void displayArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.\n", *(a+i));
	}
}

int *findMaxEachRows(int **a, int rows, int cols, int *k)
{
	int *mER;
	mER = (int*) malloc((rows+1) * sizeof(int));
	*k = 0;
	for (int i = 0; i < rows; i++)
	{
		int max = INT_MIN;
		for (int j = 0; j < cols; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
		}
		mER[*k] = max;
		*k += 1;
	}	
	return mER;
}

float greaterThan10(int **a, int rows, int cols, int *count, int *check)
{
	*check = 0;
	*count = 0;
	int result = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] > 10)
			{
				result += a[i][j];
				*count += 1;
				*check = 1;
			}
		}
	}
	return (float)result / count;
}

bool isLowerTriangularMatrix(int **a, int rows, int cols)
{
	bool check = false;
	if (rows == cols)
	{
		for (int j = 1; j < cols; j++)
		{
			for (int i = 0; i < j - 1; i++)
			{
				if (a[i][j] == 0)
				{
					check = true;
				}	
				else
				{
					check = false;
					break;
				}		
			}
		}
	}
	else return check;
	
	return check;
}

int multiNegaSubDiagonal(int **a, int rows, int cols, int *check)
{
	int result = 1;
	*check = 0;
	if (rows == cols)
	{
		int j = cols - 1;
		for (int i = 0; i < rows; i++)
		{		
			if (a[i][j] < 0)
			{
				result *= a[i][j];
			}
			j -= 1;
		}
	}
	else 
	{
		*check = 1;
	}
	return result;
}
int main()
{
	// Enter the number of rows and cols of the matrix
	int rows, cols;
	re1:
	printf("Enter the number of rows: "); 
	scanf("%d", &rows);
	if (rows <= 0)
	{
		printf("The minimum value of rows is 1. Please enter again!\n");
		goto re1;
	}
	printf("Enter the number of cols: "); 
	scanf("%d", &cols);
	if (cols <= 0)
	{
		printf("The minium value of cols is 1. Please enter again!\n");
	}
	
	int **a;
	// Allocate dynamic memory for array of level 1 pointers
	a = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		// Dynamic memory allocation for each level 1 pointers
		*(a+i) = (int*)malloc(cols * sizeof(int));
	}
	
	insertMatrix(a, rows, cols);	
	displayMatrix(a, rows, cols);
	
	// Tim phan tu nho nhat cua ma tran
	printf("\nPhan tu nho nhat cua ma tran co gia tri bang %d\n", findMin(a, rows, cols));
	
	// Tim phan tu am nho nhat cua ma tran
	int check;
	int negaMin = findNegaMin(a, rows, cols, &check);
	if (check == 0) printf("\nMa tran khong co phan tu nao am!\n");
	else printf("\nPhan tu am nho nhat cua ma tran co gia tri bang %d\n", negaMin);
	
	// Tinh tong tung cot, in ra cac cot co tong lon nhat
	int k1;
	int *sc = sumCols(a, rows, cols, &k1);
	printf("\nTong phan tu cua cac cot lan luot la: "); 
	displayArray(sc, k1);
	
	int k2;
	int *ac = findMaxArray(sc, k1, &k2);
	printf("Cac cot co tong lon nhat la: ");
	displayArray(ac, k2);
	
	// Find max value of each rows
	int k3;
	int *mER = findMaxEachRows(a, rows, cols, &k3);
	printf("\nGia tri lon nhat cua tung hang lan luot la: ");
	displayArray(mER, k3);
	
	// Dem cac phan tu duong lon hon 10 co trong ma tran
	int count1;
	float result1 = greaterThan10(a, rows, cols, &count1, &check);
	if (check == 0) printf("\nKhong co phan tu nao co gia tri duong lon hon 10!\n");
	else printf("\nCo tat ca %d phan tu co gia tri duong lon hon 10!\n", count1);
	
	// Kiem tra xem ma tran co phai ma tran tam giac duoi hay khong. Tinh tich cac phan tu am thuoc duong cheo phu
	if (isLowerTriangularMatrix(a, rows, cols)) printf("\nThe matrix is a lower triangular matrix!\n");
	else printf("\nThe matrix isn't a lower triangular matrix!\n");
	
	int multiNega = multiNegaSubDiagonal(a, rows, cols, &check);
	if (check == 0) printf("There is no negative element on the sub diagonal of the matrix!\n");
	else printf("The result of multiplication of negative elements on the sub diagonal of the matrix is %d.\n", multiNega);
	
	// Tinh trung binh cong cac phan tu lon hon 10 trong ma tran
	if (check == 0) printf("\nKhong co phan tu nao co gia tri duong lon hon 10!\n");
	else printf("\nCo tat ca %.2f phan tu co gia tri duong lon hon 10!\n", result1);
}