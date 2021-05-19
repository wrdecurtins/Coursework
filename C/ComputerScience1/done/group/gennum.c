#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int RandNum, k, sum = 0, max = -1, min = 2000;

	srand ( time(NULL) );

	for ( k = 1; k <= 20; k++ )
	{
		RandNum = rand() % 1000 + 1;
		printf("%d: %d\n", k, RandNum);

		sum = sum + RandNum;
		if ( RandNum > max )
			max = RandNum;
		if ( RandNum < min )
			min = RandNum;
	}

	printf("The Max is %d and the Min is %d and the sum is %d\n", max, min, sum);
	return 0;
}
