// Linked List program 3

// Create a Header Node to represent the linked list
// Renamed many items to keep it interesting and fresh

// Functions
//  List functions
//    - create a new list
//    - allocate a node
//    - insert node at front
//    - print list
//    - find length of list
//  Utility functions
//    - allocate a node

#include <stdio.h>
#include <stdlib.h>

typedef struct elem_type node;
typedef node *link;

struct  elem_type
{
	int data;
	link next;
	link prev;
};

struct header_type
{
	link first;
	link last;
	int  len;
};

typedef struct header_type *list;


link makeNode( int x )
{
	link b;

	b = malloc( sizeof( node )  );
	b->data = x;
	b->next = NULL;
	b->prev = NULL;
	return b;
}


int listLength( list L )
{
	return L->len;

	/*
	int len = 0;
	link mov;
	mov = L->first;
	while ( mov != NULL )
	{
		len++;
		mov = mov->next;
	}
	return len;
	*/
}


void printList( list L )
{
	link mov;
	printf("List: [%2d]: ", L->len);
	mov = L->first;
	while ( mov != NULL )
	{
		printf("%2d ", mov->data );
		mov = mov->next;
	}
	printf("\n");
}


void insertFront( list L, int num )
{
	link b;
	b =  makeNode( num );
	b->next = L->first;
	L->first = b;

	if(b->next != NULL)
	{
		b->next->prev = b;
	}
	else
	{	// Empty list
		L->last = b;
	}

	L->len++;
}

list makeList()
{
	list newL;

	newL = malloc( sizeof( *newL ));
	newL->first = NULL;
	newL->last = NULL;
	newL->len = 0;

	return newL;
}

void insertBack(list L, int x)
{
	link b;
	b = makeNode(x);
	b->prev = L->last;
	L->last = b;

	if(b->prev == NULL)
	{
		L->first = b;
	}
	else
	{
		b->prev->next = b;
	}

	L->len++;
}

void insertAfter(list L, link loc, int x)
{
	link b;
	b = makeNode(x);
	b->prev = loc;
	b->next = loc->next;
	loc->next = b;

	if(loc->next == NULL)
	{
		L->last = b;
	}
	else
	{
		loc->next->prev = b;
	}

	L->len++;
}

void removeThisOne(list L, link loc)
{
	if(loc->prev == NULL)
	{
		L->first = loc->next;
	}
	else
	{
		loc->prev->next = loc->next;
	}

	if(loc->next == NULL)
	{
		L->last = loc->prev;
	}
	else
	{
		loc->next->prev = loc->prev;
	}

	free(loc);
	L->len--;
}


// ADDED AFTER CLASS
void removeFront(list L)
{
	link tmp = L->first;
	L->first = tmp->next;

	if(tmp->next == NULL)
	{
		L->last = NULL;
	}
	else
	{
		tmp->next->prev = NULL;
	}

	free(tmp);
	L->len--;
}

void removeBack(list L)
{
	link tmp = L->last;
	L->last = tmp->prev;

	if(tmp->prev == NULL)
	{
		L->first = NULL;
	}
	else
	{
		tmp->prev->next = NULL;
	}

	free(tmp);
	L->len--;
}

int main()
{
	list AList;
	int k, x;

	AList = makeList();

	insertFront( AList, 12 );
	insertFront( AList, 12 );
	printList( AList );
	printf("Len %d\n", listLength( AList ) );

//a) Insert 5 random values (under 100)

	for ( k = 0; k < 5; ++k )
	{
		x = rand() % 100;
		printf("Adding %d\n", x);
		insertAfter( AList, AList->first->next, x );
		printList( AList );
	}


//b) Print the list

	printList( AList );


	for ( k = 0; k < 5; ++k )
	{
		removeThisOne( AList, AList->last->prev);
		printList (AList);
	}

	printList (AList);
	return 0;
}
