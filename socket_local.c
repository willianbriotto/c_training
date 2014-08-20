#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sfd, cfd;
    struct sockaddr_un my_addr, peer_addr;
    socklen_t peer_addr_size;

    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sfd == -1)
        printf("Socket erro\n");

    //bzero() equivalent
    memset(&my_addr, 0, sizeof(struct sockaddr_un)); //Clear

    my_addr.sun_family = AF_UNIX;

    strncpy(my_addr.sun_path, "/socketpath", sizeof(my_addr.sun_path));
    if(bind(sfd, (struct sockaddr *) &my_addr, sizeof(my_addr.sun_path)) == -1)
        printf("Bind error\n");

    //List errors
    if(listen(sfd, 50) == -1)
        printf("Error! Bad...\n");

    peer_addr_size = sizeof(struct sockaddr_un);
    cfd = accept(sfd, (struct sockaddr *) &peer_addr, &peer_addr_size);

    if(cfd == -1)
        printf("Not Accept\n");

    return 0;
}
