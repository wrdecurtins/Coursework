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

	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < N - 1 - i; j++ )
		{
			check++;
			if ( A[j] > A[j+1] )
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");
	return 0;
}
