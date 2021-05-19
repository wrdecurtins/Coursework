#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUMTHREADS 4

pthread_mutex_t  nextlock;


int buff[10] = {3,1,1,2,5,4,2,1,1,3};
int next = 0;

int get_next()
{
	int assign;

	
	pthread_mutex_lock( &nextlock ); 
	assign = next;
	next++;
	pthread_mutex_unlock( &nextlock ); 

	if ( assign >= 10 )
		assign = -1;

	return assign;
}

void *working( void *inp  )
{
	int me;
	int mytask;
	int dur;

	me = (long) inp;

	printf("%d getting a job\n", me);
	mytask = get_next();
	while ( mytask != -1 )
	{
		dur = buff[mytask];
		printf("%d doing task %d ... so sleep %d\n", me, mytask, dur);
		sleep( dur );	
		printf("%d sleeping complete\n", me);
		mytask = get_next();
	}
	printf("xxxxxxxxxxxxx %d\n", me);

	pthread_exit( NULL );	
}

int main()
{
	long i;
	pthread_t  tid[NUMTHREADS];

	pthread_mutex_init( &nextlock, NULL );

	for ( i = 0; i < NUMTHREADS; ++i)
	{
		pthread_create( &tid[i], NULL, working, (void *)i  );
	}

	for ( i = 0; i < NUMTHREADS; ++i)
	{
		pthread_join( tid[i], NULL );
	}

	pthread_mutex_destroy( &nextlock);

	return 0;
}
