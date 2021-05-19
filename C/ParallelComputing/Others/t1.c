
// CSC 410
// Starting sample file:  Wed 9/4

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMT 8

int calc[NUMT + 1] = {0};

void *threadcalc ( void *param )
{
	long myid;
	myid = (long) param;

	calc[myid] = 0;

	if ( myid % 2 == 0 )
		for ( int k = 1; k <= myid; k++ )
			calc[myid] = calc[myid] + k;
	if ( myid % 2 == 1 )
	{
		calc[myid] = 1;
		for ( int k = 1; k <= myid; k++ )
			calc[myid] = calc[myid] * k;
	}

//	printf("Hi from thread %ld, calc = %d\n", myid, calc[myid]);
	pthread_exit(NULL);
}

int main()
{

	long i;
	void *status;

	pthread_t tid[NUMT + 1];

//	printf("In main: time to build threads\n");

	for(i = 1; i < NUMT + 1; i++ )
	{
//		printf(" Creating %ld\n", i);

		//pthread_create( thread ID , NULL, entry fun, param to fun);
		pthread_create( &tid[i], NULL, threadcalc, (void *)i);

	}

//	printf("In main: all threads created\n");

	for(i = 1; i < NUMT + 1; i++)
	{
		pthread_join( tid[i], &status );

//		printf("   Main: joined %d\n", i);
	}

//	printf("In main:  all threads joined\n");

	calc[0] = 0;

	for ( i = 1; i <= NUMT; i++ )
	{
		printf("Thread %d value: %5d\n", i, calc[i]);
		calc[0] = calc[0] + calc[i];
	}
	printf("\nSum of all values: %5d\n", calc[0]);

	return 0;
}


