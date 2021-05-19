#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N  10 

int main()
{
 int A[N];
 int i, j, tmp;
 int swp;

 //srand( time(NULL) );
 
 for (i = 0; i < N; ++i)
   A[i] = rand() % 50 + 1;     // random val in range 1 to 50


 for (i = 0; i < N; ++i)
   printf("%2d ", A[i]);
 printf("\n");

 swp = 0;
 for (i = 0; i < N; ++i)
 {
  for (j = 0; j < N-1; ++j)
  //for (j = 0; j < N-(i+1); ++j)
  {
   swp++;
   if (A[j] > A[j+1])
   {
    tmp = A[j];
    A[j] = A[j+1];
    A[j+1] = tmp;
   } 
  }

  printf("%2d: ", i);
  for (j = 0; j < N; ++j)
    printf("%2d ", A[j]);
  printf("\n");
 }

 for (i = 0; i < N; ++i)
   printf("%2d ", A[i]);
 printf("\n");

 printf("%d swaps\n", swp);

 return 0;
}
