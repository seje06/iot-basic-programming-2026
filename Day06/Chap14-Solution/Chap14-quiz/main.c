// 14장 3번 퀴즈

#include <stdio.h>

int main(void)
{
	char mark[5][5] = { 0 };
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			//if (i == j || i + j == 4) mark[i][j] = 'X';
			if (!(j == 0 && i == 0) && !(i == 4 && j == 4) && !(i == 4 && j == 0) && !(i == 0 && j == 4) && ((i == 0 || j == 0) || (i == 4 || j == 4))) mark[i][j] = 'X';
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (mark[i][j] != 0)
			{
				printf("[%c]", mark[i][j]);
			}
			else
			{
				printf("[ ]");
			}
		}
		printf("\n");
	}
}