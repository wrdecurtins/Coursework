#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[3][5];
	int r, c;

	// fill array with random values 1 to 20
	for ( r = 0; r < 3; ++ r )
	{
		for ( c = 0; c < 5; ++c )
		{
			A[r][c] = rand() % 20 + 1;
		}
	}


	// print out as a grid/table/matrix
	for ( r = 0; r < 3; ++ r )
	{
		for ( c = 0; c < 5; ++c )
		{
			printf("%2d ", A[r][c] );
		}
		printf("\n");
	}

	return 0;
}
