
// Recursive Linked List Functions   Spring 2018
/*
Implement recurive versions of these functions:

void printList( ptr )
int listLength( ptr )
int isInList( ptr, int )      1: if val is in list
int maxVal( ptr )             largest value
int countFreq( ptr, int )     how many does does the value appear

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
	struct boxtype *b;

	b = malloc( sizeof( struct boxtype )  );
	b->val = x;
	b->link = NULL;
	return b;
}


int listLength( struct boxtype *front )
{
	if ( front == NULL )
		return 0;
	else if ( front->link == NULL )
		return 1;
	else
		return 1 + listLength(front->link);
}


void printList( struct boxtype *front )
{

	if ( front == NULL )
	{
		printf("\n");
		return;
	}
	else
	{
		printList( front->link );
		printf("%d ", front->val);
	}
}


struct boxtype *insertFront( struct boxtype *first, int num )
{
	struct boxtype *b;
	b =  makeNode( num );
	b->link = first;
	first = b;
	return first;
}

int isEmpty( struct boxtype *front )
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

int isInList( struct boxtype *front, int num )
{
	if ( front == NULL )
		return 0;
	else if ( front->val == num )
	{
		return 1;
	}
	else
		return isInList( front->link, num );
}

// list will not be empty on first call
int maxVal( struct boxtype *front )
{
	if ( front->link == NULL )
		return 0;
	if ( front->val > maxVal( front->link ))
		return front->val;
	if ( front->val < maxVal( front->link))
		return maxVal( front->link );
}

int countFreq( struct boxtype *front, int num )
{
	if ( front == NULL )
		return 0;
	else if ( front->val == num )
		return 1 + countFreq( front->link, num );
	else
		return countFreq( front->link, num );
}


int main()
{
	struct boxtype *b, *start;
	int i, x, z, mv;

	start = NULL;

	printList( start );
	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		start = insertFront( start, x );
		printList( start );
	}
	printList( start );
	x = listLength( start );
	printf("Len %d\n", x );

	mv = maxVal( start );
	printf("big  %d\n", mv );
	printList( start );

	printf("Value to search: ");
	scanf("%d", &x);
	z = isInList( start, x  );
	printf("In list: %d\n", z);

	z = countFreq( start, x );
	printf("Value %d shows %d times\n", x, z);
	return 0;
}
