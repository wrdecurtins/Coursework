#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100

int fiboMemoArray[MAXN] = {0};

int fiboNaive( int n );
int fiboMemo( int n );

int main()
{
        int n, ans;
        printf("n = ");
        scanf("%d", &n);

        clock_t t;
        t = clock();
        ans = fiboNaive(n);
        t = clock() - t;
        double time = ((double)t)/(CLOCKS_PER_SEC/1000);

        printf("fiboNaive of n = %d:%5d\n", n, fiboNaive(n));
        printf("fiboNaive ran for %5.3f milliseconds\n\n", time);

        t = clock();
        ans = fiboMemo(n);
        t = clock() - t;
        double time2 = ((double)t)/(CLOCKS_PER_SEC/1000);

        printf("fiboMemo  of n = %d:%5d\n", n, fiboMemo(n));
        printf("fiboMemo  ran for %5.3f milliseconds\n", time2);

        return 0;
}

int fiboMemo( int n )
{
        if ( n <= 0 )
                return 0;
        if ( n == 1 )
                return 1;

        if ( fiboMemoArray[n] != 0 )
                return fiboMemoArray[n];

        fiboMemoArray[n] = fiboMemo( n - 1 ) + fiboMemo( n - 2 );

        return fiboMemoArray[n];
}


int fiboNaive( int n )
{
        if ( n <= 0 )
                return 0;
        if ( n == 1 )
                return 1;

        return fiboNaive( n - 1 ) + fiboNaive( n - 2 );
}
