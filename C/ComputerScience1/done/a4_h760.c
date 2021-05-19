#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString( char A[], char B[] );

int main()
{
	char strA[]="Dakota";
	char strB[100];

	reverseString( strA, strB );

	return 0;
}

void reverseString( char A[], char B[] )
{
	int k, h = 0;

	for ( k = strlen(A) - 1; k >= 0; k-- )
	{
		B[h] = A[k];
		h++;
	}

	printf("String A: %s\n", A);
	printf("String B: %s\n", B);

}
