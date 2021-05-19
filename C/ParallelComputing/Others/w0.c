#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// must use this function for mod
//  pmath.o
int mymod( int n, int d);

int isPrime( int x )
{
 int i;
 int isprime = 1;

 // fill this in during class
 // naive to more efficient gradually

 if ( x > 2 && mymod(x,2) == 0)
	return 0;

 int end = sqrt(x);

 #pragma omp parallel for num_threads(10) reduction(&&:isprime) schedule(dynamic)
 for ( i = 3; i <= end; i+=2 )
 {
	if ( mymod(x, i)  == 0 )
		isprime = 0;
 }

 return isprime;
}

int main( int argc, char *argv[])
{
 int i, N, isprime = 1;
 int x;

 if (argc != 2)
    return 1;

 N = atoi(argv[1]);

 isprime = isPrime( N );

 printf("Result %s\n", isprime==1?"Yes":"No");
 // print first N primes
	int np = 0;
	i = 2;
	while ( np < N )
	{
		if ( isPrime(i) )
		{
			printf("%d\n", i);
			np++;
		}
		i++;
	}


 // print primes up to N
/*	int np = 0;
	for ( i = 2; i <= N; i++ )
	{
		if ( isPrime(i) )
		{
			printf("%d\n", i);
			np++;
		}
	}
*/
	printf("How many: %d\n", np);

 // how many primes up to N
 // what is the Nth prime

 return 0;
}
