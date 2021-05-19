#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int vDupli( int arr[MAX][MAX], int R, int C, int num );
int hDupli( int arr[MAX][MAX], int R, int C, int num );

int main( int argc, char *argv[] )
{
	FILE *fp;
	int arr[MAX][MAX], R, C, k, h;
	int checkh, checkv;
	char dupli[MAX][MAX];

	fp = fopen( argv[1], "r" );
	if ( fp == NULL )
	{
		printf("File %s does not exist\n", argv[1] );
		exit(1);
	}

	fscanf(fp, "%d", &R);
	fscanf(fp, "%d", &C);

	for ( k = 0; k < R; k++ )
	{
		for ( h = 0; h < C; h++ )
		{
			fscanf(fp, "%d", &arr[k][h]);
//			printf("%d ", arr[k][h]);
		}
//		printf("\n");
	}
//	printf("\n");

	for ( k = 0; k < R; k++ )
	{
		for ( h = 0; h < C; h++ )
		{
			checkh = hDupli( arr, k, C, arr[k][h] );
			checkv = vDupli( arr, R, h, arr[k][h] );

			if (( checkh == 1 ) && ( checkv == 1 ))
				dupli[k][h] = '+';
			else if ( checkh == 1 )
				dupli[k][h] = '-';
			else if ( checkv == 1 )
				dupli[k][h] = '|';
			else
				dupli[k][h] = ' ';

			printf("%c ", dupli[k][h]);
		}
		printf("\n");
	}
	printf("\n");


	for ( k = 0; k < R; k++ )
		for ( h = 0; h < C; h++ )
			printf("%c", dupli[k][h]);

	printf("\n");

	return 0;
}

int hDupli( int arr[MAX][MAX], int R, int C, int num )
{
	int h, dupli = 0;

	for ( h = 0; h < C; h++ )
	{
		if ( arr[R][h] == num )
			dupli++;
	}

	if ( dupli > 1 )
		return 1;
	else
		return 0;
}

int vDupli( int arr[MAX][MAX], int R, int C, int num )
{
	int k, dupli = 0;

	for ( k = 0; k < R; k++ )
	{
		if ( arr[k][C] == num )
			dupli++;
	}

	if ( dupli > 1 )
		return 1;
	else
		return 0;
}
