#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int x, k;

	srand ( time(NULL) );

	for ( k = 1; k <= 5; k += 1)
	{
		x = rand() % 20;
		printf("%2d\n", x);
	}


	return 0;
}
