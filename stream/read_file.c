#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if(argc != 1) {
       if((fp = fopen(argv[1], "r")) == NULL) {
           printf("File can't be open!\n");
           exit(1);
      }
      
      ch = getc(fp);
      
      do {
         putchar(ch);
         ch = getc(fp);    
      } 
      while(ch != EOF);
      printf("\n\n\nHere is end of file!\n");
    }
    exit(1);
}
