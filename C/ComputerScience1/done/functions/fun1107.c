/*
Fill an array A of size N with random values below H
     ex: put 10 values into array under 100

Print the contents of an array that has N elements

Search:  check if a value X can be found in an
         array A that has N elements
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void fillArray( int arr[], int sz );
//void printArray( int arr[], int sz );
//int isInList( int arr[], int sz, int val );

int main()
{
	int A[10];
	int numlist[15];
	int x;
//	srand ( time( NULL ) );

	fillArray( A, 10 );
	printArray( A, 10 );
	fillArray( numlist, 5 );
	printArray( numlist, 5 );

	printf("Val to search: ");
	scanf("%d", &x);
	if ( isInList( A, 10, x ) == 1 )
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

void fillArray( int arr[], int sz )
{
	int k;

	for ( k = 0; k < sz; k++ )
	{
		arr[k] = rand() % 20 + 1;
	}
}

void printArray( int arr[], int sz )
{
	int k;
	for ( k = 0; k < sz; k++ )
		printf("%2d ", arr[k]);
	printf("\n");
}

int isInList( int arr[], int sz, int val )
{
	int k;

	for ( k = 0; k < sz; k++ )
	{
		if ( arr[k] == val )
			return 1;
	}

	return 0;
}
