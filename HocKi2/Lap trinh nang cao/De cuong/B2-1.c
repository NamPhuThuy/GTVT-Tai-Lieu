#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef long long ll;

struct Contestant
{
 
    char name[120], unit[10];
    float mark;

    // COntestant Contestant(char *name, float mark, char *unit)
    // {
    //     this->name = strdup(name);
    //     this->mark = mark;
    //     this->unit = unit;
    // }
};

Read(struct Contestant *list, int *n)
{
    FILE *file;
    char fileName[120]; gets(fileName);
    if (file = fopen (fileName, "r") == NULL)
        printf("Can't open file '%s'\n", fileName);
    fscanf(file, "%d", &n);
    list = (struct Contestant *) malloc((*n)*sizeof(struct Contestant)); 
}

int main()
{
    struct Contestant *contestantsList;
    int i, n;
    

    
    
    Read(&contestantsList, &n);

}