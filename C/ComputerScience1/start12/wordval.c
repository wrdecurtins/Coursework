// read a list
//   each element is a string and an integer
// print list
// sort by string
// sort by number
/*
Additional notes::

File:
 each line will consist of a string/word and an integer value
 Input file contains a list of words, 1 per line.
  - there will be less than 100 words
  - all words will be less than 30 characters

Note::
 * Do NOT pass file pointers to functions, only the
    filenames and/or arrays

Function: sort the data
  Param: arrays
         # of items
         pick   to sort by word or number
                   by parameter, not interactive

Function:  display on screen
  Param: arrays
         # of items
   ** also print a "line number" 1,2,3  by each pair

Function: read data from file
  Param: filename
         arraysd
  Return: number of items
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArrays( int numbers[], char items[][30], int numOfLines );
void sortpair( char items[100][30], int numbers[100], int numOfLines, int key );

int main( int argc, char *argv[] )
{
	// declare variables
	int numOfLines = 0, numbers[100], tempnum;
	char items[100][30], tempstr[30];
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
	fscanf( fp, "%s %d", tempstr, &tempnum );
	while( feof( fp ) != 1 )
	{
		numbers[numOfLines] = tempnum;
		strcpy( items[numOfLines], tempstr );

		fscanf( fp, "%s %d", tempstr, &tempnum );

		numOfLines++;
	}

//	printf("%s %d\n", items[numOfLines], numbers[numOfLines]);


	// print out how many lines were read
	printf("%d lines were read.\n", numOfLines);

	// print out original data, number each line
	printArrays( numbers, items, numOfLines );

	// print out sorted by number , number each line
	sortpair( items, numbers, numOfLines, 1 );
	printArrays( numbers, items, numOfLines );

	// print out sorted by word , number each line
	sortpair( items, numbers, numOfLines, 2 );
	printArrays( numbers, items, numOfLines );

	return 0;
}

void printArrays( int numbers[], char items[][30], int numOfLines )
{
	int k;

	for ( k = 0; k < numOfLines; k++ )
	{
		printf("%d: %s %d\n", k+1, items[k], numbers[k]);
	}
	printf("\n");
}

void sortpair( char items[100][30], int numbers[100], int numOfLines, int key )
{
	int k, h, temp;
	char tstr[30];


	if ( key == 1 )
	{
		for ( k = 0; k < numOfLines; k++ )
		{
			for ( h = 0; h < numOfLines-1; h++ )
			{
				if( numbers[h] > numbers[h+1] )
				{
					temp = numbers[h];
					numbers[h] = numbers[h+1];
					numbers[h+1] = temp;
					strcpy( tstr, items[h] );
					strcpy( items[h], items[h+1] );
					strcpy( items[h+1], tstr );
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
				if( strcmp( items[h], items[h+1] ) > 0 )
				{
					temp = numbers[h];
					numbers[h] = numbers[h+1];
					numbers[h+1] = temp;
					strcpy( tstr, items[h] );
					strcpy( items[h], items[h+1] );
					strcpy( items[h+1], tstr );
				}
			}
		}
	}
}
