#include <stdio.h>
#include <stdlib.h>

#define RN 25
#define LL 20

void listStat( int L[], int N, int *max, int *min, float *avg );

int main()

{
	int k, A[LL], max, min;
	float avg;

	for ( k = 0; k < LL; k++ )
	{
		A[k] = rand() % RN + 1;
		printf("%d ", A[k]);
	}
	printf("\n");

	listStat( A, LL, &max, &min, &avg );

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	printf("Avg: %.2f\n", avg);

	return 0;
}

void listStat( int L[], int N, int *max, int *min, float *avg )
{
	int k, sum;

	*max = L[0];
	*min = L[0];
	sum = 0;

	for ( k = 0; k < N; k++ )
	{
		if ( L[k] > *max )
			*max = L[k];
		if ( L[k] < *min )
			*min = L[k];

		sum += L[k];
	}
	*avg = 1.0 * sum / N;

}
