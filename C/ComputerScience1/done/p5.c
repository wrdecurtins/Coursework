#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int numbars = 7, randnum = 0, times, bars;

	srand ( time( NULL ) );

	for ( times = 1; times <= numbars; times +=1 )
	{
		randnum = rand() % 15 + 1;

		printf("%2d ", randnum);

		for ( bars = 1; bars <= randnum; bars += 1 )
		{
			if ( randnum % 2 == 0 )
				printf("@");
			else
				printf("=");

			if ( bars == randnum )
				printf("\n");
		}
	}
	return 0;
}
