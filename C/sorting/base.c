#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N    5
#define Max 50

int isInList( int arr[], int many, int target );

int main()
{
	int A[ N ];
	int i, j, temp;
	for (i = 0; i < N; ++i)
		A[i] = rand() % Max + 1;

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");

	// great stuff

	scanf("%d", &temp);

	if ( isInList( A, N, temp ) )
		printf("YES %d is in list\n", temp);
	else
		printf("NO %d is not in list\n", temp);


	printf("\n---- suspense ----\n\n");

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");

	return 0;
}

int isInList( int arr[], int many, int target )
{
	int k;
	for ( k = 0; k < many; k++ )
	{
		if ( arr[k] == target )
			return 1;
	}
	return 0;
}
