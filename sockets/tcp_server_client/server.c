#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 5000
#define MAX_BYTES 1024
#define MAX_USERS 15
#define MESSAGE_TO_CLIENT "Welcome Client \n"

int main(int argc, char *argv[])
{
    int server, client, client_len;
    struct sockaddr_in server_addr, cli_addr;
    char data[MAX_BYTES];

    if((server = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Create fail");
        exit(1);
    }
     
    memset(&server_addr, 0, sizeof(server_addr)); //or 8 :)    
    memset(data, 0, sizeof(data));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    

    if(bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind fail");
        exit(1);
    }

    listen(server, MAX_USERS);
    client_len = sizeof(cli_addr);    
    

    while(1)
    {
        printf("Waiting for data");
        if((client = accept(server, (struct sockaddr*) &cli_addr, &client_len)) == -1) 
        {
            perror("Accept fail");
            exit(1);
        }
        memset(data, 0, sizeof(data));
        //Read message
        if(read(client, data, MAX_BYTES) == 0) 
        {
            perror("Read Error");
            exit(1);
        }
        else
            printf("Message from client: %s", data);
        //Write message
        if(write(client, MESSAGE_TO_CLIENT, sizeof(MESSAGE_TO_CLIENT)) == -1)
        {
            perror("Write Error");
            exit(1);
        }  
        close(client);
    }
    return 0;
}
