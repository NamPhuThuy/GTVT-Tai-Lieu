#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int max(int x, int y)
{
	if (x > y) return x;
	return y;
}

int min(int x, int y)
{
	if (x < y) return x;
	return y;
}

void Read(char *Filename, int *n, int *m, float **a, float **b)
{
	FILE *file;
	if ((file = fopen(Filename, "rt")) == NULL)
	{
		printf("re-check the filename bro\n");
		getch();
		exit(1);
	};
	fscanf(file,"%d%d", n, m);
	if ((*a = (float*) calloc(*n+1, sizeof(float))) == NULL) printf("Cant allocate array\n");
	if ((*b = (float*) calloc(*m+1, sizeof(float))) == NULL) printf("Cant allocate array\n");
	
	for (int i = 0; i <= *n; i++) fscanf(file, "%f", *a+i);
	for (int i = 0; i <= *m; i++) fscanf(file, "%f", *b+i);
	fclose(file);
}

void Print(int n, float *a, char Name)
{
	printf("%c = ", Name);
	printf("%.2f*x^0", a[0]);
	for (int i = 1; i <= n; i++) 
	{
		if (a[i] < 0)
		{
			printf(" - %.2f*x^%d", a[i]*-1, i);
		} 
		else
		printf(" + %.2f*x^%d", a[i], i);
	}
	printf("\n");
}

float Count(int n, float *a, float x)
{
	float sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += (a[i]*pow(x, i));
	}
	
	return sum;
}

void Subtract(float *a, int n, float *b, int m)
{
	float *c = (float*) calloc((max(n, m) + 1), sizeof(float));
	for (int i = 0; i <= min(n, m); i++)
	{
		c[i] = a[i] - b[i];
	}
	
	if (n > m)
	{
		for (int i = min(n, m) + 1; i <= max(n, m); i++) c[i]= a[i];
	}
	else 
	{
		for (int i = min(n, m) + 1; i <= max(n, m); i++) c[i] = -b[i];
	}
	
	for (int i = 0; i <= max(n, m); i++) printf("%.2f ", c[i]);
}

int main()
{
	char Filename[120]; 
	printf("What is the filename?: ");
	gets(Filename);
	
	float *a, *b;
	int n, m;
	Read(Filename, &n, &m, &a, &b);
	Print(n, a, 'P');
	Print(m, b, 'Q');
	
	printf("\nInsert x, y bro: ");
	float x, y; scanf("%f%f", &x, &y);
	
	float S = Count(n, a, x) / Count(m, b, y);
	printf("\nS = P(%.2f) / Q(%.2f) = %.3f\n", x, y, S);
	
	Subtract(a, n, b, m);
	free(a);
	free(b);
}
