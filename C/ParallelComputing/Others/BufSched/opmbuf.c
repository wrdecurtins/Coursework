#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int buff[10] = {3,1,1,2,5,4,2,1,1,3};
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
	int mytask = me;
	int dur;
	printf("%d getting a job\n", me);
	dur = buff[mytask];
	printf("%d doing task %d ... so sleep %d\n", me, mytask, dur);
	sleep( dur );
	printf("%d sleeping complete\n", me);
	printf("xxxxxxxxxxxxx %d\n", me);
}

int main()
{
	int i = 0;
	omp_set_num_threads( 5 );
	#pragma omp parallel
	{
		while (i < 10)
		{
			working( i );
			#pragma omp critical
			i++;
		}
	}
	return 0;
}
