#include <stdio.h>


int max( int A[], int N )
{

	int high = A[0];
	int k;

	for ( k = 1; k < N; k++ )
	{
		if ( A[k] > high )
			high = A[k];
	}

	return high;
}


int main()
{
	int numList[10] = {8, 3, 6, 13, 2, 6, 3, 5, 1, 4};
	int big;

	big = max( numList, 10 );
	printf("Largest is %d\n", big);

	return 0;
}
