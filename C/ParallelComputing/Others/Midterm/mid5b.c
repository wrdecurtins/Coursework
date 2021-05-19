#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

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

	int numt = 0;
	long id = 0;

	numt = atoi(argv[1]);

	omp_set_num_threads(numt);

	#pragma omp parallel
	{
		int me = omp_get_thread_num();
		printf("Hello from %2d\n", me);
	}

	return 0;
}
