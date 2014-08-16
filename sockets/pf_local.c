#include <stdio.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <errno.h>

int main()
{
   int socket_pf_unix;
   //PF_UNIX -- He is for process in same PC
   //SOCK_STREAM -- By stream
   //Can be SOCK_DGRAM -- By diagrams that preserves limits of messages
   socket_pf_unix = socket(PF_UNIX, SOCK_STREAM, 0);
   if(socket_pf_unix == -1)
       perror("Fail"); //When socket fail, return -1
   else {
       printf("Socket number %d\n", socket_pf_unix);
       close(socket_pf_unix);
   }
   return 0;
}
//Fonte: https://github.com/marcosps/c_exercises/blob/master/sockets/tcp/socket_1.c


