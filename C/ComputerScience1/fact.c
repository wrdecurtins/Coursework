#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
	if ( n == 0 )
		return 1;
	else
		return n * f(n-1);
}


int main( int argc, char *argv )
{
	int x;

	if (argc == 1)
		scanf("%d", &x);
	else
		x = atoi(argv[1]);


	printf("%d! = %d\n", x, f(x));

	return 0;

}
