#include "arrfun.h"

int main()
{
	list one, two;
	int i, x;

	one = makeList(); 
	two = makeList(); 

	for ( i = 0; i < 7; ++i )
	{
		x = rand() % 80 + 1;
		insertFront( one, x );
		insertBack( two, x );
	}

	int tot = 99;

	while ( two->len > 0 )
	{
		x = two->dat[0];
		tot += x%29;
		removeFront( two );
	}

	while ( one->len > 0 )
	{
		x = one->dat[0];
		tot += x%29;
		removeBack( one );
	}
	printf("%d\n", tot);

	return 0;
}
