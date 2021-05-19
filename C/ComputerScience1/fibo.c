#include <stdio.h>


int f( int n )
{
	if ( n == 1 || n == 2 )
		return 1;
	else
		return (f( n - 1) + f( n - 2 ));
}


int main()
{
	int x;
	scanf("%d", &x);


	for ( x = 3; x <= 20; x++ )
		printf("%d = %d\n", x, f(x));
	return 0;
}
