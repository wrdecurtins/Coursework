#include "toy.h"

int dig()
{
	int x;
	x = rand() % 10;
	return x;
}

char let()
{
	char c;
	c = rand() % 26;
	c = 'a' + c;
	return c;
}


