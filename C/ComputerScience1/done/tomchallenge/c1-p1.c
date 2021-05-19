#include <stdio.h>
int main()
{
	int num, k, u;
	char a = '@';
	for ( k = 1; k <= 100; k++ )
	{
		int quit = scanf("%d", &num);

		if ( quit != 1 )
		{
			printf("\n");
			return 0;
		}
		else
		{
			printf("%d: ", k);
			for ( u = 0; u < num; u++ )
				printf("%c", a);
			printf("\n");
		}
	}
	return 0;
}
