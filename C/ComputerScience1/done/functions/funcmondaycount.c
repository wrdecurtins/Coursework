#include <stdio.h>
#include <string.h>

void countbetween( int start, int end )
{

	if ( start < end )
	{
		for ( start = start; start <= end; start++ )
			printf("%d ", start);
		printf("\n");
	}

	else if ( end < start )
	{
		for ( end = end; end <= start; end++ )
			printf("%d ", end);
		printf("\n");
	}
}


int main()
{
	int first, second;

	scanf("%d", &first);
	scanf("%d", &second);
	countbetween( first, second );

	return 0;
}
