//break를 사용한 반복문 종료
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	int i;
	int sum = 0;

	for (i = 1; i < 10; i++)
	{
		sum += i;
		if (sum > 30)
		{
			break;
		}
	}

	printf("누적합 : %d\n", sum);
	printf("마지막으로 더한값 : %d\n",i);


	return 0;
}