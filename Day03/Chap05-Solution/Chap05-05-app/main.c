// 구구단 프로그램

#include<stdio.h>

int main()
{
	int i, j;

	for (j = 1; j <= 9; j++)
	{
		printf("구구단 %d\n",j);
		for (i = 1; i <= 9; i++)
		{
			printf("%d * %d = %2d\t", j, i, j * i);
		}
		printf("\n");
	}
}