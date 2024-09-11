#include <stdio.h>
#include <math.h>
main()
{
	// Gia thiet
	int n;
	re1:
	printf("Nhap bac cua Da thuc P: "); scanf("%d", &n);
	if (n < 0)
	{
		printf("Bac toi thieu cua da thuc la 0. Vui long nhap lai!\n");
		goto re1;
	}
	
	float hsP[n+1];
	printf("Nhap lan luot %d he so cua Da thuc P:\n", n);
	for (int i = 0; i <= n; i++)
	{
		printf("He so thu %d: ", i+1);
		scanf("%f", &hsP[i]);
	}
	
	printf("\nDa thuc P = ");
	for (int i = 0; i <= n; i++)
	{
		if (n == 0) printf("(%.2f)", hsP[i]);
		else 
		{
			if (i != n)
			{
				printf("(%.2f).x^%d + ", hsP[i], n-i);
			}
			else printf("(%.2f)", hsP[i]);
		}
	}
	printf("\n");
	
	// Yeu cau 1
	float x; printf("Nhap so thuc x: "); scanf("%f", &x);
	float p = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i != n) p += hsP[i] * pow(x, n-i);
		else p += hsP[i];
	}
	float dhp = 0;
	for (int i = 0; i < n; i++)
	{
		dhp += (n-i) * hsP[i] * pow(x, n-i-1);
	}
	printf("Gia tri cua bieu thuc S bang %.2f", sqrt(2021 + p + dhp));
	
	// Yeu cau 2
	int m;
	re2:
	printf("\n\nNhap bac cua Da thuc Q: "); scanf("%d", &m);
	if (m < 0)
	{
		printf("Bac toi thieu cua da thuc la 0. Vui long nhap lai!\n");
		goto re2;
	}
	
	float hsQ[n+1];
	printf("Nhap lan luot %d he so cua Da thuc Q:\n", n);
	for (int i = 0; i <= m; i++)
	{
		printf("He so thu %d: ", i+1);
		scanf("%f", &hsQ[i]);
	}
	
	printf("\nDa thuc Q = ");
	for (int i = 0; i <= m; i++)
	{
		if (m == 0) printf("(%.2f)", hsQ[i]);
		else 
		{
			if (i != m)
			{
				printf("(%.2f).x^%d + ", hsQ[i], m-i);
			}
			else printf("(%.2f)", hsQ[i]);
		}
	}
	printf("\n");
	if (m == n) printf("\nHai da thuc P va Q co cung bac!");
	else 
	{
		printf("\nDa thuc hieu P(x) - Q(x) = ");
		if (n > m)
		{
			float hs[n+1];
			for (int i = 0; i < n-m; i++)
			{
				hs[i] = hsP[i];
				printf("(%.2f).x^%d + ", hs[i], n-i);
			}
			for (int i = n-m, j = 0; i <= n; i++, j++)
			{
				hs[i] = hsP[i] - hsQ[j];
				if (i != n) printf("(%.2f).x^%d + ", hs[i], n-i);
				else printf("(%.2f)", hs[i]);
			}
		}
		else
		{
			float hs[m+1];
			for (int i = 0; i < m-n; i++)
			{
				hs[i] = hsQ[i];
				printf("(%.2f).x^%d + ", hs[i], m-i);
			}
			for (int i = m-n, j = 0; i <= m; i++, j++)
			{
				hs[i] = hsQ[i] - hsP[j];
				if (i != m) printf("(%.2f).x^%d + ", hs[i], m-i);
				else printf("(%.2f)", hs[i]);
			}
		}
	}
}