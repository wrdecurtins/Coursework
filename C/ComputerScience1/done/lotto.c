#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int lotto = 0, check = 0, drawn = 20, k, r;

	srand ( time( NULL ) );

	for ( k = 0; k < drawn; k++ )
	{
		for ( r = 1; r <= 3; r++ )
		{
			while ( lotto == check )
			{
				lotto = rand() % 25 + 1;
			}

			if ( r == 1 )
				printf("%2d:   ", k + 1);
			if ( r != 3 )
				printf("%2d, ", lotto);
			else
				printf("%2d\n", lotto);

			check = lotto;
		}
	}

	return 0;
}
