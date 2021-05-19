#include <stdio.h>

int main()
{
	int orignum, nextnum, doublenum;

	printf("Pls enter a num:");

	scanf("%d", &orignum);

	nextnum = orignum + 1;

	doublenum = orignum * 2;

	printf("The next num is %d and the orignum doubled is %d\n", nextnum, doublenum);

	return 0;
}
