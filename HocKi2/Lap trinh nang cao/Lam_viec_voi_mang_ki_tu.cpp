#include<stdio.h>
#include <string.h>

//Kiem tra co bat dau bang
bool check(char s[])
{
	for(int i = 0; i < strlen(s); i++)
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
		{
			return false;
		}
	}
	
	return true;
}

//Dem so tu trong chuoi
int DemTu(char  s[],int length)
{
	int word = (s[0] != ' ');
    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            word++;
        }
    }
    return word;
}
void KiTuTrai(char s[],int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%c", s[i]);
	}
}

int main()
{
	char s[1000];
	
	printf("Nhap chuoi: ");
	gets(s);
	int length = strlen(s);
	
	
	
	if(check(s)) 
		printf("Chuoi nhap vao la chuoi so");
	else printf("Chuoi nhap vao khong phai chuoi so");
	
	printf("\nChuoi nhap vao co %d tu", DemTu(s, length));
	
	int n;
	printf("\n\nNhap so ki tu ben trai muon in ra: ");
	scanf("%d",&n);
	KiTuTrai(s, n);
	
}
