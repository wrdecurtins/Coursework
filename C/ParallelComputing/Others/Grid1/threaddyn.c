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
#include <pthread.h>
#include <unistd.h>

// establish your sizes using variables or #define
//   so that it is easy to change;
// remainder of code should look at these values

#define NR 12
#define NC 20
#define GEN 10
#define SEED 2
#define NUMT 4

int G = 1;
//int NUMT = 4;
int A[NR][NC];
int B[NR][NC];
int WorkByTid[NUMT] = {0};

pthread_mutex_t lock;
int Row = 0;
int Col = 0;

pthread_barrier_t barr;

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
				sum += 0;
			}
			else
			{
				sum += arr[i][j];
			}
		}
	}

//	printf("\nSum before: %d\n", sum);

	int s = sum;

	usleep( s % 11 * 1500 );

//	printf("\nSum after: %d\n", sum);

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

int getRow()
{
	int r;
//	pthread_mutex_lock( &lock );
	r = Row;
//	pthread_mutex_unlock( &lock );
	return r;
}


void incrementRow( int r )
{
//	pthread_mutex_lock( &lock );
	if ( r == Row )
		Row++;
//	pthread_mutex_unlock( &lock );
}

int GetAndIncrementCol()
{
	int c;
	pthread_mutex_lock( &lock );
	c = Col;
	Col++;
	pthread_mutex_unlock( &lock );
	return c;
}

void resetCol()
{
	pthread_mutex_lock( &lock );
	if ( Col == NC )
		Col = 0;
	pthread_mutex_unlock( &lock);
}


void *threadtask( void *param )
{
	long myid;
	myid = (long) param;
	int r, c;

	while ( Row < NR )
	{
		r = getRow();

		Col = 0;
		pthread_barrier_wait(&barr);

//		if ( myid == 5 )
//			printf("Col == %d", Col);

		while ( Col < NC )
		{
			c = GetAndIncrementCol();

			if ( G % 2 == 1 )
				B[r][c] = checker( A, r, c );
			else if ( G % 2 == 0 )
				A[r][c] = checker( B, r, c );

			WorkByTid[myid]++;
		}
		pthread_barrier_wait( &barr );
		pthread_mutex_lock( &lock );
		incrementRow(r);
		pthread_mutex_unlock( &lock );
//		resetCol();
//		Col = 0;

//		if ( myid == 5 )
//			printf("Col == %d", Col);

//		pthread_barrier_wait( &barr );

	}
//	pthread_barrier_wait( &barr );

	pthread_exit(NULL);
}

int main()
{
	void *status;

	pthread_t tid[NUMT];

	fillGrid( A, SEED, 20 );

	pthread_barrier_init( &barr, NULL, NUMT );
	pthread_mutex_init( &lock, NULL );

	for ( G = 1; G <= GEN; G++ )
	{
		Row = 0;
		Col = 0;
		if ( G % 2 == 1 )
		{
			printf("%d------------------------------\n", G);
			printf("A--\n");
			printGrid(A);
			for (long myid = 0 ; myid < NUMT; myid++ )
			{
				pthread_create( &tid[myid], NULL, threadtask, (void *) myid );
			}

//			pthread_barrier_wait( &barr );

			for ( long t = NUMT - 1; t >= 0; t-- )
			{
				pthread_join( tid[t], &status);
			}

			printf("B--\n");
		//	fillGrid( B, 38, 20 );
			printGrid(B);
		}
		else if ( G % 2 == 0 )
		{
			printf("%d------------------------------\n", G);
			printf("B--\n");
			printGrid(B);

			for (long myid = 0 ; myid < NUMT; myid++ )
			{
				pthread_create( &tid[myid], NULL, threadtask, (void *) myid );
			}

//			pthread_barrier_wait( &barr );


			for ( long t = NUMT - 1; t >= 0; t-- )
			{
				pthread_join( tid[t], &status);
			}


			printf("A--\n");



		//	fillGrid( B, 38, 20 );
			printGrid(A);
		}
	}

	int total = 0;
	printf("\n\n");
	for ( int k = 0; k < NUMT; k++ )
	{
		printf("Thread %2d : %3d checks\n", k, WorkByTid[k]);
		total += WorkByTid[k];
	}
	printf("Total Work : %5d\n", total);

	return 0;
}
