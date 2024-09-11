#include<stdio.h>
#define MAX 100
void nhap(float a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%f", &a[i]);
	}
}
void xuat(float a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%.2f ", a[i]);
	}
}
float tong(float a[], int n)
{
	if(n == 1) return a[0];
	else return a[n - 1] + tong(a, n-1);
}

int count(float a[], int n)
{
	
    if(n == (-1)) return 0;
    else
    {
        if(a[n] > 0) return  1 + count(a, n-1);
        else return count(a, n-1);
    }
	
}

int max(float a[], int n)
{
	if(n == 1) return a[0];
	if(a[n-1] > max(a, n-1)) return a[n-1];
	return max(a, n-1);
}

int main()
{
	float a[MAX];
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	printf("\nHay nhap day so: ");
	nhap(a, n);
	
	printf("\nDay vua nhap la: ");
	xuat(a, n);
	printf("\nTong day so = %.2f ", tong(a,n));
	printf("\nSo phan tu lon hon 0 la %d", count(a, n-1));
	printf("\nGia tri lon nhat cua day la %d ", max(a, n));
}
