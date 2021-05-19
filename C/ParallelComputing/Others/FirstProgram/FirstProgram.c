#include <stdio.h>

int function( int N );

int main()
{
	int k, sum;

	for ( k = 1; k <= 13; k++ )
	{
		sum = sum + k;
	}

	printf("Sum = %d\n\n", sum);

	int countBackFrom = 10, L;

	L = countBackFrom;

	printf("Counting back from %d\n", countBackFrom);

	while ( L >= 0 )
	{
		printf("%d\n", L);
		L = L - 1;
	}

	printf("Function(%d) = %d\n", sum, function(sum));
	printf("Function(%d) = %d\n", 344, function(344));


	return 0;
}

int function( int N )
{
	int T = 0, k = 0;

	for ( k = 0; k <= N; k += 2 )
	{
		T = T + k;
	}

	T = T - N;

	return T;
}
