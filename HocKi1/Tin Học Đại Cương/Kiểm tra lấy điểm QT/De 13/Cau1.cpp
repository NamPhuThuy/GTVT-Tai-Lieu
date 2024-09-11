#include <stdio.h>
void NHAP(float a[100], int n)
{
	printf("\nNhap %d phan tu vao day so:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}
void XUAT(float a[100], int n)
{
	printf("\nDay so vua duoc nhap la: "); 
	for (int i = 0; i < n; i++)
	{
		printf("%7.2f", a[i]);
	}
	printf("\n");
}
void YC1(float a[100], int n)
{
	float x, y;
	do
	{		
		printf("\nNhap lan luot hai so thuc a va b: "); scanf("%f%f", &x, &y);
		if (x >= y) printf("Gia tri khong thoa man. Vui long nhap lai!\n");
	}
	while (x >= y);
	float tong = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			tong += a[i];
			dem++;
		}
	}
	printf("Trung binh cong cua cac phan tu nam trong khoang [%.2f, %.2f] bang %.2f\n", x, y, tong / dem);
}
void YC2(float a[100], int n)
{
	float maxch = a[0];
	for (int i = 0; i < n; i++)
	{
		if (maxch < a[i] && (int)a[i] % 2 == 0)
		{
			maxch = a[i];
		}
	}
	if ((int)maxch % 2 != 0) printf("\nTrong day so khong co mot phan tu chan nao!\n");
	else printf("\nPhan tu chan lon nhat trong day so la %.2f\n", maxch);

}
void YC3(float a[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			float temp = a[i];
			if (a[i] > a[j])
			{
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\nDay so sau khi duoc xep theo thu tu tang dan la: ");
	for (int i = 0; i < n; i++)
	{
		printf("%7.2f", a[i]);
	}
}
main()
{
	int n; printf("Nhap so luong phan tu cua day so: "); scanf("%d", &n);
	float a[100];
	NHAP(a, n);
	XUAT(a, n);
	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}