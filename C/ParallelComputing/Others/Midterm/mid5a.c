#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_barrier_t barr;

void *work ( void *param )
{
	long tid;
	tid = (long) param;

	printf("Hi from %2d!\n", tid );

	pthread_exit(NULL);
}

int main ( int argc, char *argv[] )
{
	if ( argc != 2 )
	{
		printf("Invalid number of arguements\n");
		return 0;
	}

	if ( atoi(argv[1]) <= 0 )
	{
		printf("Invalid arguement, need nonzero positive integer\n");
		return 0;
	}

	void *status;

	int numt = 0;
	long id = 0;

	numt = atoi(argv[1]);

	pthread_t tid[numt];

	pthread_barrier_init( &barr, NULL, numt );

	for ( id = 0; id < numt; id++ )
	{
		pthread_create( &tid[id], NULL, work, (void *) id);
	}

	for ( id = 0; id < numt; id++ )
	{
		pthread_join( tid[id], &status);
	}

	return 0;
}
