#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printColors( char c[][10], int many )
{
	int i;

	for (i = 0; i < many; ++i)
		printf("-- %s\n", c[i]);
}

char spaceBetween( char s[] )
{
	int i, L;
	L = strlen( s );
	for ( i = 0; i < L; ++i )
		printf("%c ", s[i]);
	printf("\n");
}

int main()
{
	char colors[3][10] = { "red", "green", "blue" };
	char shades[5][10];
	int i;

	strcpy( shades[0], "red" );
	strcpy( shades[1], "orange" );
	strcpy( shades[2], "yellow" );
	strcpy( shades[3], "green" );
	strcpy( shades[4], "blue" );

	printf("- - -\n");
	for (i = 0; i < 3; ++i)
		printf("%s  %s\n", colors[i], shades[i]);

	printf("- - -\n");
	printColors( colors, 3 );

	printf("- - -\n");
	printColors( shades, 5 );

	printf("- - -\n");
	for ( i = 0; i < 3; ++i )
		spaceBetween( colors[i] );
	
	return 0;
}
