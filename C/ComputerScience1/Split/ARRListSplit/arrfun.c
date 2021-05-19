#include "arrfun.h"



int listLength( list L )
{
	return L->len;
}


void printList( list L )
{
	int mov;
	printf("List: [%2d]: ", L->len);
	for ( mov = L->first; mov < L->last; ++mov )
	{
		printf("%2d ", L->dat[mov] );
	}
	printf("\n");	
}



void insertFront( list L, int num )
{
	int i;
	// shift everything to open spot 0
	for ( i = L->last; i > 0; --i )
	{
		//printf("Moving %d to %d\n", i-1, i);
		L->dat[i] = L->dat[i-1];
	}

	// add the new value
	L->dat[0] = num;

	L->last++;
	L->len++;
}


void insertBack( list L, int num )
{
	int loc;
	loc = L->last;
	L->dat[loc] = num;
	L->last++;
	L->len++;
}

void removeFront( list L )
{
	int i;
	// shift everything to cover spot 0
	L->last--;
	L->len--;
	for ( i = 0; i < L->last; ++i )
	{
		//printf("Moving %d to %d\n", i-1, i);
		L->dat[i] = L->dat[i+1];
	}

}

void removeBack( list L )
{
	L->last--;
	L->len--;
}



int isEmpty( list L )
{
	return L->len == 0;
}

int isInList( list L, int x )
{
	int i;
	for ( i = 0; i < L->len; ++i )
	{
		if ( L->dat[i] == x )
			return 1;
	}
	return 0;
}

int getLoc( list L, int x )
{
	int i;
	for ( i = 0; i < L->len; ++i )
	{
		if ( L->dat[i] == x )
			return i;
	}
	return -1;
}

int maxVal( list L )
{
	int i;
	int big;
	big = L->dat[0];
	for ( i = 0; i < L->len; ++i )
	{
		if ( L->dat[i] > big )
			big = L->dat[i];
	}
	return big;
}

int maxLoc( list L )
{
	int i;
	int big, bigloc;
	big = L->dat[0];
	bigloc = 0;
	for ( i = 0; i < L->len; ++i )
	{
		if ( L->dat[i] > big )
		{
			big = L->dat[i];
			bigloc = i;
		}
	}
	return bigloc;
}


void insertAfter( list L, int loc, int num )
{
    int i;
    // shift everything to open spot     loc 
    for ( i = L->last; i > loc; --i )
    {
        //printf("Moving %d to %d\n", i-1, i);
        L->dat[i] = L->dat[i-1];
    }

    // add the new value
    L->dat[loc] = num;

    L->last++;
    L->len++;
}

void removeThisOne( list L, int loc )
{
    int i;
    // shift everything to cover spot    loc 
    L->last--;
    L->len--;
    for ( i = loc; i < L->last; ++i )
    {
        //printf("Moving %d to %d\n", i-1, i);
        L->dat[i] = L->dat[i+1];
    }
}


list makeList()
{
	list newL;

	newL = malloc( sizeof( *newL ));
	newL->first = 0; 
	newL->last = 0; 
	newL->len = 0;

	return newL;
}

