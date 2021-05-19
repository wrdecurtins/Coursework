#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int deck[14][2];
	int k, x;
	int ptotal, htotal;

	srand( time( NULL ) );

	for ( k = 1; k <= 13; k++ )
	{
		deck[k][0] = 4;
		deck[k][1] = k;
		if ( k > 10 )
			deck[k][1] = 10;
	}


	for ( k = 1; k <= 13; k++ )
	{
		printf("%2d     %2d         %d\n", k, deck[k][1], deck[k][0] );
	}

	ptotal = 0;

	while (ptotal < 17)
	{
		do
		{
			x = rand() % 13 + 1;
		} while ( deck[x][0] == 0 );

		deck[x][0]--;
		ptotal = ptotal + deck[x][1];
		printf("Player: card %d total now %d\n", x, ptotal);
	}
	printf("Player end turn: %d\n", ptotal);

	return 0;
}

