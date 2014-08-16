#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    FILE *fp;
    char ch;

    if((fp = fopen("WriteFile", "w+")) == NULL) {
        printf("File can't opent to write\n"); 
        exit(1);
    }

    printf("What's you want wrote in file?\n");

    do {
        ch = getchar();
    }
    while(sizeof(ch) == 0);

    if(putc(ch, fp) == EOF) {
        printf("Wrong: Not was possible write in file!\n");
        exit(1);
    }
    printf("File was write with success!\n");
    fclose(fp);
}
