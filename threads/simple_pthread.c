#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS	5

void *print(void *threadid)
{
    long tid; //thread id
	tid = (long)threadid;
	printf("Thread Id: #%ld!\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS]; //Create [NUM_THREADS] threads
	int rc;
	int t;
	
	for(t = 0; t < NUM_THREADS; t++) {
	    printf("Creating thread: %ld\n", t);
		//get returned value of pthread_create
		rc = pthread_create(&threads[t], NULL, print, (void *)t);
		if(rc) { //if value != 0
		    printf("Error: code returned is %d\n", rc);
			exit(1);
		}
	}
	
	//Last thing that main() should do
	pthread_exit(NULL);
}