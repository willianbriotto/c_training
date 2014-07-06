#include <stdlib.h>
#include <stdio.h>

int pwr(int a, int b);
void table(int p[4][10]);
void show(int p[4][10]);

void main(void)
{
    int *p;
    
    p = malloc(40 * sizeof(int));

    if(!p)
    {
        printf("Error, not enougth memory!");
        exit(1);
    }
  
    table(p);
    show(p);

}

//Create the table
void table(int p[4][10])
{
    register int i, j;

    for(j = 1; j < 11; j++)
        for(i = 1; i < 5; i++)
            p[i - 1][j - 1] = pwr(j, i);
}

//Show table
void show(int p[4][10])
{
    register int i, j;

    printf("%10s  %10s  %10s  %10s\n", "N", "N^2", "N^3", "N^4");

    for(j = 1; j < 11; j++) {
        for(i = 1; i < 5; i++)
            printf("%10d ", p[i - 1][ j - 1]);
        printf("\n");
    }
}

int pwr(int a, int b)
{
    register int t = 1;
    
    for(; b; b--)
        t = t * a;

    return t;
}
