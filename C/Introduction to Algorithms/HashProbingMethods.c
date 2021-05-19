#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXK 11

int linearInsert( int hashTable[MAXK], int vals[MAXK] );
int quadInsert( int hashTable[MAXK], int vals[MAXK] );
int doubleHash( int hashTable[MAXK], int vals[MAXK] );
void printArray( int arr[MAXK] );
void initHashTable( int hashTable[MAXK] );

int main()
{
        int hashTable[MAXK] = {0};
        int vals[MAXK + 1] = {10,22,31,4,15,28,17,88,59,-1};

        initHashTable(hashTable);
        linearInsert( hashTable, vals );
        initHashTable(hashTable);
        quadInsert( hashTable, vals );
        initHashTable(hashTable);
        doubleHash(hashTable, vals);

        return 0;
}

int linearInsert( int hashTable[MAXK], int vals[MAXK] )
{
        int collisions = 0;
        int oldloc, k = 0;

        while ( vals[k] > -1 )
        {
                int loc = vals[k] % MAXK;
                if ( hashTable[loc] != -1 )
                {
                        collisions++;
                        oldloc = loc % MAXK;
                        loc++;

                        for ( loc; loc % MAXK != oldloc; loc++ )
                        {
                                if ( hashTable[loc] == -1 )
                                {
                                        hashTable[loc] = vals[k];
                                        break;
                                }
                        }
                }
                else
                        hashTable[loc] = vals[k];
                k++;
        }

        printf("\nLinear Probing Table: ");
        printArray(hashTable);
        printf("Collisions: %d\n", collisions);

        return collisions;
}

int quadInsert( int hashTable[MAXK], int vals[MAXK] )
{
        int i, k = 0, collisions = 0;

        while ( vals[k] > -1 )
        {
                int loc = vals[k] % MAXK;

                if ( hashTable[loc] != -1 )
                {
                        collisions++;
                        int oldloc = loc;

                        for ( i = 1; i < MAXK; i++ )
                        {
                                loc = (oldloc + i + 3 * (i * i)) % 11;
                                if ( hashTable[loc] == -1 )
                                {
                                        hashTable[loc] = vals[k];
                                        break;
                                }
                        }
                }
                else
                        hashTable[loc] = vals[k];
                k++;
        }

        printf("\nQuadratic Probing Table: ");
        printArray(hashTable);
        printf("Collisions: %d\n", collisions);

        return collisions;
}

int doubleHash( int hashTable[MAXK], int vals[MAXK] )
{
        int k = 0, collisions = 0;

        while ( vals[k] > -1 )
        {
                int loc = vals[k] % MAXK;
                if ( hashTable[loc] != -1 )
                {
                        collisions++;
                        int oldloc = loc;
                        int oldloc2 = (vals[k] % (MAXK - 1)) + 1;
                        for ( int i = 1; i < MAXK; i++ )
                        {
                                loc = ( oldloc + i * oldloc2 ) % MAXK;

                                if ( hashTable[loc] == -1 )
                                {
                                        hashTable[loc] = vals[k];
                                        break;
                                }
                        }
                }
                else
                        hashTable[loc] = vals[k];
                k++;
        }


        printf("\nDoubleHash Probing Table: ");
        printArray(hashTable);
        printf("Collisions: %d\n", collisions);

        return collisions;
}

void printArray( int arr[MAXK] )
{
        printf("\n");

        for ( int k = 0; k < MAXK; k++ )
        {
                if ( arr[k] < 0 )
                        printf("%d: NULL\n", k);
                else
                        printf("%d: %d\n", k, arr[k]);
        }

        printf("\n");
}

void initHashTable( int hashTable[MAXK] )
{
        for ( int i = 0; i < MAXK; i++ )
                hashTable[i] = -1;
}
