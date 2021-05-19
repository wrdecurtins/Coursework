
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
	char val(100);
	struct boxtype *link;
};

struct boxtype *makeNode( char x )
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
		printf("%s ", mov->val);
		mov = mov->link;
	}

	printf("\n");
}


struct boxtype *insertFront( struct boxtype *first, char num )
{
	struct boxtype *tmp;

	tmp = makeNode( num );

	tmp->link = first;

	first = tmp;

	return first;
}


int main( int argc, char *argv[] )
{
	FILE *fp;
	struct boxtype *b,*start;
	char tmp(100);
	int i, x, k, r;

	start = NULL;

	fp = fopen( argv[1], "r" );

	fgets( tmp, 100, fp );
	start = insertFront(start, tmp);

	

	while ( feof(fp) != 1 )
	{
		fgets( tmp, 100, fp );
		start = insertFront(start, tmp);
	}



	return 0;
}
