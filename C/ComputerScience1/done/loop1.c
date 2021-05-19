#include <stdio.h>

int main()
{
	int n, cond;
	n = 1;
	cond = 19;

	while ( n <= cond)
	{
		if ( n % 2 == 1 )
		{
			printf("%d", n);

			if ( n < cond )
				printf(", ");
			else
				printf("\n");
		}
		n = n + 1;
	}

	return 0;
}
