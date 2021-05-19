
#include <stdio.h>
#include <stdlib.h>

struct header_type
{
	int first;
	int last;
	int len;
	int dat[100];
};

typedef struct header_type *list;


int listLength( list L );
void printList( list L );
void insertFront( list L, int num );
void insertBack( list L, int num );
void removeFront( list L );
void removeBack( list L );
int isEmpty( list L );
int isInList( list L, int x );
int getLoc( list L, int x );
int maxVal( list L );
int maxLoc( list L );
void insertAfter( list L, int loc, int num );
void removeThisOne( list L, int loc );
list makeList();

