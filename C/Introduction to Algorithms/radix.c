#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRSIZE 20
#define NUMSTR 6
#define ONELESSTHANA 96
#define CHARSET 27

//char strings [NUMSTR][MAXSTRSIZE] = {"dcba","aabc","adca","cddd"};
//char strings [NUMSTR][MAXSTRSIZE] = {"a","c","d","b"};
//char strings [NUMSTR][MAXSTRSIZE] = {"ba                 ","ac                 ","dd                 ","bb                 "};
//char strings [NUMSTR][MAXSTRSIZE] = {"ba","ac","dd","bb"};
//char strings [NUMSTR][MAXSTRSIZE] = {"crackers", "Cheese", "salami", "Salad Dressing"};
char strings [NUMSTR][MAXSTRSIZE] = {"Cheese", "Video player", "salami", "Salad Dressing", "video card", "crackers"};


void printIntArray( int arr[CHARSET] );

void printStrings( char str[][MAXSTRSIZE] )
{
        for ( int k = 0; k < NUMSTR; k++ )
        {
                if ( k == NUMSTR - 1)
                        printf("%s\n", str[k]);
                else
                        printf("%s, ", str[k]);

        }
}

void countSort( int sortIndex, char A[][MAXSTRSIZE] )
{
        char B[NUMSTR][MAXSTRSIZE];
        int C[CHARSET] = {0};

        for ( int k = 0; k < NUMSTR; k++ )
        {
                char acharc = tolower(A[k][sortIndex]);

//              printf("acharc = %c\nintacharc = %d\n", acharc, (int) acharc - ONELESSTHANA);


                if ( A[k][sortIndex] == ' ')
                        C[0]++;
//              else if ( (int)A[k][sortIndex] - ONELESSTHANA < 0 )
                else if ( (int)acharc - ONELESSTHANA < 0 )
                        continue;
                else
//                      C[(int)tolower(A[k][sortIndex]) - ONELESSTHANA]++;
                        C[(int)acharc - ONELESSTHANA]++;
        }

//      printIntArray(C);

        for ( int k = 1; k < CHARSET; k++ )
                C[k] = C[k] + C[k-1];

//      printIntArray(C);

        for ( int k = NUMSTR - 1; k >= 0; k-- )
        {
                char achar = tolower(A[k][sortIndex]);

//              printf("achar = %c\nintachar = %d\n", achar, (int) achar - ONELESSTHANA);

                if ( achar == ' ' )
                {
//                      printIntArray(C);
                        strncpy(B[C[0]-1],A[k],MAXSTRSIZE);
//                      printStrings(B);
                        C[0]--;
//                      printIntArray(C);

                }
                else if ( achar >= 'a' && achar <= 'z' )
                {
//                      printIntArray(C);
//                      printf("%s\n",A[k]);
                        strncpy(B[C[(int)achar - ONELESSTHANA]-1],A[k],MAXSTRSIZE);
//                      strncpy(strings[C[(int)achar - ONELESSTHANA]],"you",MAXSTRSIZE);
//                      printStrings(B);
                        C[(int)achar - ONELESSTHANA]--;
//                      printIntArray(C);
                }
                else
                {
                        printf("\nERROR\n");
                }


        }

        for ( int i = 0; i < NUMSTR; i++  )
        {
                strncpy(strings[i],B[i],MAXSTRSIZE);
        }

}

int main()
{
//      char strings [NUMSTR][MAXSTRSIZE] = {"crackers","Cheese","salami","Salad Dressing"};
//      char strings [NUMSTR][MAXSTRSIZE] = {"dcba","aabc","adca","cddd"};

        printf("Sorting: \n");
        printStrings(strings);
        printf("\n");

        for ( int h = 0; h < NUMSTR; h++ )
        {
                while ( strlen(strings[h]) < MAXSTRSIZE - 1 )
                {
                        strncat(strings[h], " ", MAXSTRSIZE);
                }
        }

//      countSort(0, strings);
//      Radix(strings);
        for ( int k = MAXSTRSIZE - 3; k >= 0; k-- )
                countSort(k,strings);

        for ( int m = 0; m < NUMSTR; m++ )
        {
                while ( strings[m][strlen(strings[m])-1] == ' ' )
                {
                        strings[m][strlen(strings[m])-1] = '\0';
                }
        }

        printf("Sorted: \n");
        printStrings(strings);

//      for (int k = 0; k < NUMSTR; k++ )
//              strncpy(strings[k],"you",MAXSTRSIZE);
//      printStrings(strings);

        return 0;
}

void printIntArray( int arr[CHARSET] )
{
        printf("\n");

        for ( int k = 0; k < CHARSET; k++ )
        {
                printf("%d ", arr[k]);
        }

        printf("\n");
}
