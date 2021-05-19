#include <stdio.h>
#include <string.h>

int main()
{
	char input[1], w[1] = "w", a[1] = "a", s[1] = "s", d[1] = "d", q[1] = "q";
//	int input, w, a, s, d, q;

	while ( strcmp(input, q) != 0 )
	{
		scanf("%d", input);
		if ( strcmp(input, "w") == 0 )
			printf("up\n");
		if ( strcmp(input, a) == 0 )
			printf("left\n");
		if ( strcmp(input, s) == 0 )
			printf("down\n");
		if ( strcmp(input, d) == 0 )
			printf("right\n");
	}

	return 0;
}
