
#include <stdio.h>

// only works for size 3
void printA( int a[] )
{
	int k;

	printf("[ ");
	for ( k = 0; k < 3; ++k )
		printf("%2d ", a[k]);
	printf(" ]\n");
}


void printA2( int a[][3] )
{
	int r,c;

	for ( r = 0; r < 3; ++r )
	{
		printf("[ ");
		for ( c = 0; c < 3; ++c )
			printf("%2d ", a[r][c]);
		printf(" ]\n");
	}
}

int main()
{
	int b[3] = {5,6,7};
	int c[]  = {10,11,12};
	int d[3]  = {0};
	int e[3]  = {5};
	int x[3][3] = {0};
	int y[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	printf("b is " );
	printA( b );
	printf("c is " );
	printA( c );
	printf("d is " );
	printA( d );
	printf("e is " );
	printA( e );
	printf("x is\n" );
	printA2( x );
	printf("y is\n" );
	printA2( y );
	
	return 0;
}
