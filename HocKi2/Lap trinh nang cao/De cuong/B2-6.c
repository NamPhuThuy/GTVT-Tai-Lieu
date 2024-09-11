#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
	char MS[100], TS[100], TTG[100];
	int NXB, GIA;
} Book;

void Remove(char a[])
{
	int n = strlen(a);
	if (a[n-1] == '\n') a[n-1] = '\0';
}

Book *insert(int *n, char *fileName)
{
	FILE *file;
	if ((file = fopen(fileName, "r")) == NULL)
	{
		printf("Cant open file");
		getch();
		exit(12);
	}
	
	Book *tmpList;
	fscanf(file, "%d\n", n);
	
	if ((tmpList = (Book*) calloc((*n) + 1, sizeof(Book))) == NULL)
		printf("Cant allocate memory\n");
	
	int i;
	
	for (i = 0; i < *n; i++)
	{
		fflush(stdin);
		fgets(tmpList[i].MS, 100, file); Remove(tmpList[i].MS); fflush(stdin);
		fgets(tmpList[i].TS, 100, file); Remove(tmpList[i].TS); fflush(stdin);
		fgets(tmpList[i].TTG, 100, file); Remove(tmpList[i].TTG); 
		
		fscanf(file, "%d\n", &tmpList[i].NXB);
		fscanf(file, "%d\n", &tmpList[i].GIA);
	}
	
	fclose(file);
	return tmpList;
}

void print(Book *bookList, int n)
{
	int i = 0;
	for (i; i < n; i++)
	{
		printf("%s\n", bookList[i].MS);
		printf("%s\n", bookList[i].TS);
		printf("%s\n", bookList[i].TTG);
		
		printf("%d\n", bookList[i].NXB);
		printf("%d\n", bookList[i].GIA);
	}
}

void sort(Book *bookList, int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	for (j = i + 1; j < n; j++)
	{
		if (bookList[i].GIA > bookList[j].GIA)
		{
			Book tmp = bookList[i];
			bookList[i] = bookList[j];
			bookList[j] = tmp;
		}
	}
}

void printfile(Book *books, int n)
{
	
}

int main()
{
	char fileName[100];
	printf("Insert filename pls: ");
	scanf("%s", fileName);
	
	int n;
	Book *bookList;
	bookList = insert(&n, fileName);
	print(bookList, n);
	printf("\n");
	sort(bookList, n);
	print(bookList, n);
	free(bookList);
}
