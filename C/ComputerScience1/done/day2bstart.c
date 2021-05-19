

// Solve each step & test before moving to next
/*
generate & print N random values  ( under 100 )
use   srand(11); so we get the same numbers
find the sum of these values


for each of the N values, print the
    number and then the word  "even" or "odd" on a line

*/


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N, k, x, sum = 0;

	srand(11);

	printf("How many values: ");
	scanf("%d", &N);

	for ( k = 0; k < N; k++ )
	{
		x = rand() % 100;
		printf("%2d ", x);

		if ( x % 2 == 0 )
			printf("even\n");
		else
			printf("odd\n");

		sum += x;
	}
	printf("\nThe Sum = %d ", sum);

		if ( sum % 2 == 0 )
			printf("even\n\n");
		else
			printf("odd\n\n");

	return 0;
}




