#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef long long ll;

float** ReadMatrix(char *filename, int *rows, int *cols)
{
    float **tmpMatrix;
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("Couldn't open file %s\n", filename);
        getch();
        exit(12);
    }

    fscanf(file, "%d%d", rows, cols);
    tmpMatrix = (float**) calloc((*rows)+1, sizeof(float*));
    int i, j; 
    for (i = 0; i < *rows; i++)
    {
        tmpMatrix[i] = (float*) calloc((*cols)+1, sizeof(float));
    }

    for (i = 0; i < *rows; i++)
    for (j = 0; j < *cols; j++)
    {
        float t; fscanf(file,"%f", &t);
        tmpMatrix[i][j] = t;
    }

    fclose(file);
    return tmpMatrix;
}

void printMatrix(float **Matrix, int rows, int cols)
{
    int i, j;
    printf("The Matrix be read from file:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++) 
        {
            printf("%.1f ", Matrix[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    char fileName[1024];
    int rows, cols;
    float **Matrix;
    printf("Insert fileName: "); gets(fileName);
    Matrix = ReadMatrix(fileName, &rows, &cols);
    int i;
    
    printMatrix(Matrix, rows, cols);
    for (i = 0; i < rows; i++) free(Matrix[i]);
    free(Matrix);
}
