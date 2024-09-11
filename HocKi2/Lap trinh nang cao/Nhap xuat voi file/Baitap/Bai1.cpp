#include<stdio.h>
#include <math.h>

int main()
{
    FILE *file;
    int n; 
    file = fopen("input1.txt", "r");
    fscanf(file,"%d",&n);
    int A[n];
    for (int i = 0; i < n; i++)
        fscanf(file,"%d", &A[i]);
    fclose(file);

    int ans = 0;
    file = fopen("output1.txt", "w");
    for (int i = 0; i < n; i++) ans += A[i];
    fprintf(file,"%d", ans);
    fclose(file);
}


