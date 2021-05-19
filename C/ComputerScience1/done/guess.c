#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int secret, guess = -1;

	srand( time( NULL ) );

	secret = rand() % 20 + 1;
//	printf("Hidden number: %d\n", secret);

	while ( guess != secret )
	{
		printf("Guess a number between 1-20: ");
		scanf("%d", &guess);
		if ( guess < secret )
			printf("Too low try again\n");
		if ( guess > secret )
			printf("Too high try again\n");
	}

	printf("You did a good and got the number!!!\n");
	return 0;
}
