#include <stdio.h>
#include <math.h>
void NHAP(float hs[], int n)
{
	printf("Nhap lan luot %d he so cua da thuc:\n", n+1);
	for (int i = 0; i <= n; i++)
	{
		printf("He so a[%d] = ", i);
		scanf("%f", &hs[i]);
	}
}
void XUAT(float hs[], int n)
{
	printf("Da thuc vua nhap la: P(x) = ");
	for (int i = 0; i <= n; i++)
	{
		if (i != n) printf("(%.2f).x^(%d) + ", hs[i], n-i);
		else printf("(%.2f)\n", hs[i]);
	}
}
void TINH(float hs[], int n)
{
	float t;
	printf("\nNhap so thuc t tu ban phim: ");
	scanf("%f", &t);
	float bt = 0;
	for (int i = 0; i <= n; i++)
	{
		bt += hs[i] * pow(t, n-i);
	}
	if (bt == 0) printf("So thuc t = %.2f la mot nghiem cua phuong trinh P(t) = 0", t);
	else printf("So thuc t = %.2f khong phai la mot nghiem cua phuong trinh P(t) = 0", t);
	
	//
	float dh = 0;
	for (int i = 0; i <= n; i++)
	{
		dh += (n-i) * hs[i] * pow(t, n-i-1);
	}
	printf("\nDao ham cua da thuc P(t) = %.2f\n", dh);
}
void MAX(float hs[], int n)
{
	float max = hs[0];
	for (int i = 0; i <= n; i++)
	{
		if ((n-i) % 2 != 0)
		{
			if (max < hs[i]) max = hs[i];
		}
	}
	printf("\nGia tri lon nhat cua cac he so bac le cua da thuc la %.2f\n", max);
}
void SAPXEP(float hs[], int n)
{
	printf("\nCac he so sau khi duoc sap xep giam dan la: ");
	for (int i = 0; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			float temp = hs[i];
			if (hs[i] < hs[j])
			{
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (i != n)
		{
			printf("%.2f, ", hs[i]);
		}
		else printf("%.2f", hs[i]);
	}
}
main()
{
	int n;
	re:
	printf("Nhap bac cua da thuc P: ");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("Bac toi thieu la 0. Vui long nhap lai!\n");
		goto re;
	}
	float hs[n+1];
	NHAP(hs, n);
	XUAT(hs, n);
	TINH(hs, n);
	MAX(hs, n);
	SAPXEP(hs, n);
}