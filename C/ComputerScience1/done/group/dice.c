#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int NumRolls, Roll, k, diesize = 6;
	srand ( time(NULL) );

//	printf("What die Size? : ");
//	scanf("%d", &diesize);
	printf("How many Rolls?: ");
	scanf("%d", &NumRolls);

	int c[6] = {0};

	for ( k = 0; k < NumRolls; k++ )
	{
		Roll = rand() % diesize + 1;
		printf("%d  ", Roll);
		c[Roll - 1]++;
	}

	printf("\n");

	for ( k = 0; k < diesize; k++ )
		printf("c%d: %d\n", k + 1, c[k]);

	return 0;
}
