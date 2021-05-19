#include <stdio.h>

int main()
{
	int num;
	printf("What is your number?:");
	scanf("%d", num);

	if ( num >= 13 && num <= 19)
		printf("The num is a teen");
	else
		printf("the num is not a teen");

	return 0;
}
