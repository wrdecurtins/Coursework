#include <stdio.h>

int main()
{
	FILE *fileout;
	int num1, num2;

	fileout = fopen( "myout", "w" );
	printf("Type in a number: ");
	scanf("%d", &num1);

	printf("Value stored to file named myout\n");
	fprintf(fileout, "User number %d\n", num1);


	return 0;
}
