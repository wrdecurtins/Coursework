#include <stdio.h>

int main()
{
	int i, n, k;
	int s[20] = {0};
	printf("how high: ");
	scanf("%d", &n);

	//#pragma omp parallel for lastprivate(i)
	#pragma omp parallel for 
	for (i=0; i<=n; i++)
	{
		int j;
		for (j = 0; j <= i; ++j)
			s[i] = s[i] + j;
	}

	printf("End:  i %d\n", i);
	for (k = 0; k <= n; ++k)
		printf("%2d: %3d\n", k, s[k]);

	return 0;
}	

