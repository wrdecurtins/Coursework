
// a KEY will contain 6 characters 
//      ( random combination of letters & digits )


#include "toy.h"

int main()
{
	int k, p;
	char c;
	int d;

	for ( k = 0; k < 6; ++k )
	{
		p = rand() % 2;
		if ( p == 0 )
		{
			c = let();
			printf("%c", c);
		}
		else
		{
			d = dig();
			printf("%d", d);
		}
	}
	printf("\n");


	return 0;
}
