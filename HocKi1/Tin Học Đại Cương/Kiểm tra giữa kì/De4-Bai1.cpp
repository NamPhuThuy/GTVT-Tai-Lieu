#include <stdio.h>
struct DIEM
{
	float x;
	float y;
};
void NHAP(DIEM a[], int n)
{
	printf("\nNhap lan luot toa do cua %d diem:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Toa do diem thu %d:\n", i+1);
		printf("\tHoanh do x%d = ", i+1); scanf("%f", &a[i].x);
		printf("\tTung do y%d = ", i+1); scanf("%f", &a[i].y);
	}
}
void XUAT(DIEM a[], int n)
{
	printf("\nDay diem vua nhap la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("(%.2f, %.2f); ", a[i].x, a[i].y);
		else printf("(%.2f, %.2f)\n", a[i].x, a[i].y);
	}
}
void GAPKHUC(DIEM a[], int n)
{
	
}
main()
{
	int n;
	re:
	printf("Nhap so luong diem dau vao cua day diem: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 3. Vui long nhap lai!\n");
		goto re;
	}
	DIEM a[n];
	NHAP(a, n);
	XUAT(a, n);
}