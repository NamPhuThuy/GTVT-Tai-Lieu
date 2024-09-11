#include <stdio.h>
#include<string.h>

int checkDigitString(char A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!(A[i] >= '0' && A[i] <= '9')) return 0;
	}
	return 1;
}

int countWord(char A[], int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == ' ') ans++;
	}
	
	return ans+1;
}

int main()
{
	char A[100001];
	gets(A);
	if (checkDigitString(A, strlen(A)) == 1) printf("Chuoi nhap vao la chuoi so\n");
	else printf("Chuoi vua nhap khong phai la chuoi so\n");
	
	printf("So tu cua xau la %d", countWord(A, strlen(A)));
}
