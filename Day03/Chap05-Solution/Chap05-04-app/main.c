// for문

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a = 1;
	int i; // 반복문을 위한 변수

	/*
	* for(초기값; 조건식; 증감식)
	* {
	*	반복 실행할 코드;
	* }
	*/

	for (i = 0; i < 5; i++)
	{
		a *= 2;
	}
	printf("a : %d\n", a); // for문을 빠져나온 뒤 a값 콘솔출력

	//$를 열번 출력
	for (i = 0; i < 10; i++)
	{
		printf("%c",'$'); // printf("$"), printf("%s", "$")
	}
	printf("\n");

	int j = 0;
	// 이중 for문
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}

	return 0;
}