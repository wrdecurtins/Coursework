#include <stdio.h>
#include <stdlib.h>

// roll a dice with given number of sides
// return the result
int rollv1( int sides )
{
	int d;
	d = rand() % sides + 1;
	return d;
}

// roll a dice with given number of sides
// result is passed back in parameter
void rollv2( int sides, int *dice )
{
	*dice = rand() % sides + 1;
}


// roll two dice with given number of sides
// result is passed back in parameters
void rollpair( int sides, int *d1, int *d2 )
{
	*d1 = rand() % sides + 1;
	*d2 = rand() % sides + 1;

}


// for a given value, send back the number
//   immediate before & after in sequence
/*void getNeighbors( int val, previous, next)
{

}

*/

int main()
{
	int r, s;
	int before, after;

	// leave srand out for now so we get the same numbers
	//srand( time(NULL) );

 //  roll a 5-sided dice
 //  using return value
	r = rollv1( 5 );
	s = rollv1( 5 );
	printf("Rolled %d and %d\n", r, s );

 // using reference parameter
	rollv2( 5,  &r );
	rollv2( 5,  &s );
	printf("Rolled version 2  %d and %d\n", r, s);

	rollpair( 5, &r, &s  );
	printf("RolledPair  %d and %d\n", r, s);

//	getNeighbors( 10, ??, ?? );
//	printf("%d before 10 and %d after 10\n", before, after);

	return 0;
}
