#include<stdio.h>
#include <math.h>

int main()
{
    FILE *file;
    int i;
    file = fopen("Output.txt", "w"); // w hoac w+t hoac wt
    fprintf(file,"Nothing to do here");
    fprintf(file, "********************************");
}
