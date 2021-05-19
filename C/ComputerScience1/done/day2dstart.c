// Solve each step & test before moving to next
/*
Declare an array of 25 integers

Seed 7
Set each element to random value 0 to 29, (0<x<30)

Print the array just to verify
 - do we all match?

Write a function to print the array
  Parameter:  array, size of array
   Return:    none

Create a new function
  Parameter:  array, size of array
   Return:   integer

  Purpose:  count how many odd values are in array

*/

#include <stdio.h>
#include <stdlib.h>

void printArray( int A[], int N)
{
	int k;
	for ( k = 0; k < N; k++ )
		printf("%d ", A[k]);
	printf("\n");
}

int countOdd( int A[], int N )
{
	int k, ans = 0;

	for ( k = 0; k < N; k++ )
		if ( A[k] % 2 == 1 )
			ans++;

	return ans;
}

int main()
{
	int nums[25], k;

	srand( 7 );

	for ( k = 0; k < 25; k++ )
	{
		nums[k] = rand() % 30;
	}

	printArray( nums, 25 );

	printf("Number of odds: %d\n", countOdd( nums, 25 ));

	return 0;
}







