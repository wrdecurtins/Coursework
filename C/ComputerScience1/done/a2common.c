#include <stdio.h>
#include <string.h>

int SimilarChars( char A[], char B[] );
int CheckLetter( char A, char B[], int lenOfString );

int main()
{
	int numOfSimilar = 0;
	char str1[50], str2[50];

	printf("What is the first word?: ");
	scanf("%s", str1);

	printf("What is the second word?: ");
	scanf("%s", str2);

	numOfSimilar = SimilarChars( str1, str2 );

	printf("\nThere are %d characters similar in these two words\n", numOfSimilar);

	return 0;
}

int SimilarChars( char A[], char B[] )
{
	int k, h, num = 0;
	char used[52] = {0};

	for ( k = 0; k < strlen(A); k++ )
	{
		if ( CheckLetter( A[k], A, k ) == 0 )
			if ( CheckLetter( A[k], B, strlen(B) ) == 1 )
				num++;
	}
	return num;
}

int CheckLetter( char A, char B[], int lenOfString )
{
	int k;

	for ( k = 0; k < lenOfString; k++ )
	{
		if ( A == B[k] )
			return 1;
	}
	return 0;
}
