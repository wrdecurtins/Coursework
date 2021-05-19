#include "arrfun.h"

int main()
{
	list two;
	int i, x;

	two = makeList(); 

	for ( i = 0; i < 20; ++i )
	{
		x = rand() % 200 + 1;
		insertBack( two, x );
	}

	int tot = 99;
	int n = 11;

	int mv;
	int ml;
	while ( !isEmpty( two ) )
	{
		mv = maxVal( two );
		ml = maxLoc( two );
		if ( mv % 2 )
			tot = tot + mv + n;
		else
			tot = tot - mv + n;
		n++;
		removeThisOne( two, ml );
	}
	printf("%d\n", tot);
	return 0;
}
