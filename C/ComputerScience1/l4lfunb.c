
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

struct boxtype *makeNode( int x );
void printList( struct boxtype *front );
struct boxtype *insertFront( struct boxtype *first, int num );
int listLength( struct boxtype *front );

int isEmpty( struct boxtype *front );
int isInList( struct boxtype *front, int x );
struct boxtype *getLoc( struct boxtype *box, int x );
int maxVal( struct boxtype *front );
struct boxtype *maxLoc( struct boxtype *front );

struct boxtype *insertBack( struct boxtype *first, int num );

struct boxtype *insertAfter( struct boxtype *first, struct boxtype *here, int num );

struct boxtype *removeFront( struct boxtype *first );
struct boxtype *removeBack( struct boxtype *first );
struct boxtype *removeThisOne( struct boxtype *first, struct boxtype *here );

int main()
{
 struct boxtype *two;
        int i, x;

        two = NULL;

        for ( i = 0; i < 20; ++i )
        {
                x = rand() % 200 + 1;
                two = insertBack( two, x );
        }

        int tot = 99;
        int n = 11;

        int mv;
        struct boxtype *ml;
        while ( !isEmpty( two ) )
        {
				mv = maxVal( two );
                ml = maxLoc( two );
                two = removeThisOne( two, ml );
        }
        printf("%d\n", tot);
        return 0;

}

//This function creates the linked list items and sets the link to NULL
struct boxtype *makeNode( int x )
{
	struct boxtype *mynode;

	mynode = malloc( sizeof( struct boxtype)  );
	mynode->val = x;
	mynode->link = NULL;

	return mynode;

}

//This function prints the entire linked list to the screen
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

//This function inserts a new list item at the front of the list
struct boxtype *insertFront( struct boxtype *first, int num )
{
	struct boxtype *tmp;

	tmp = makeNode( num );

	tmp->link = first;

	first = tmp;

	return first;
}

//This function returns how many items are in the list
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

//This function returns a 1 if the list is empty and a 0 if not
int isEmpty( struct boxtype *front )
{
	struct boxtype *mov;

	mov = front;

	if ( mov == NULL )
		return 1;
	return 0;
}

//This function searchs the linked list for a specific value and returns a 1 if it is found (otherwise 0)
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

//This function finds and returns the list item with x value
struct boxtype *getLoc( struct boxtype *front, int x )
{
	struct boxtype *mov, *rt;

	mov = front;

	while ( mov->link != NULL )
	{
		if ( mov->val == x )
			rt = mov;
		mov = mov->link;
	}

	return rt;
}

//This function finds the highest value in the list and returns it
int maxVal( struct boxtype *front )
{
	struct boxtype *mov;
	int max;

	mov = front;
	max = mov->val;

	while ( mov->link != NULL )
	{
	if ( mov->val > max )
			max = mov->val;
		mov = mov->link;
	}

	return max;
}

//This function finds the list location of the greatest value and returns it
struct boxtype *maxLoc( struct boxtype *front )
{
	struct boxtype *mov, *rt;
	int max;

	//This if statement checks to see if the list has only one item
	if ( front->link == NULL )
	{
		rt = front;
	}
	else //this else handles all other conditions
	{
		mov = front;

		max = maxVal(front);
		while ( mov->link != NULL )
		{
			if ( mov->val == max )
				rt = mov;
			mov = mov->link;
		}
	}
	return rt;
}

//This function inserts a new list item at the back of the list
struct boxtype *insertBack( struct boxtype *first, int num )
{
	//This if checks to see if there are zero items in the list
	if( first == NULL )
	{
		first = makeNode( num );
	}
	else//this else handles all other conditions
	{
		struct boxtype *tmp, *mov;

		tmp = makeNode( num );

		mov = first;

		while( mov->link != NULL )
		{
			mov = mov->link;
		}
		mov->link = tmp;
	}
	return first;
}

//This function takes a list location and inserts a new list item after it
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

//This function deletes the first item in the list
struct boxtype *removeFront( struct boxtype *first )
{
	first = first->link;

	return first;
}

//This function deletes the last item in the list
struct boxtype *removeBack( struct boxtype *first )
{
	//This if checks to see if there is only one item in the list
	if ( first->link == NULL )
	{
		first = NULL;
	}
	else//this else handles all other cases
	{
		struct boxtype *mov, *mov2;

		mov = first;
		mov2 = first;

		while ( mov->link != NULL )
			mov = mov->link;

		while ( mov2->link != mov )
			mov2 = mov2->link;

		mov2->link = NULL;
	}
	return first;
}

//This Function takes a list location and removes the list item at that location
struct boxtype *removeThisOne( struct boxtype *first, struct boxtype *here )
{
	//this if checks to see if there is only one list item
	if ( first->link == NULL )
	{
		first = NULL;
	}
	else if ( first == here )//this if checks if the first item is the item to be removed
	{
		first = first->link;
	}
	else if ( listLength(first) == 2 )//if checks to see if there are only two list items and the first one is not the one being removed
	{
		first->link = NULL;
	}
	else//this handles all other cases
	{
		struct boxtype *tmp, *mov;

		mov = first;
		tmp = first;

		while( tmp->link != here->link )
			tmp = tmp->link;

		while( mov->link != tmp )
			mov = mov->link;
		mov->link = tmp->link;
	}

	return first;
}

