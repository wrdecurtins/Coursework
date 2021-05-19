#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int buff[10] = {3,9,1,2,5,4,2,1,1,3};
int next;

int get_next()
{
	int assign;
	assign = next;
	next++;
	if ( next > 10)
		assign = -1;
	return assign;
}

void working( int me )
{
	int mytask;
	int dur;
	printf("%d getting a job\n", me);
	#pragma omp critical
		mytask = get_next();
	while ( mytask != -1 )
	{
		dur = buff[mytask];
		printf("%d doing task %d ... so sleep %d\n", me, mytask, dur);
		sleep( dur );
		printf("%d sleeping complete\n", me);
	#pragma omp critical
		mytask = get_next();
	}
	printf("xxxxxxxxxxxxx %d\n", me);
}

int main()
{
	int i;

	i = 1;
	omp_set_num_threads(5);
	#pragma omp parallel private(i)
	{
	i = omp_get_thread_num() ;
	working( i );
	}
	return 0;
}
