#include <stdio.h>

int main()
{
	int NR, NC, k, u, box[20][20], ArraySize = 20;

	scanf("%d", &NR);
	scanf("%d", &NC);

	for ( u = 0; u < ArraySize; u++ )
		for ( k = 0; k < ArraySize; k++ )
			box[u][k] = 0;

	for ( u = 1; u <= NR; u++ )
		for ( k = 1; k <= NC; k++ )
			scanf("%d", &box[u][k]);

	for ( u = 1; u <= NR; u++ )
	{
		for ( k = 1; k <= NC; k++ )
		{
			int nValue = 0;
			nValue = ( box[u-1][k-1] + box[u-1][k] + box[u-1][k+1] + box[u][k-1] + box[u][k+1] + box[u+1][k-1] + box[u+1][k] + box[u+1][k+1] );

			if ( nValue < 10 )
				printf("^");
			else
				printf("#");
		}
		printf("\n");
	}

	return 0;
}
