#include <stdio.h>
#include <stdlib.h>

#define mid 7500
#define red 1
#define yellow 0
#define outofbounds 42250000
int main( int argc, char *argv[] )
{
	int dist[2][9][5], color, roundnum, stone, x, y, k, h;
	int score[2][9] = {0};
	FILE *fp;

	fp = fopen( argv[1], "r" );

	if ( fp == NULL )
	{
		printf("File %s does not exist\n", argv[1] );
		exit(1);
	}

	//section reads the file and assigns a distance to each stone

	for( k = 1; k < 9; k++ )
	{
		fscanf(fp, "%d", &roundnum);

		for ( stone = 0; stone < 5; stone++ )
		{
			fscanf(fp, "%d %d", &x, &y);

			if ( (x == -1) || (((mid - x) * (mid - x) + (mid - y) * (mid - y)) > outofbounds) )
				dist[red][roundnum][stone] = -1;
			else
				dist[red][roundnum][stone] = ((mid - x) *  (mid - x) + (mid - y) * (mid - y));
		}

		for ( stone = 0; stone < 5; stone++ )
		{
			fscanf(fp, "%d %d", &x, &y);

			if ( (x == -1) || (((mid - x) * (mid - x) + (mid - y) * (mid - y)) > outofbounds) )
				dist[yellow][roundnum][stone] = -1;
			else
				dist[yellow][roundnum][stone] = ((mid - x) * (mid - x) + (mid - y) * (mid - y));
		}
	}

	int lowestY = 56250001, lowestR = 56250001, lowestA[2] = {56250001, 56250001}, points = 0, totalpoints[2] = {0};


	//section computes and stores the score into an arry
	for( roundnum = 1; roundnum < 9; roundnum++ )
	{
		for( color = 0; color < 2; color++ )
		{
			for( stone = 0; stone < 5; stone++ )
			{
				if( (color == red) && (dist[color][roundnum][stone] < lowestR) && (dist[color][roundnum][stone] >= 0) )
					lowestR = dist[color][roundnum][stone];
				if( (color == yellow) && (dist[color][roundnum][stone] < lowestY) && (dist[color][roundnum][stone] >= 0) )
					lowestY = dist[color][roundnum][stone];
				if( (dist[color][roundnum][stone] < lowestA[color]) && (dist[color][roundnum][stone] >= 0) )
					lowestA[color] = dist[color][roundnum][stone];
			}
		}
		if( lowestR == lowestY )
		{
			if( roundnum % 2 == 0 )
				lowestR = outofbounds + 1;
			if( roundnum % 2 == 1 )
				lowestY = outofbounds + 1;
		}


		if( (lowestR < lowestY) || ((lowestR == lowestY) && (roundnum % 2 == 1) ))
		{

			points = 0;
			for( stone = 0; stone < 5; stone++ )
				if( (dist[red][roundnum][stone] <= lowestY) && (dist[red][roundnum][stone] != -1) )
					points++;
			score[red][roundnum] = points;
		}

		if( (lowestY < lowestR) || ((lowestY == lowestR) && (roundnum % 2 == 0)) )
		{
			points = 0;
			for( stone = 0; stone < 5; stone++ )
				if( (dist[yellow][roundnum][stone] <= lowestR) && (dist[yellow][roundnum][stone] != -1) )
					points++;
			score[yellow][roundnum] = points;
		}
		lowestY = 56250001;
		lowestR = 56250001;
	}

	for( color = 0; color < 2; color++ )
		for( roundnum = 1; roundnum < 9; roundnum++ )
			totalpoints[color] += score[color][roundnum];

	//section prints the output to the user

	printf("\n");
	printf("Scores by round:\n");
	for( roundnum = 1; roundnum < 9; roundnum++ )
		printf("%d: Red: %d   Yellow: %d\n", roundnum, score[red][roundnum], score[yellow][roundnum]);
	printf("\n\n");
	printf("Final Score:\n");
	printf("Red: %d  Yellow: %d\n\n", totalpoints[red], totalpoints[yellow]);

	if( totalpoints[red] > totalpoints[yellow] )
		printf("Red Wins the Match!\n\n");

	if( totalpoints[red] < totalpoints[yellow] )
		printf("Yellow Wins the Match!\n\n");

	if( totalpoints[red] == totalpoints[yellow] )
	{
		if( lowestA[red] < lowestA[yellow] )
			printf("Red Wins the Match!\n\n");
		if( lowestA[red] > lowestA[yellow] )
			printf("Yellow Wins the Match!\n\n");
	}

	return 0;
}
