
// CSC 410
// Starting sample file:  Wed 9/4

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMT 4

void *sayhi ( void *param )
{
	long myid;
	myid = (long) param;

	printf("Hi from thread %ld\n", myid);
	pthread_exit(NULL);
}

int main()
{

	long i;
	void *status;

	pthread_t tid[NUMT];

	printf("In main: time to build threads\n");

	for(i = 0; i < NUMT; i++ )
	{
		printf(" Creating %ld\n", i);

		//pthread_create( thread ID , NULL, entry fun, param to fun);
		pthread_create( &tid[i], NULL, sayhi, (void *)i);

	}

	printf("In main: all threads created\n");

	for(i = 0; i < NUMT; i++)
	{
		pthread_join( tid[i], &status );

		printf("   Main: joined %d\n", i);
	}

	printf("In main:  all threads joined\n");

	return 0;
}


