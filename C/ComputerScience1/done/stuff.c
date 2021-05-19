#include <stdio.h>

int main()
{
	int sid[5];
	int ex1[5], ex2[5], ex3[5];
	int k, max = 0;


	for ( k = 0; k < 5; k++ )
	{
		scanf("%d", &sid[k]);
		scanf("%d", &ex1[k]);
		scanf("%d", &ex2[k]);
		scanf("%d", &ex3[k]);
	}

	for ( k =0; k < 5; k++ )
	{
		printf("Student %4d : %2d %2d %2d\n", sid[k], ex1[k], ex2[k], ex3[k]);
	}

	// high score on test 3

	for ( k = 0; k < 5; ++k )
	{
		if ( ex3[k] > max )
			max = ex3[k];
	}

	printf("The highest score on test 3: %2d\n", max);

	// find grade for each student

	int ssum;
	float savg;
	char letter;

	for ( k = 0; k < 5; k++ )
	{
		ssum = ex1[k] + ex2[k] + ex3[k];
		savg = ssum / 60.0 * 100;

		if ( savg >= 90 )
			letter = 'A';
		else if ( savg >= 80 )
			letter = 'B';
		else if ( savg >= 70 )
			letter = 'C';
		else if ( savg >= 60 )
			letter = 'D';
		else
			letter = 'F';

		printf("student %4d has grade %.1f %c\n", sid[k], savg, letter);
	}

	return 0;
}
