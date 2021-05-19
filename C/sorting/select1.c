#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   10
#define Max 50



int main()
{
	int A[ N ];
	int i, j, temp, check = 0;
	srand ( 43 );

	for (i = 0; i < N; ++i)
		A[i] = rand() % Max + 1;

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");

	// great stuff
	int maxloc = 0;
	for ( i = 0; i < N; i++ )
	{
		maxloc = 0;
		for ( j = 0; j < N - i; j++ )
		{
			if ( A[j] > A[maxloc] )
				maxloc = j;
		}

		temp = A[maxloc];
		A[maxloc] = A[N-1-i];
		A[N-1-i] = temp;

	}

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");
	return 0;
}
