#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct boxtype
{
        int actnum;
		int checked;
        float balance;
        struct boxtype *forward;
};

struct boxtype *makeAccount( int x, float y )
{
        struct boxtype *myAccount;

        myAccount = (struct boxtype*)malloc( sizeof( struct boxtype ) );
        myAccount->actnum = x;
        myAccount->balance = y;
		myAccount->checked = 0;
        myAccount->forward = NULL;

        return myAccount;
}

struct boxtype *insertFront( struct boxtype *first, int x, float y )
{
        struct boxtype *tmp = NULL;

        tmp = makeAccount( x, y );

        tmp->forward = first;

        first = tmp;

        return first;
}

void transfer( struct boxtype *first, int x, int y, float z )
{
	struct boxtype *mov = NULL;

	mov = first;

	while ( mov != NULL )
	{
		if ( mov->actnum == x )
			mov->balance -= z;
		if ( mov->actnum == y )
			mov->balance += z;
		mov = mov->forward;
	}
}

void printList( struct boxtype *front )
{
        struct boxtype *mov;

        mov = front;

		while ( mov != NULL )
   	    {
       	    printf("%d : %.2f\n", mov->actnum, mov->balance);
           	mov = mov->forward;
       	}

        printf("\n");
}

void printOrder( struct boxtype *front )
{
	struct boxtype *mov;
	int i = 0, aorder[100], bigact = 0, k, m;
	float bigbal = -1;

	mov = front;

	while ( mov != NULL )
	{
		i++;
		mov = mov->forward;
	}

	for ( k = 0; k < i; k++ )
	{
		mov = front;
		bigbal = -1;

		for ( m = 0; m < i; m++ )
		{
			if ( mov->checked == 0 )
			{
				if ( mov->balance > bigbal )
				{
					bigbal = mov->balance;
		 			bigact = mov->actnum;
				}
			}
				mov = mov->forward;
		}

		aorder[k] = bigact;

		mov = front;

		for ( m = 0; m < i; m++ )
		{
			if ( mov->actnum == bigact )
			{
				mov->checked = 1;
			}
			mov = mov->forward;
		}
	}

	for ( k = 0; k < i; k++ )
	{
		mov = front;

		for ( m = 0; m < i; m++ )
		{
			if ( mov->actnum == aorder[k] )
				printf("#%d:$%.2f\n", mov->actnum, mov->balance);
			mov = mov->forward;
		}
	}

//	for ( k = 0; k < i; k++ )
//		printf("aorder[k] = %d\n", aorder[k]);
//	printf("i=%d", i);

}


int main()
{
        struct boxtype *start;
        char buff[100] = "";
		int a = 0, nomoreaccounts = 0;
        start = NULL;

//		scanf("%s", buff);


		fgets( buff, 100, stdin );

		do
	   {
//			printf("%s\n", buff);

			for ( a = 0; a < strlen(buff); a++ )
			{
				if ( buff[a] == '-' || buff[a] == '>' )
					nomoreaccounts = 1;

			}

			if ( nomoreaccounts == 0 )
			{
                int accountNumber = 0, k;
                float accountBalance = 0.00;
                int tmpan[100], tmpabpre[100], tmpabpost[100], numdigitsan = 0, i = 0, numdigitsab = 0, m = 0;

                for ( k = 0; k < strlen(buff); k++ )
                {
                int tmpan[100], tmpabpre[100], tmpabpost[100], numdigitsan = 0, i = 0, numdigitsab = 0, m = 0;

                        if ( buff[k] == '#' )
                        {
                                k++;
                                while ( buff[k] != ':' )
                                {
                                    int ibuff = buff[k] - '0';
                                    tmpan[i] = ibuff;
                                    k++;
                                    i++;
                                    numdigitsan++;
                                }

                        }

                        for ( m = 0; m < numdigitsan; m++ )
                        {
                                int power = 1;

                                for ( i = 0; i < numdigitsan - m - 1; i++ )
                                {
                                        power *= 10;
                                }

                                accountNumber += tmpan[m] * power;
                        }
						k++;
						if ( buff[k] == '$' )
						{
							i = 0;
							k++;
							while ( buff[k] != '.' )
							{
								int ibuff = buff[k] - '0';
								tmpabpre[i] = ibuff;
								k++;
								i++;
								numdigitsab++;
							}

						}

                        for ( m = 0; m < numdigitsab; m++ )
                        {
                                float powerb = 1.00;
                                for ( i = 0; i < numdigitsab - m - 1; i++ )
                                {
                                    powerb *= 10;
                                }
                              accountBalance += tmpabpre[m] * powerb;

                        }

						k++;
						while ( buff[k] != '\n' )
						{
							int ibuff = buff[k] - '0';
							tmpabpost[i] = ibuff;
							k++;
							i++;
							numdigitsab++;
						}

						accountBalance += tmpabpost[0] * 0.1;
						accountBalance += tmpabpost[1] * 0.01;


                        start = insertFront( start, accountNumber, accountBalance);



	             }

//               fgets( buff, 100, stdin );

			}

			else if ( nomoreaccounts == 1 )
			{
				int k;
				int accountNumberFrom = 0, accountNumberTo = 0;
				float transferAmount = 0;


				for ( k = 0; k < strlen(buff); k++ )
                {
                int tmpan[100] = {0}, tmpab[100] = {0}, tmpbalancepre[20] = {0}, tmpbalancepost[20] = {0}, numdigitsab = 0, numdigitsan = 0, i = 0, numdigitsabpre = 0, numdigitsabpost = 0, m = 0;

                        if ( buff[k] == '#' )
                        {
                                k++;
                                while ( buff[k] != '-' )
                                {
                                    int ibuff = buff[k] - '0';
                                    tmpan[i] = ibuff;
                                    k++;
                                    i++;
                                    numdigitsan++;
                                }

                        }

                        for ( m = 0; m < numdigitsan; m++ )
                        {
                                int power = 1;

                                for ( i = 0; i < numdigitsan - m - 1; i++ )
                                {
                                        power *= 10;
                                }

                                accountNumberFrom += tmpan[m] * power;
                        }

						k += 2;

						if ( buff[k] == '#' )
                        {
                                k++;
                                while ( buff[k] != ':' )
                                {
                                    int ibuff = buff[k] - '0';
                                    tmpab[i] = ibuff;
                                    k++;
                                    i++;
                                    numdigitsab++;
                                }

                        }

                        for ( m = 0; m < numdigitsab; m++ )
                        {
                                int powerb = 1;

                                for ( i = 0; i < numdigitsab - m - 1; i++ )
                                {
                                        powerb *= 10;
                                }

                                accountNumberTo += tmpab[m] * powerb;
                        }

						k++;
						if ( buff[k] == '$' )
						{
							i = 0;
							k++;
							while ( buff[k] != '.' )
							{
								int ibuff = buff[k] - '0';
								tmpbalancepre[i] = ibuff;
								k++;
								i++;
								numdigitsabpre++;
							}
						}

						for ( m = 0; m < numdigitsabpre; m++ )
						{
							float powerc = 1.00;
							for ( i = 0; i < numdigitsabpre - m - 1; i++ )
							{
								powerc *= 10;
							}
							transferAmount += tmpbalancepre[m] * powerc;
						}

						k++;
						while ( buff[k] != '\n' )
						{
							int ibuff = buff[k] - '0';
							tmpbalancepost[i] = ibuff;
							k++;
							i++;
							numdigitsabpost++;
						}

						transferAmount += tmpbalancepost[0] * .1;
						transferAmount += tmpbalancepost[1] * 0.01;


			}
/*					printf("accountNumberFrom = %d\n", accountNumberFrom);
					printf("accountNumberTo = %d\n", accountNumberTo);
					printf("transferAmount = %f\n", transferAmount);

					printList(start);

*/					transfer( start, accountNumberFrom, accountNumberTo, transferAmount);

//					printList(start);

//					fgets(buff, 100, stdin);

		}
		}   while ( fgets( buff, 100, stdin) != NULL );


		printOrder(start);
//		printList(start);

        return 0;
	}
