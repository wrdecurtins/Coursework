#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int x, k;
	int howmany = 0;


	srand ( time(NULL) );
	x = rand() % 20;

	while ( x != 18 )
	{
		printf("%2d\n", x);
		howmany += 1;
		x = rand() % 20;
	}

	printf("Generated %d numbers\n", howmany);

	return 0;
}
