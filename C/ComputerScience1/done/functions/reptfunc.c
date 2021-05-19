#include <stdio.h>

void rept( int many, char sym )
{
	int k, c;

	for ( k = 0; k < many; k++ )
	{
		for ( c = 0; c < many; c++ )
			printf("%c", sym);
		printf("\n");
	}

}


int main()
{
	int many;
	char sym;

	printf("what symbol?: ");
	scanf("%c", &sym);

	printf("how many?: ");
	scanf("%i", &many);

	printf("\n\n");

	rept(many, sym);

	printf("\n\n");

	return 0;
}
