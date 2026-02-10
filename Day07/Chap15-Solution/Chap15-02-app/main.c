//함수 포인터 활용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void func(int (*fp)(int, int));

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

// 메인 함수 정의
int main(void)
{
	func(sum);
	func(sub);
	func(mul);
	func(div);

	return 0;
}


void func(int (*fp)(int , int))
{
	int a, b;
	printf("두정수 값을 입력하시오 : ");
	scanf(" %d %d", &a, &b);
	printf ("해당 함수의 결과 : %d\n", fp(a, b));
}

int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}