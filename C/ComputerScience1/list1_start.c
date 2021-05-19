#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxList 50

void insertEnd( int L[], int x )
{
	int location = L[0] + 1;
	L[location] = x;
	L[0]++;
}

void insertFront( int L[], int x )
{
	int len = L[0], k;

	for ( k = len; k > 0; k-- )
		L[k+1] = L[k];

	L[1] = x;
	L[0]++;
}

int isEmpty( int L[] )
{
	if ( L[0] == 0 )
		return 1;
	return 0;
}

int isFull( int L[] )
{
	if ( L[0] >= (MaxList - 1) )
		return 1;
	return 0;
}

void printList( int L[] )
{
	int len, k;
	len = L[0];

	for ( k = 1; k <= len; k++ )
		printf("%2d ", L[k]);

	printf("\n");
}


int main()
{
 int L[MaxList] = {0};
 int x, i;

 srand( 3 );

 if (isEmpty(L))
   printf("1 empty\n");
 else
   printf("1 notempty\n");

 if (isFull(L))
   printf("1 full\n");
 else
   printf("1 notfull\n");

 x = rand() % 100;
 insertEnd( L, x );
 printList( L );
 x = rand() % 100;
 insertEnd( L, x );
 printList( L );

 if (isEmpty(L))
   printf("2 empty\n");
 else
   printf("2 notempty\n");

 if (isFull(L))
   printf("2 full\n");
 else
   printf("2 notfull\n");

 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertEnd( L, x );
   printList( L );
  }
 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertFront( L, x );
   printList( L );
  }

 if (isEmpty(L))
   printf("3 empty\n");
 else
   printf("3 notempty\n");

 if (isFull(L))
   printf("3 full\n");
 else
   printf("3 notfull\n");

 return 0;
}
