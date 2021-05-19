
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


// code for 3/26 & 3/27
// Start with llfunb from last time
// add a few more functions

// Create a copy of our code from last time
// Remove the code from main()

// Now we work together

// Let's type in our main
//   -- well copy it from D2L content  main326

int countMultOf5( struct boxtype *first )
{
	struct boxtype *mov;
	int m5 = 0;

	mov = first;

	while ( mov != NULL )
	{
		if ( mov->val % 5 == 0 )
			m5++;
		mov = mov->link;
	}
	return m5;
}

void add5ToAll( struct boxtype *first )
{
	struct boxtype *mov;
    mov = first;
    while ( mov != NULL )
    {
		mov->val += 5;
        mov = mov->link;
    }
}


int main()
{
    struct boxtype *b, *start;
    int k, x;

    start = NULL;

    start = insertFront( start, 12 );
    printList( start );
    printf("Len %d\n", listLength( start ) );

//a) Insert 20 random values (under 100)
    for ( k = 0; k < 20; k++ )
        {
                x = rand() % 100;
                start = insertFront( start, x );
        }

//b) Print the list
    printList( start );

//c) Write a function to count multiples of 5 in a list
//d) Call function & print result in main

	x = countMultOf5( start );
	printf("%d multiples of 5\n", x);


//e) add 5 to every data value in the list





        return 0;
}

