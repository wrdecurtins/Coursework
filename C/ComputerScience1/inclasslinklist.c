
// Linked List Assignment #1   Spring 2018
/*
Done:
ptr makeNode( int )
void printList( ptr )
ptr insertFront( ptr, int )
int listLength( ptr )


More Linked List for you to add
  -  purpose & behavior explained in class

int isEmpty( ptr )            1: if list is empty
int isInList( ptr, int )      1: if val is in list
ptr getLoc( ptr, int )        ptr to location of val
int maxVal( ptr )             largest value
ptr maxLoc( ptr )             location of largest value

ptr insertBack( ptr, int )    add value to end of list

ptr insertAfter( ptr, ptr, int )
                              add value to list after loc

ptr removeFront( ptr )        delete first item
ptr removeBack( ptr )         delete last item
ptr removeThisOne( ptr, ptr ) delete item at this loc

*/


#include <stdio.h>
#include <stdlib.h>

struct boxtype
{
	int val;
	struct boxtype *link;
};

struct boxtype *makeNode( int x )
{
	struct boxtype *mynode;

	mynode = malloc( sizeof( struct boxtype)  );
	mynode->val = x;
	mynode->link = NULL;

	return mynode;

}


int listLength( struct boxtype *front )
{
	struct boxtype *mov;
	int len = 0;

	mov = front;

	while ( mov != NULL )
	{
		len++;
		mov = mov->link;
	}

	return len;
}


void printList( struct boxtype *front )
{
	struct boxtype *mov;

	printf("List: ");

	mov = front;

	while ( mov != NULL )
	{
		printf("%d ", mov->val);
		mov = mov->link;
	}

	printf("\n");
}


struct boxtype *insertFront( struct boxtype *first, int num )
{
	struct boxtype *tmp;

	tmp = makeNode( num );

	tmp->link = first;

	first = tmp;

	return first;
}


int main()
{
	struct boxtype *b,*starteven, *startodd, *startover30, *startunder30;
	int i, x, k, r;

	starteven = NULL;
	startodd = NULL;
	startover30 = NULL;
	startunder30 = NULL;

	printf("even list:\n");
	printList( starteven );
	printf("odd list:\n");
	printList( startodd );
	printf("over30 list:\n");
	printList( startover30 );
	printf("under30 list:\n");
	printList( startunder30 );
	printf("\n");

	for ( k = 0; k < 13; k++ )
	{
		r = rand() % 75 + 1;

		printf("r == %d\n\n", r);

		if ( r % 2 == 0 )
			starteven = insertFront(starteven, r);
		else
			startodd = insertFront(startodd, r);

		if ( r > 30 )
			startover30 = insertFront(startover30, r);
		else
			startunder30 = insertFront(startunder30, r);

		printf("even list:\n");
		printList( starteven );
		printf("odd list:\n");
		printList( startodd );
		printf("over30 list:\n");
		printList( startover30 );
		printf("under30 list:\n");
		printList( startunder30 );
		printf("\n");
	}


	return 0;
}
