// To uses do this:
//    name_of_binary count display
// how this: name_of_binary 30 display 

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main(int argc, char *argv[])
{
    int disp, count;
    
    //Check if was passed arguments to count
    if(argc < 2) {
        printf("Put valeu in command line to count \n");
        exit(1);
    }

    if(argc == 3 && !strcmp(argv[2], "display"))
        disp = 1;
    else
        disp = 0;

    for(count = atoi(argv[1]); count; count--)
        if(disp)
            printf("%d\n", count);

    putchar('\a');

    printf("Finish \n");
}
