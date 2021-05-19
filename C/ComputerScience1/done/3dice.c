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

		switch (r)
		{
		case 1:
			printf("Red\n");
			break;
		case 2:
			printf("Orange\n");
			break;
		case 3:
			printf("Yellow\n");
			break;
		case 4:
			printf("Green\n");
			break;
		case 5:
			printf("Blue\n");
			break;
		case 6:
			printf("Ingigo\n");
			break;
		case 7:
			printf("Violent\n");
			break;
		}
	}
	return 0;
}
