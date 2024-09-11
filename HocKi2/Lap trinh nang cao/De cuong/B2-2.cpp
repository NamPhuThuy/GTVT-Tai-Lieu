#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef long long ll;

typedef struct
{
    char price[120];
    char publisher[120], name[120];
} Book;

void Remove(char tmp[])
{
	ll n = strlen(tmp);
	if (tmp[n - 1] == '\n') tmp[n - 1] = '\0';
}

Book *Insert(int *n, char* fileName)
{
	FILE *file;
	if ((file = fopen(fileName, "r")) == NULL)
	{
		printf("Cant open file %s\n", fileName);	
		getch();
		exit(12);
	}
	
	Book *tmpList;
	fscanf(file, "%d", n);
	
	if ((tmpList = (Book*) calloc((*n)+1, sizeof(Book))) == NULL)
		printf("Cant allocate memory");
	
	char tmp[120]; fgets(tmp, 120, file);
	
    for (int i = 0; i < 5; i++)
    {	
         fgets(tmpList[i].name, 120, file); Remove(tmpList[i].name); fflush(stdin);
         fgets(tmpList[i].publisher, 120, file); Remove(tmpList[i].publisher); fflush(stdin);
		fgets(tmpList[i].price, 120, file); Remove(tmpList[i].price);
	//	fscanf(file, "%d\n", tmpList[i].price);
    }
	return tmpList;
}

void Print(Book *books, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", books[i].name);
        printf("%s\n", books[i].publisher);
        printf("%s\n", books[i].price);
    }
}

void Sort(Book *books, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (((strcmp(books[i].price, books[j].price) < 0) && strlen(books[i].price) == strlen(books[j].price))
				|| strlen(books[i].price) < strlen(books[j].price))
			{
				Book tmp = books[i];
				books[i] = books[j];
				books[j] = tmp;
			}
		}
	}
}

int main()
{
    int n, k; 
    Book *books;
    char fileName[1024];
    printf("Insert fileName: "); gets(fileName); fflush(stdin);
    books = Insert(&n, fileName);
    Print(books, n);
    Sort(books, n);
    Print(books, n);
    free(books);
}
