#include<stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    FILE *file;
    int n;
    file = fopen("input2.txt", "r");
    fscanf(file, "%d", &n);
    float X[n], Y[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%f%f", &X[i], &Y[i]);
    }
    fclose(file);

    printf("What name do you want for the output file?: ");
    char outputFile[200];
    gets(outputFile);
    int length = strlen(outputFile);
    char Extension[] = ".txt";
    for (int i = 0; i < 4; i++) outputFile[length+i] = Extension[i];
    
    file = fopen(outputFile, "w");
    float ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans += sqrt(pow(X[i] - Y[i], 2) + pow(X[i+1] - Y[i+1], 2));
    }
    fprintf(file, "%f", ans);
    fclose(file);
    printf("%f", ans);
}







