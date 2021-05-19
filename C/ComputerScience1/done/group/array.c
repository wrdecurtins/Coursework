#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int sum, max, min, k;
	int mylist[20];

	srand( time(NULL) );

	for ( k = 0; k < 20; k++ )
	{
		mylist[k] = rand() % 1000 + 1;
	}

	for ( k = 0; k < 20; k++ )
	{
		printf("%d ", mylist[k]);
	}
	printf("\n");

	for ( k = 0; k < 20; k++ )
		sum = sum + mylist[k];
	printf("Sum:  %d\n", sum);

	max = mylist[0];

	for ( k = 0; k < 20; k++ )
	{
		if ( mylist[k] > max )
			max = mylist[k];
	}
	printf("Max:  %d\n", max);

	for ( k = 0; k < 20; k++ )
	{
		printf("%d ", mylist[k]);
	}
	printf("\n");

	return 0;
}
