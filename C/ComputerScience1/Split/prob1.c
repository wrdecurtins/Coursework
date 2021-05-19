#include "toy.h"

int main()
{
	int i, x;
	char m;

	for ( i = 0; i < 5; ++i )
	{
		x = dig();
		m = let();
		printf("%c - %d\n", m, x );
	}
	return 0;
}
