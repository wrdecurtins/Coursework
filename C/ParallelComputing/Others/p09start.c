
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS	5

int glob = 0;

void *sayhi( void *param)
{
	long myid;
	myid = (long)  param;
 	printf("hi from %ld\n", myid);
	printf("   %ld global is %d\n", myid, glob);
 	glob = glob + 1;
	pthread_exit(NULL);	
}

int main()
{
	pthread_t tids[NUM_THREADS];
	long t;
	void *status;

	printf("In main: time to build threads\n");
	glob = 20;

	for (t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n", t);
		pthread_create( &tids[t], NULL, sayhi, (void *) 1000+t  );
	}

	printf("In main: all threads created\n");

	for (t=NUM_THREADS-1; t >= 0; t--)
	{
		pthread_join( tids[t], &status );
		printf("Main: joined %ld\n", t);
	}

	printf("In main:  all threads joined\n");

//	pthread_exit( NULL );
	
	return 0;
}

