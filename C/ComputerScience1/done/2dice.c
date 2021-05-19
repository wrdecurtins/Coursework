#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int r, k;

	srand( time (NULL) );



	for ( k = 1; k <= 5; ++k )
	{
		r = rand() % 7 + 1;
		printf("%d\n", r);
		if ( r == 1 )
			printf("Red\n");
		else if ( r == 2 )
			printf("Orange\n");
		else if ( r == 3 )
			printf("Yellow\n");
		else if ( r == 4 )
			printf("Green\n");
		else if ( r == 5 )
			printf("Blue\n");
		else if ( r == 6 )
			printf("Ingigo\n");
		else if ( r == 7 )
			printf("Violent\n");
	}
	return 0;
}
