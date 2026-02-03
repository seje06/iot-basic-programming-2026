#include <stdio.h>


int main()
{
	int res;

	int shortSize = sizeof(short);
	int longSize = sizeof(long);

	res = (shortSize > longSize) ? shortSize : longSize;

	printf("%s\n", (res == shortSize) ? "short" : "long");

	return 0;
}