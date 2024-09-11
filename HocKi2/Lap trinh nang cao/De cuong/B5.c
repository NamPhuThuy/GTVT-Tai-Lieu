#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int i,j;
typedef struct{
	int bac;
	float *a;
}Dathuc;

void nhap(Dathuc *s, int n)
{
    for(i=0;i<n;i++)
	{
		printf("Da thuc thu %d:\n", i+1);
		printf("Bac: "); scanf("%d",&s[i].bac);
		s[i].a=(float*)calloc(s[i].bac+1, sizeof(float));
		printf("Cac he so cua da thuc P%d :\n", i+1);
		for(j=0;j<=s[i].bac;j++)
		  {
		  	scanf("%f", &s[i].a[j] );
		  }
	}	
}
void in(Dathuc *s, int n)
{
	for(i=0;i<n;i++)
	{
		printf("\nP%d = %.1f ", i+1, s[i].a[0]);;
		for(j=1;j<=s[i].bac;j++)
		  printf("+ %.1f * x^%d ", s[i].a[j],j);
	}
}
void sapxep(Dathuc *s, int n)
{
	Dathuc t;
	for(i = 0; i < n-1; i++)
	 {
	 	for(j = i + 1; j < n; j++)
	 	{
	 		if(s[i].bac < s[j].bac)
	 		{
	 			t = s[i];
	 			s[i] = s[j];
	 			s[j] =t;
			 }
		 }
	 }
	printf("\nCac da thuc sap xep theo thu tu giam dan cua bac:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d = %.1f ", i+1, s[i].a[0]);;
		for(j=1;j<=s[i].bac;j++)
		  printf("+ %.1f * x^%d ", s[i].a[j],j);
	}
}

void sum(Dathuc a, Dathuc b)
{
	Dathuc t;
	if()
}
main()
{
	int n;
	printf("n = ");
	scanf("%d",&n);
	Dathuc *s = (Dathuc*)calloc(n,sizeof(Dathuc));
	
	nhap(s,n);
	in(s,n);
	sapxep(s,n);
}

