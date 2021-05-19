#include <stdio.h>

int main()
{
	int x, y;
	int *p;

	x = 5;
	y = 7;
	p = &x;

	printf(" %2d %2d %2d\n", x, y, *p );

	x = 11;
	printf(" %2d %2d %2d\n", x, y, *p );

	*p = 19;
	printf(" %2d %2d %2d\n", x, y, *p );


	p = &y;
	printf(" %2d %2d %2d\n", x, y, *p );


	printf("ADDRESS x: %p\n", &x);
	printf("ADDRESS y: %p\n", &y);
	printf("ADDRESS p: %p\n", p);




	return 0;
}
