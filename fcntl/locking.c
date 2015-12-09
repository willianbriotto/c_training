#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fc;
    struct flock flo;
    
    if(argc < 1) 
    {
        printf("We needs of a file path :)");
        exit(1);
    }

    if((fc = open(argv[1], O_RDWR)) == -1) 
    {
       perror("Open error");
       exit(1);
    }

    flo.l_type = F_WRLCK; //Flock type
    flo.l_whence = SEEK_SET;
    flo.l_start = 0;
    flo.l_len = 150;//Flock byte end

    if(fcntl(fc, F_SETLK, &flo) == -1)
    {
        perror("Found error");
        exit(1);
    }
    else
        printf("Loking file from %d to %d with success \n", 
               (int)flo.l_start, (int)flo.l_len);
    return 0;
}
