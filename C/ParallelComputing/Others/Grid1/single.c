// Program described in class on 9/11/19
// Rules can be found in class video, short version here::
//   For G[x][y] ... add all neighbors & self to find sum
/*     In the next generation, value at [x][y] is
        sum % 10 == 0               0
        sum is under 50             add 3 to current
        sum between 50 & 150        subtract 3, but can't go below 0
        sum over 150                1
 	Any neighbors outside space are 0's
//

Sample to illustrate rules:
A--
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16

B--
 4  5  0  7
 8  3  4 11
 6  0  8  9
16 11 12 13

*/


// this code does not work, but shows you how it should be structured

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// establish your sizes using variables or #define
//   so that it is easy to change;
// remainder of code should look at these values

#define SEED 2
#define UPPERBOUND 20

int NR = 12;
int NC = 20;
int GEN = 10;

// fill grid G with random values
// use srand(seed); to set the sequence
// use % high to restrict the range
void fillGrid( int G[NR][NC], int seed, int high )
{
	srand(seed);
	int random;

	for ( int i = 0; i < NR; i++ )
	{
		for ( int j = 0; j < NC; j++ )
		{
			random = rand() % high + 1;
			G[i][j] = random;
		}
	}

}

// print out the grid
void printGrid( int G[NR][NC] )
{
	for ( int i = 0; i < NR; i++ )
	{
		for ( int j = 0; j < NC; j++ )
		{
			printf("%3d ", G[i][j]);
		}
		printf("\n");
	}
}

// given grid, and an particular (x,y) location
//   compute the value of that spot in next generation
int checker( int arr[NR][NC],int x, int y )
{
	int sum = 0;

	for ( int j = y - 1; j <= y + 1; j++ )
	{
		for ( int i = x - 1; i <= x + 1; i++ )
		{
			if ( i < 0 || i >= NR || j < 0 || j >= NC )
			{
				continue;
			}
			else
			{
				sum += arr[i][j];
			}
		}
	}

	usleep( sum % 11 * 1500);

	if ( sum % 10 == 0 )
		return 0;
	else if ( sum < 50 )
		return arr[x][y] + 3;
	else if ( sum >= 50 && sum <= 150 && arr[x][y] <= 3 )
		return 0;
	else if ( sum >= 50 && sum <= 150 && arr[x][y] > 3 )
		return arr[x][y] - 3;
	else
		return 1;
}

int main()
{
	int A[NR][NC];
	int B[NR][NC];

	fillGrid( A, SEED, UPPERBOUND );

	for ( int g = 1; g <= GEN; g++ )
	{
		if ( g % 2 == 1 )
		{
			printf("%d------------------------------\n", g);
			printf("A--\n");
			printGrid(A);
			for (int i = 0 ; i < NR; ++i )
			{
				for (int j = 0; j < NC; ++j )
				{
					B[i][j] = checker( A, i, j );
				}
			}

			printf("B--\n");
		//	fillGrid( B, 38, 20 );
			printGrid(B);
		}
		else if ( g % 2 == 0 )
		{
			printf("%d------------------------------\n", g);
			printf("B--\n");
			printGrid(B);
			for (int i = 0 ; i < NR; ++i )
			{
				for (int j = 0; j < NC; ++j )
				{
					A[i][j] = checker( B, i, j );
				}
			}

			printf("A--\n");
		//	fillGrid( B, 38, 20 );
			printGrid(A);
		}
	}
	return 0;
}
