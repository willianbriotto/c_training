#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    struct flock flo;

    if(argc < 1)
    {
        printf("Is needs a path/file :)");
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR)) == -1)
    {
        perror("Open error");
        exit(1);
    }

    //Set Lock
    flo.l_type = F_WRLCK;//Lock to write
    flo.l_whence = SEEK_SET;
    flo.l_start = 0;
    flo.l_len = 150;
    
    if(fcntl(fd, F_SETLK, &flo) == -1)
    {
        perror("File locking error");
        exit(1);
    }
    else
        printf("File locked \n");

    int own = 0;
    if((own = fcntl(fd, F_GETOWN, &flo)) != -1)
    {
        if(own > 0)//0 PID OR GID is?
            printf("The PID own is %d\n", own);
        else
            printf("The GID own id %d\n", own);
    }

    char _ulk[1];
    printf("You want unloking file start/len byte? S or Any ");
    scanf("%s", _ulk);

    if(strcmp("s", _ulk) != 0)
    {
        flo.l_type = F_UNLCK;
        flo.l_whence = SEEK_SET;
        flo.l_start = 0;
        flo.l_len = 150;
        if(fcntl(fd, F_SETLK, &flo) == -1)
        {
            perror("Unloking error");
            exit(1);
        }
        else
            printf("File bytes unloking with success\n");
    }
    else
        printf("File still is locked\n");

    return 0;
}
