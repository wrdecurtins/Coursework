#include <stdio.h>

int fun( int x )
{
	int val, k;
	val = 0;
	for ( k = 0 ; k < x ; k++ )
	{
		val = val + x;
	}
	return 5;
}

int main()
{
	int ans;

	printf("hi\n");
	ans = fun(7);
	printf("Result is %d\n", ans);

	return 0;
}
