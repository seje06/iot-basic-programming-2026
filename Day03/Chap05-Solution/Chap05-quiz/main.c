#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



void Pyramid(int height,int isReverse, int spaceCount) // 몰래 함수 쓰기
{
	if (height <= 0) printf("잘못된 높이 입력;;\n");

	int width = 2 * height - 1;

	int i = isReverse ? height : -1;
	do
	{

		if (isReverse)
		{
			i--;
			if (i < 0) break;
		}
		else
		{
			i++;
			if (i >= height) break;
		}

		for (int k = 0; k < spaceCount; k++) printf(" ");
		for (int j = 0; j < width; j++)
		{
			if (j >= width - height - i && j <= width - height + i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");

	} while (1);
}

int main()
{
	int n = 11;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || n - i - 1 == j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}




	int height;
	int isReverse;
	printf("피라미드 높이와 역피라미드인지(1 == true, 0 == false)를 입력하시오.\n");
	scanf(" %d %d", &height, &isReverse);
	Pyramid(height, isReverse,0);

	printf("다이아몬드 만들기\n");
	Pyramid(height, 0,0);
	Pyramid(height-1, 1,1);

	return 0;
}