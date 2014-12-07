#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if(signo == SIGINT)
        printf("received SIGINT\n");
}

int main()
{
    if(signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");

    while(1)
        sleep(1);
    return 0;
}
