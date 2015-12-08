#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5000
#define MAX_BYTES 1024
#define MESSAGE_TO_SERVER "Hi, my names id Client"

int main(int argc, char *argv[])
{
    int client;
    struct sockaddr_in server;
    char data[MAX_BYTES];

    if((client = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Create error");
        exit(1);
    }

    memset(&server, 0, sizeof(server)); // 8 is the same
    memset(data, 0, sizeof(data));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    if(connect(client, (struct sockaddr*)&server, sizeof(server)) == -1)
    {
       perror("Connect error");
       exit(1);
    }

    printf("Now you is connected with the server \n");

    if(write(client, MESSAGE_TO_SERVER, sizeof(MESSAGE_TO_SERVER)) == -1) {
        perror("Write was fail");
        exit(1);
    }
    
    while(read(client, data, MAX_BYTES) > 0)
    {
        printf("Message received is: %s", data);
    }
    return 0;
}
