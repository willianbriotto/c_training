/*
*
*   Problem:
*
*   What is the work done by a force applied to a body of mass 5kg and that causes an acceleration of X m/s² and travels for a distance of 100m?
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS	5
#define MASS 5
//Meters
#define DISTANCE 100

float metrosSegundo[NUM_THREADS];

void *print(void *threadid)
{
    int *id_ptr, taskid;
    
	sleep(1);
    id_ptr = (int *) threadid;
    taskid = *id_ptr;
    printf("Work with %f m/s²: %f\n", metrosSegundo[taskid], (MASS * metrosSegundo[taskid] * DISTANCE));
    pthread_exit(NULL);
}
	
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS]; //Num of threads
	int *taskids[NUM_THREADS];
	int rc, t;
	
	metrosSegundo[0] = 1.5;
	metrosSegundo[1] = 2.7;
	metrosSegundo[3] = 3.2;
	metrosSegundo[4] = 5.8;
	
	for(t = 0; t < NUM_THREADS; t++) {
		taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;
		printf("Creating thread: %d\n", t);
		rc = pthread_create(&threads[t], NULL, print, (void *) taskids[t]);
		if(rc) {
            printf("Error: code returned is %d\n", rc);
			exit(1);
		}
	}
	
	pthread_exit(NULL);
}