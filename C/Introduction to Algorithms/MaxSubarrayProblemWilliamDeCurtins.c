/* Question 4.1-1 What does FIND-MAXIMUM-SUBARRAY return
        when all elements of A are negative?

        FIND-MAXIMUM-SUBARRAY will return whatever the least negative
        value in the array is when all the numbers are negative because
        adding any of the values together will actually make for a
        smaller sum. For example if the array is A{-1, -50, -2, -32,
        -5} then the returned value will be -1 as it is the greatest
        among these numbers.

  Question 4.1-3 What problem size n gives the crossover point at
    which the recursive algorithm beats the brute force algorithm?
    Then change the base case of the recursive algorithm to use
    the brute-force algorithm whenever the problem size is less
    than n. Does that change the crossover point?

        The approximate n value for which my algorithm's crossover
        point is n = 175. It is an approximation as computers are so
        fast it is difficult to tell exactly when the crossover point
        is in a practical way. I don't know if that really counts as
        changing the crossover point, it is more akin to removing
        the crossover point altogether where we are just using the
        better of the two algorithms in any given situation.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define ARRAYSIZE 20000

void FillArray( int A[] )
{
        int random;
        srand(time(NULL));

        for ( int i = 0; i < ARRAYSIZE; i++ )
        {
                random = rand() % 101 - 50;
                A[i] = random;
        }
}

int BruteForceMaxSubarray( int A[ARRAYSIZE] )
{
        int maxSubarray = INT_MIN;
        for ( int i = 0; i < ARRAYSIZE; i++ )
        {
                int sum = 0;
                for ( int k = 0; k < ARRAYSIZE; k++ )
                {
                        sum = sum + A[k];
                        if ( sum > maxSubarray )
                        {
                                maxSubarray = sum;
                        }
                }
        }
        return maxSubarray;
}

int FindMaxCrossingSubarray( int A[ARRAYSIZE], int low, int mid, int high )
{
        int sum = 0;
        int leftSum = INT_MIN;

        for ( int i = mid; i >= low; i-- )
        {
                sum = sum + A[i];
                if ( sum > leftSum )
                        leftSum = sum;
        }

        sum = 0;
        int rightSum = INT_MIN;

        for ( int j = mid+1; j <= high; j++ )
        {
                sum = sum + A[j];
                if ( sum > rightSum )
                        rightSum = sum;
        }

        sum = leftSum + rightSum;

        return sum;
}

int FindMaximumSubarray( int A[ARRAYSIZE], int low, int high )
{
        int mid = ( low + high ) / 2 ;

        if ( high == low )
                return A[low];

        int leftSum = FindMaximumSubarray( A, low, mid );
        int rightSum = FindMaximumSubarray( A, mid+1, high );
        int crossSum = FindMaxCrossingSubarray( A, low, mid, high );

        if ( leftSum >= rightSum && leftSum >= crossSum )
                return leftSum;
        else if ( rightSum >= leftSum && rightSum >= crossSum )
                return rightSum;
        else
                return crossSum;
}

int main()
{
//      int A[] = {2, 3, 4, 5, 7};
//      int A[] = {-1, -5, -2, -7, -60};
        int A[ARRAYSIZE];

        FillArray( A );

        int maxSubArray;

        if ( ARRAYSIZE < 175 )
                maxSubArray = BruteForceMaxSubarray( A );
        else
                maxSubArray = FindMaximumSubarray( A, 0, ARRAYSIZE-1 );

        printf("Maximum Sum of a Subarray is %d\n", maxSubArray);

        return 0;
}
