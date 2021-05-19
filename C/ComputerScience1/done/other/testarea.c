#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand( time( NULL ) );

	int dierolls[4] = {0}, r, finalrolls[6] = {0};

    for ( r = 0; r < 4; r++ )
		dierolls[r] = rand() % 6 + 1;

	for ( r = 0; r < 4; r++ )
		printf("%d: %d\n", r + 1, dierolls[r]);

			 if ( dierolls[0] <= dierolls[1] && dierolls[0] <= dierolls[2] && dierolls[0] <= dierolls[3] )
                dierolls[0] = 0;
            else if ( dierolls[1] <= dierolls[0] && dierolls[1] <= dierolls[2] && dierolls[1] <= dierolls[3] )
                dierolls[1] = 0;
            else if ( dierolls[2] <= dierolls[0] && dierolls[2] <= dierolls[1] && dierolls[2] <= dierolls[3] )
                dierolls[2] = 0;
            else if ( dierolls[3] <= dierolls[1] && dierolls[3] <= dierolls[2] && dierolls[3] <= dierolls[0] )
                dierolls[3] = 0;

	printf("\n");

	for ( r = 0; r < 4; r++ )
		printf("%d: %d\n", r + 1, dierolls[r]);

	for ( r = 0; r < 4; r++ )
		finalrolls[0] += dierolls[r];

	printf("\nFinal Roll value: %d\n", finalrolls[0]);

	return 0;
}
