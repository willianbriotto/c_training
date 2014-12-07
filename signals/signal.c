#include <stdio.h>
#include <signal.h> //Need import tthis header
#include <unistd.h>

void sig_handler(int signo)
{
    if(signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if(signo == SIGKILL)
        printf("received SIGKILL\n");
    else
        printf("received SIGSTOP\n");
}

int main()
{
    if(signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");

    if(signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\ncant't catch SIGKILL\n");

    if(signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    
    while(1)
        sleep(1);

    return 0;
}
