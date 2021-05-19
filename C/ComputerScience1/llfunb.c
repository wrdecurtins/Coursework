
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

int maxVal( struct boxtype *front )
{
	struct boxtype *mov;
	int max;

	mov = front;
	max = mov->val;

	while ( mov != NULL )
	{
		if ( mov->val > max )
			max = mov->val;
		mov = mov->link;
	}

//	printf("max %d", max);

	return max;
}

int isInList( struct boxtype *front, int x )
{
	struct boxtype *mov;

	mov = front;

	while ( mov != NULL )
	{
		if ( mov->val == x )
			return 1;

		mov = mov->link;
	}

	return 0;
}

int isEmpty( struct boxtype *front )
{
	struct boxtype *mov;

	mov = front;

	if ( mov == NULL )
		return 1;
	return 0;
}

struct boxtype *getLoc( struct boxtype *box, int x )
{

}

struct boxtype *maxLoc( struct boxtype *front )
{
/*	struct boxtype *mov, *rt;
	int max;

	mov = front;

	max = maxVal(front);

	while ( mov->link != NULL )
	{
		if ( mov->val == max )
			rt = mov;
		mov = mov->link;
	}

	return rt;
*/
}
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
struct boxtype *insertAfter( struct boxtype *first, struct boxtype *here, int num )
{
	struct boxtype *tmp, *mov;

	mov = first;

	while( mov->link != here->link )
		mov = mov->link;

	tmp = makeNode(num);

	here = here->link;

	tmp->link = here;

	mov->link=tmp;


	return first;

}

struct boxtype *insertBack( struct boxtype *first, int num )
{
	struct boxtype *tmp, *mov;

	tmp = makeNode( num );

	mov = first;

	while( mov->link != NULL )
	{
		mov = mov->link;
	}
	mov->link = tmp;

	return first;
}

struct boxtype *removeFront( struct boxtype *first )
{
	first = first->link;

	return first;
}

struct boxtype *removeBack( struct boxtype *first )
{
	struct boxtype *mov, *mov2;

	mov = first;
	mov2 = first;

	while ( mov->link != NULL )
		mov = mov->link;

	while ( mov2->link != mov )
		mov2 = mov2->link;

	mov2->link = NULL;

	return first;
}

struct boxtype *removeThisOne( struct boxtype *first, struct boxtype *here )
{
	if ( first == here )
		return first->link;

	struct boxtype *tmp, *mov;

	mov = first;
	tmp = first;

	while( tmp->link != here->link )
		tmp = tmp->link;

	while( mov->link != tmp )
		mov = mov->link;
	mov->link = tmp->link;

	return first;
}

int main()
{
	printf("here0");

	struct boxtype *b, *start;
//	struct boxtype *test;
	int i, x;
	printf("here1");

	start = NULL;

/*
	printList( start );

	start = insertFront(start, 33);
	printList(start);

	start = insertBack(start, 7);
	printList(start);

	start = insertFront(start, 19);
	printList(start);

	test = start;

	start = insertAfter(start, test, 7);
	printList(start);

	x = listLength( start );
	printf("%d items\n", x);

	printf("highest val: %d\n", maxVal(start));

	test = test->link;
	printList(start);
	start = removeThisOne(start, test);
	printList(start);

	start = removeFront(start);
	printList(start);

	start = removeBack(start);
	printList(start);

	x = listLength( start );
	printf("%d items\n", x);

	printf("highest val: %d\n", maxVal(start));
//	printf("highest loc: %d\n", maxLoc(start));
*/

	printf("here2");

	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		if ( x % 2 == 0 )
			start = insertFront( start, x );
		else
			start = insertBack( start, x );
	printf("here3");

		printList( start );
	}
	printf("Len %d\n", listLength( start ) );


	while ( !isEmpty( start ) )
	{
		x = start->val;
		printf("%d\n", x);
		start = removeFront( start );
		printList( start );
	}


	while ( !isEmpty( start ) )
	{
		start = removeBack( start );
		printList( start );
	}


	int mv;
	struct boxtype *ml;
	while ( !isEmpty( start ) )
	{
		mv = maxVal( start );
		ml = maxLoc( start );
		printf("big  %d\n", mv );
		start = removeThisOne( start, ml );
		printList( start );
	}

	return 0;
}
