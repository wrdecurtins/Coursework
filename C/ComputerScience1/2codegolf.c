#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct boxtype
{
        int actnum;
        float balance;
        struct boxtype *forward;
//      struct account *backward;
};

struct boxtype *makeAccount( int x, float y )
{
        struct boxtype *myAccount;

        myAccount = malloc( sizeof( struct boxtype ) );
        myAccount->actnum = x;
        myAccount->balance = y;
        myAccount->forward = NULL;
//      myAccount->backward = NULL;

        return myAccount;
}

struct boxtype *insertFront( struct boxtype *first, int x, float y )
{
        struct boxtype *tmp;

        tmp = makeAccount( x, y );

        tmp->forward = first;

        first = tmp;

        return first;
}

void printList( struct boxtype *front )
{
        struct boxtype *mov;

        mov = front;

        while ( mov != NULL )
        {
            printf("%d : %.2f", mov->actnum, mov->balance);
            mov = mov->forward;
        }

        printf("\n");
}

int main( int argc, char *argv[] )
{
        struct boxtype *start;
        FILE *fp;
        fp = fopen( argv[1], "r");
        char buff[50];
        int endOfAccounts = 0;

		start = NULL;

        fgets( buff, 50, fp );

//		start = insertFront( start, 23456, 12.89 );
//		printList( start );




 //       while ( feof(fp) != 1 )
   //     {
//                printf("%s\n", buff);

                int accountNumber = 0, k;
				float accountBalance = 0.00;
                int tmpan[20], i = 0, numdigitsab = 0, m;

                for ( k = 0; k < strlen(buff); k++ )
                {
                int tmpan[20], tmpabpre[20], tmpabpost[20], numdigitsan = 0, i = 0, numdigitsab = 0;

  //                      printf("%c\n", buff[k]);

                        if ( buff[k] == '#' )
                        {
                                k++;
                                while ( buff[k] != ':' )
                                {
    //                                printf("numdigitsan = %d\n", numdigitsan);

                                    int ibuff = buff[k] - '0';
                                    tmpan[i] = ibuff;
                                    k++;
                                    i++;
                                    numdigitsan++;
      //                              printf("numdigitsan = %d\n", numdigitsan);
                                }

                        }

//                        printf("numdigitsan = %d\n", numdigitsan);
                        for ( m = 0; m < numdigitsan; m++ )
                        {
                                int power = 1;

                                for ( i = 0; i < numdigitsan - m - 1; i++ )
                                {
                                        power *= 10;
                                }

        //                        printf("%d\n", tmpan[m]);
                                accountNumber += tmpan[m] * power;
          //                      printf("%d\n", accountNumber);
                        }

/*                        for ( k = 0; k < numdigitsab; k++ )
                        {
                                int power = 1;
                                for ( i = 0; i < numdigitsab - k - 1; i++ )
                                {
                                        power *= 10;
                                }

                                accountBalance += tmpabpre[k] * power;
                        }
*/
//                        printf("accountNumber= %d\n\n", accountNumber);

                        start = insertFront( start, accountNumber, 0);



//					printf("%d %f", start->actnum, start->balance);


                fgets( buff, 50, fp );

//		}
        printList( start );

		}
        return 0;

}


