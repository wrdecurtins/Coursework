#include "arrfun.h"
#include "toy.h"

int main()
{
	int k;
	list L;

	L = makeList();

	for ( k = 0; k < 10; k++ )
	{
		insertBack( L, dig() );
		printList(L);
	}



	return 0;
}
