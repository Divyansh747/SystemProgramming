#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Mutex declaration */
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *signal_status(void *ptr)
{
	/* Lock Mutex */
	pthread_mutex_lock(&mutex1);
	char *message;
	message = (char *)ptr;
	
	for(int i=0;i<3;i++){
	sleep(1);
	printf("%s\n", message);
	}
	/* Unlock Mutex */
	pthread_mutex_unlock(&mutex1);
	
}

/* Main Function */
int main()
{
	/* Thread declaration*/
	pthread_t thread1, thread2, thread3;

	/* Vars section */
	char *light_status1 = "RED LIGHT     : CAR STOPS!!!";
	char *light_status2 = "YELLOW LIGHT  : CAR ENGINE STARTS";
	char *light_status3 = "GREEN LIGHT   : CAR GOES...."; 
	
	int ctr=5;

	/* Thread   Creation & Joining */	
	while(ctr > 0) {
	printf("************************************************************\n");
	
    printf("Thread 1:\n");
	pthread_create(&thread1, NULL, signal_status,(void *)light_status1);
	pthread_join(thread1, NULL);
	
    printf("Thread 2:\n");
	pthread_create(&thread2, NULL, signal_status,(void *)light_status2);
	pthread_join(thread2, NULL);
	
    printf("Thread 3:\n");
	pthread_create(&thread3, NULL, signal_status,(void *)light_status3);	
	pthread_join(thread3, NULL);
	
	ctr--;	//counter
	}
	printf("************************************************************\n");
	printf("**** STOPPED! ****\n");
	
	exit(0);
}
