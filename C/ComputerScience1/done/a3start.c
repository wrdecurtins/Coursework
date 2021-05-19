#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int manyUpper( char s[] );
int manyDigits( char s[] );


int main( int argc, char *argv[] )
{
	char line[100], longestLine[100], shortestLine[100];
	int lineNum = 1, numUp, maxUp = -1, maxUpLineNum, lineLen;
	int numDigits, maxDigits = -1, maxDigitsLineNum;
	int maxStrLen = -1, maxStrLenLineNum, minStrLen = 101, minStrLenLineNum;

	FILE *infp;

	infp = fopen( argv[1], "r" );

	if ( infp == NULL )
	{
		printf("File Does Not Exist\n");
		exit(1);
	}

	while ( fgets( line, 100, infp ) != NULL )
	{
		printf("%d : %s", lineNum, line);

		numUp = manyUpper( line );
		if ( numUp > maxUp )
		{
			maxUp = numUp;
			maxUpLineNum = lineNum;
		}

		numDigits = manyDigits( line );
		if ( numDigits > maxDigits )
		{
			maxDigits = numDigits;
			maxDigitsLineNum = lineNum;
		}

		lineLen = strlen( line );

		if ( lineLen > maxStrLen )
		{
			maxStrLenLineNum = lineNum;
			maxStrLen = strlen( line );
			strcpy( longestLine, line );
		}

		if ( lineLen < minStrLen )
		{
			minStrLenLineNum = lineNum;
			minStrLen = strlen( line );
			strcpy( shortestLine, line );
		}

		lineNum++;
	}


	printf("\n\nLongest Line Number : %2d line : %s", maxStrLenLineNum, longestLine);
	printf("Shortest Line Number: %2d line : %s\n", minStrLenLineNum, shortestLine);

	printf("Max number of Upper : %2d line#: %2d\n", maxUp, maxUpLineNum);
	printf("Max number of Digits: %2d line#: %2d\n\n", maxDigits, maxDigitsLineNum);

	return 0;
}


int manyUpper( char s[] )
{
	int k, upcount = 0;

	for ( k = 0; k < strlen(s); k++ )
		if ( s[k] >= 'A' && s[k] <= 'Z' )
			upcount++;

	return upcount;
}

int manyDigits( char s[] )
{
	int k, digitcount = 0;

	for ( k = 0; k < strlen(s); k++ )
		if ( s[k] >= '0' && s[k] <= '9' )
			digitcount++;

	return digitcount;
}
