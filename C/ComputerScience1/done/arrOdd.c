#include <stdio.h>
#include <stdlib.h>

void printArray( int arr[], int N )
{
	int k, x;

	for ( k = 0; k < N; ++k )
		printf("%2d ", arr[k]);
	printf("\n");
}

void fillArray( int arr[], int N )
{
	int k, x;

	for ( k = 0; k < N; ++k )
	{
		x = rand() % 30;
		arr[k] = x;
	}
}

int countOdd( int arr[], int N )
{
	int oc = 0;
	int k;
	for ( k = 0; k < N; ++k )
	{
		if ( arr[k] % 2 == 1 )
			oc++;
	}
	return oc;
}


int main()
{
	int numlist[25];
	int k, x;
	int res;

	srand( 7 );

	fillArray( numlist, 25 );
	printArray( numlist, 25 );

	res = countOdd( numlist, 25 );

	printf("%d odd values\n", res);

	return 0;
}
