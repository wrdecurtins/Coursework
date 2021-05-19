/*###########################################

***Answers and Timing***************

--mass1.dat--
Total Fuel F = 10
real 0m2.002s
user 0m0.002s
sys 0m0.000s

--mass2.dat--
Total Fuel F = 597
real    0m8.003s
user    0m0.000s
sys     0m0.003s

--gg--
Total Fuel F = 14991
real    0m50.008s
user    0m0.001s
sys     0m0.003s

--hh--
Total Fuel F = 546321
real    8m3.052s
user    0m0.001s
sys     0m0.010s

***Code Explanation***************
This program reads the integers from an input file to populate
array M while keeping track of the total number of integers
inputed in N. Then for each element in M we call the findF
function which will return the amount of fuel that M value
need and adds that to the totalF variable, which holds the
running total of fuel. After the total fuel is calculated we
figure out how many 100's are in totalF by subtracting 100
until totalF is less than 100 and counting each time. Then we
add 110 multiplied by the number of 100's to replace what we
subtracted and add 10 extra per 100. Then we have our final
value so we print it and exit.

###########################################*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define MAXN 10000

int findF( int M );

int main( int argc, char ** argv)
{
	FILE *fptr;
	char filename[20];
	int F, k, getM;
	int N;
	int totalF = 0;
	int countHundreds = 0;
	int M[MAXN] = {0};

	sscanf(argv[1], "%s", &filename);

	fptr = fopen(filename,"r");

	if (fptr == NULL)
	{
		printf("Invalid file\n");
		exit(0);
	}

	fscanf(fptr, "%i", &getM);
	while( !feof (fptr) )
	{
		M[N] = getM;
		N++;
//		printf("get %d\n",getM);
		fscanf(fptr, "%i", &getM);
	}
	fclose(fptr);

	for ( k = 0; k < N; k++ )
	{
		sleep(1);
		F = findF(M[k]);
		totalF += F;
//		printf("%d: F = %d\n",k,F);
	}

	while ( totalF > 100 )
	{
		totalF -= 100;
		countHundreds++;
	}

	totalF += (110 * countHundreds);

	printf("Total Fuel F = %d\n",totalF);

	return 0;
}

int findF( int M )
{
	double F;

	if ( M == 0 )
		return 1;

	F = (((double) M)/4) - 3;

	if ( F < 1 )
		return 1;

	return floor(F);
}
