#include <stdio.h>
#include <stdlib.h>

void mostVisitors( int grid[20][20] );
void notVisited( int grid[20][20] );
void printGrid( int grid[20][20] );

int main( int argc, char *argv[] )
{
	int grid[20][20] = {0}, numOfLines = 0, x, y, people, k;
	FILE *fp;

	fp = fopen( argv[1], "r" );

	if ( fp == NULL )
	{
		printf("File %s does not exist\n", argv[1]);
		exit(1);
	}


	fscanf(fp, "%d %d %d", &x, &y, &people);
	while ( feof(fp) != 1 )
	{
		grid[x][y] += people;
		fscanf(fp, "%d %d %d", &x, &y, &people);
		numOfLines++;
	}

	printf("\n");
	mostVisitors( grid );
	printf("\n");
	notVisited( grid );
	printf("\n");
	printGrid( grid );

	return 0;
}

void printGrid( int grid[20][20] )
{
	int x, y;

	for ( x = 0; x < 20; x++ )
	{
		for ( y = 0; y < 20; y++ )
		{
			if ( grid[x][y] > 10 )
				printf("H");
			else if ( grid[x][y] == 0 )
				printf(".");
			else
				printf("L");
		}
		printf("\n");
	}
}

void notVisited( int grid[20][20] )
{
	int x, y, num = 0;

	for ( x = 0; x < 20; x++ )
	{
		for ( y = 0; y < 20; y++ )
		{
			if ( grid[x][y] == 0 )
				num++;
		}
	}
	printf("%d location(s) had no visitors\n", num);
}

void mostVisitors( int grid[20][20] )
{
	int x, y, mostv = 0;

	for ( x = 0; x < 20; x++ )
	{
		for ( y = 0; y < 20; y++ )
		{
			if ( grid[x][y] > mostv )
				mostv = grid[x][y];
		}
	}

	printf("The highest amount of visitors in a location: %d\n", mostv);
	printf("Location(s) with the most visitors:\n");

	for ( x = 0; x < 20; x++ )
	{
		for ( y = 0; y < 20; y++ )
		{
			if ( grid[x][y] == mostv )
				printf("X:%2d Y:%2d\n", x, y);
		}
	}
}
