#include <stdio.h>

void main(int argc, char *argv[])
{
    int t, i;

    for(t = 0; t < argc; t++) {
        i = 0;

        while(argv[t][i]) {
            putchar(argv[t][i]);
            ++i;
        }
    }
    printf("\n");
}
