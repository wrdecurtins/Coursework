#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct boxtype
{
	int actnum;
	float balance;
	struct boxtype *forward;
};

struct boxtype *makeAccount( int x, float y )
{
	struct boxtype *myAccount;

	myAccount = malloc( sizeof( struct boxtype ) );
	myAccount->actnum = x;
	myAccount->balance = y;
	myAccount->forward = NULL;
//	myAccount->backward = NULL;

	return myAccount;
}

struct boxtype *insertFront( struct boxtype *first, int x, float y )
{
        struct boxtype *tmp;

        tmp = makeAccount( x, y );

        tmp->forward = first;

//		first->backward = tmp;

        first = tmp;

        return first;
}

void printList( struct boxtype *front )
{
        struct boxtype *mov;

        mov = front;

                printf("%d : $%.2f\n", mov->actnum, mov->balance);
                mov = mov->forward;


        while ( mov != NULL )
        {
                printf("%d : $%.2f\n", mov->actnum, mov->balance);
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

	start = NULL;

//	printf("here1");

	start = insertFront( start, 12345, 12.45 );
	start = insertFront( start, 54321, 21.34 );
	start = insertFront( start, 321, 28.30 );
	printList( start );

/*

	fgets( buff, 50, fp );

	while ( feof(fp) != 1 )
	{
//	printf("here2");


//	printf("here3");
		printf("%s\n", buff);

		int accountNumber = 0, k;
		float accountBalance = 0;
		int tmpan[20], tmpabpre[20], tmpabpost[20], numdigitsan = 0, i = 0, numdigitsab = 0;

//	printf("here4");


		for ( k = 0; k < strlen(buff); k++ )
		{
		int tmpan[20], tmpabpre[20], tmpabpost[20], numdigitsan = 0, i = 0, numdigitsab = 0;

//	printf("here5");
			printf("%c\n", buff[k]);

			if ( buff[k] == '#' )
			{
	printf("here7");

				k++;
				while ( buff[k] != ':' )
				{
					printf("numdigitsan = %d\n", numdigitsan);
//					printf("here8");
//					printf("\n%c\n",buff[k]);
					int ibuff = buff[k] - '0';
//					printf("%d\n",ibuff);
					tmpan[i] = ibuff;
//					printf("%d\n",tmpan[i]);
					k++;
					i++;
					numdigitsan++;
					printf("numdigitsan = %d\n", numdigitsan);
				}
			}
	printf("here9");


			if ( buff[k] == '$' )
			{
	printf("here10");

				k++;
				i = 0;
				while ( buff[k] != '.' )
				{
					printf("here11");
					int ibuff = buff[k] - '0';
					tmpabpre[i] = ibuff;
					k++;
					i++;
					numdigitsab++;
				}
//	printf("here12");

				while ( buff[k] != '\n' )
				{
//	printf("here13");

					tmpabpost[i] = buff[k] * '0';
					k++;
					i++;
				}
			}
		}
//	printf("here14");


//		if ( feof(fp) == 0 )
//		{
//	printf("here15");
			printf("numdigitsan = %d\n", numdigitsan);
			for ( k = 0; k < numdigitsan; k++ )
			{
//	printf("here16");

				int power = 1;

				for ( i = 0; i < numdigitsan - k; i++ )
				{
//					printf("here17");

					power *= 10;
				}

//	printf("here18");
				printf("%d\n", tmpan[k]);
				accountNumber += tmpan[k] * power;
				printf("%d\n", accountNumber);
			}
//	printf("here19");

			for ( k = 0; k < numdigitsab; k++ )
			{
//	printf("here20");

				int power = 1;
				for ( i = 0; i < numdigitsab - k; i++ )
				{
//	printf("here21");

					power *= 10;
				}

//	printf("here22");
				accountBalance += tmpabpre[k] * power;
			}
//	printf("here23");
			accountBalance += tmpabpost[0]*0.1 + tmpabpost[1]*0.02;
//	printf("here24");
			printf("accountNumber= %d\n\n", accountNumber);

			start = insertFront( start, accountNumber, accountBalance );
//	printf("here25");

//		}

//		fgets( buff, 50, fp );

	}
//	printf("here26");




	printList( start );
*/
	return 0;
}

