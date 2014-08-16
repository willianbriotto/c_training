#include <stdio.h>
#include <stdlib.h>

void main(void) 
{
    FILE *fp;
    if((fp = fopen("Test", "w")) == NULL) {
        printf("Crash, file not open");
        exit(1);
    }
    printf("Sucess to open file!\n");
    printf("Now you can press any key for close the file:\n");
    getchar();
    if(!fclose(fp))
        printf("Ok, your file was closed\n");
    else {
        printf("Bad, file no close. Now lets do a crash\n");
        exit(1);
    }
}
