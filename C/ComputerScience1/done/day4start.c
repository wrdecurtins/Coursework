#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLowercase( char c );
int isUppercase( char c );
int isLetter( char c );
int isOnlyLetters( char str[] );
void alternateCase( char str[] );

int main()
{
	int r, q;
	char str[20];

	r = isUppercase( 'A' );
	if ( r == 1 )
		printf("Yes A is uppercase\n");
	else
		printf("No A is not uppercase\n");

	r = isUppercase( 'b' );
	if ( r == 1 )
		printf("Yes b is uppercase\n");
	else
		printf("No b is not uppercase\n");

	r = isUppercase( '$' );
	if ( r == 1 )
		printf("Yes $ is uppercase\n");
	else
		printf("No $ is not uppercase\n");


	printf("String: ");
	scanf("%s", str);

	printf("String is %s\n", str);
	printf("Len: %d\n", q);

	r = isOnlyLetters( str );
	if ( r == 1 )
		printf("Only letters\n");
	else
		printf("Not just letters\n");


	printf("Alternating: ");
	alternateCase( str );
	return 0;
}


int isLowercase( char c )
{
	if ( c >= 'a' && c <= 'z' )
		return 1;
	else
		return 0;
}

int isUppercase( char c )
{
	if ( c >= 'A' && c <= 'Z' )
		return 1;
	else
		return 0;
}

int isLetter( char c )
{
	if (( isLowercase(c) == 1 ) || ( isUppercase(c) == 1 ))
		return 1;
	else
		return 0;
}

int isOnlyLetters( char str[] )
{
	int k;

	for ( k = 0; k < strlen(str); k++ )
		if ( isLetter( str(k) ) == 0 )
			return 0;
	return 1;
}

void alternateCase( char str[] )
{
}
