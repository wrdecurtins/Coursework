#include <stdio.h>

void pbv( int x )
{
 printf("           In pbv: %d\n", x);
 x = 9;
 printf("          Out pbv: %d\n", x);
}

void pbr( int *x )
{
 printf("           In pbr: %d\n", *x);
 *x = 9;
 printf("          Out pbr: %d\n", *x);
}

int main()
{
 int val;

 val = 2;
 printf("Before PBV: %d\n", val);
 pbv( val );
 printf(" After PBV: %d\n", val);

 printf("\n\n");
 val = 2;
 printf("Before PBR: %d\n", val);
 pbr( &val );
 printf(" After PBR: %d\n", val);

 return 0;
}
