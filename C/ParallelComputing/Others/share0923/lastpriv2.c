#include <stdio.h>

int main()
{
	int i, n, k;
	int s[20] = {0};
	printf("how high: ");
	scanf("%d", &n);
	int x = 100;
	//#pragma omp parallel for private(x) 
	#pragma omp parallel for lastprivate(x) 
	for (i=0; i<=n; i++)
	{
		x = i * 2;
		int j;
		for (j = 0; j <= i; ++j)
			s[i] = s[i] + j;
	}

	printf("End:  i %d\n", i);
	printf("End:  x %d\n", x);
	for (k = 0; k <= n; ++k)
		printf("%2d: %3d\n", k, s[k]);

	return 0;
}	

