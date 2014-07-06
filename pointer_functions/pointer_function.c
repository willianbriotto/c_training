#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void check(char *a, char *b,
                    int (*cmp) (const char *, const char *));

int main(void)
{
    char s1[80] = "Teste", s2[80] = "Teste";
    int (*p)();

    p = strcmp;

    check(s1, s2, p);

    return 0;
}

void check(char *a, char *b, 
                    int (*cmp) (const char *, const char *))
{
    if(!(*cmp) (a, b))
        printf("Ok, this string are equals \n");
    else
        printf("Direrente string \n");

    printf("The test above show the job with pointer to functions \n");   
}
