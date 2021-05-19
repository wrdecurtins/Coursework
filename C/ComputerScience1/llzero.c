// Linked List program 1
//  - allocate a node
//  - attach to list
//  - print list
//  - find sum of items in list

#include <stdio.h>
#include <stdlib.h>

struct boxtype
{
	int val;
	struct boxtype *link;
};


int main()
{
	struct boxtype *start, *b;

	start = malloc( sizeof( struct boxtype ) );
	start->val = 12;
	start->link = NULL;

	b = malloc( sizeof( struct boxtype ) );
	b->val = 5;
	b->link = start;
	start = b;


	b = malloc ( sizeof( struct boxtype ) );
	b->val = 20;
	b->link = start;
	start = b;

	// stuff happens

	int sum = 0;
	b = start;
	while ( b != NULL )
	{
		printf("%02d ", b->val);
		sum = sum + b->val;
		b = b->link;
	}
	printf("\n");
	printf("Total is %d\n", sum);



	return 0;
}


