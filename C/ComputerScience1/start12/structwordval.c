
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wvpair
{
	char word[100];
	int num;
};


void printArrays( struct wvpair parr[100], int numOfLines );
void sortpair( struct wvpair parr[100], int numOfLines, int key );

int main( int argc, char *argv[] )
{
	// declare variables
	struct wvpair mylist[100];
	int numOfLines = 0,  tempnum;
	char tempstr[30];
	FILE *fp;

	fp = fopen( argv[1], "r" );

	if ( argc < 2 )
	{
		printf("Please supply a file name\n");
		exit(1);
	}

	if ( fp == NULL )
	{
		printf("File name invalid\n");
		exit(1);
	}

	// read data
	fscanf( fp, "%s %d", tempstr, &mylist[numOfLines].num );
	while( feof( fp ) != 1 )
	{
		mylist[numOfLines].num = tempnum;
		strcpy( mylist[numOfLines].word, tempstr );

		fscanf( fp, "%s %d", tempstr, tempnum );

		numOfLines++;
	}

//	printf("%s %d\n", items[numOfLines], numbers[numOfLines]);


	// print out how many lines were read
	printf("%d lines were read.\n", numOfLines);

	// print out original data, number each line
	printArrays( mylist, numOfLines );

	// print out sorted by number , number each line
	sortpair( mylist, numOfLines, 1 );
	printArrays( mylist, numOfLines );

	// print out sorted by word , number each line
	sortpair( mylist, numOfLines, 2 );
	printArrays( mylist, numOfLines );

	return 0;
}

void printArrays( struct wvpair parr[100], int numOfLines )
{
	int k;

	for ( k = 0; k < numOfLines; k++ )
	{
		printf("%d: %s %d\n", k+1, parr[k].word, parr[k].num);
	}
	printf("\n");
}

void sortpair( struct wvpair parr[100], int numOfLines, int key )
{
	int k, h, temp;
	char tstr[30];


	if ( key == 1 )
	{
		for ( k = 0; k < numOfLines; k++ )
		{
			for ( h = 0; h < numOfLines-1; h++ )
			{
				if( parr[h].num > parr[h+1].num )
				{
					temp = parr[h].num;
					parr[h].num = parr[h+1].num;
					parr[h+1].num = temp;
					strcpy( tstr, parr[h].word );
					strcpy( parr[h].word, parr[h+1].word );
					strcpy( parr[h+1].word, tstr );
				}
			}
		}
	}

	if ( key == 2 )
	{
		for ( k = 0; k < numOfLines; k++ )
		{
			for ( h = 0; h < numOfLines-1; h++ )
			{
				if( strcmp( parr[h].word, parr[h+1].word ) > 0 )
				{
					temp = parr[h].num;
					parr[h].num = parr[h+1].num;
					parr[h+1].num = temp;
					strcpy( tstr, parr[h].word );
					strcpy( parr[h].word, parr[h+1].word );
					strcpy( parr[h+1].word, tstr );
				}
			}
		}
	}
}
