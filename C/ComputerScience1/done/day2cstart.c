

// Solve each step & test before moving to next
/*
// Using an array
// Loop 1:  set 1000 random integers in range 0 to 50000
// Loop 2:  count how many multiples of 7 are in list & report
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nums[1000], k, sev = 0;

	for ( k = 0; k < 1000; k++ )
		nums[k] = rand() % 50001;

	for ( k = 0; k < 1000; k++ )
		printf("%d\n", nums[k]);

	for ( k = 0; k < 1000; k++ )
		if ( nums[k] % 7 == 0 )
			sev++;

	printf("\nNumber of multiples of seven: %d\n\n", sev);

	return 0;
}

