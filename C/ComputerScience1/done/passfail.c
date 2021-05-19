#include <stdio.h>

int main()
{
	int pts;

	printf("Enter your score (0-100): \n");
	scanf("%d", &pts);

	printf("Your score is %d\n", pts);

	if ( pts <= 60 )
	{
		printf("Sorry but that is a failing score\n");
	}
	else
	{
		printf("Your score is a pass\n");
	}

	return 0;
}
