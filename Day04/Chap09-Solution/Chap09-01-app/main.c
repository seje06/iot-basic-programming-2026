// 포인터 이전 로컬변수, 변수스코프

#include <stdio.h>

int x = 10;

void func(void);

void add(int); // 매개변수 값을 100 더하는 함수

int main()
{
	int x = 30;
	printf("main x = %d\n", x);
	func();
	printf("main x = %d\n", x);
	// 여기까지 기본 변수 스코프

	// 블록 스코프
	int a = 1;

	if (a == 1)
	{
		int b = 2;
		printf("블록 내부 : a = %d, b = %d", a, b);
	}

	printf("블록 외부 : a = %d", a);
	//printf("b = %d\n", b); //블록 내부에서 선언한 변수 b는 블록 밖에서 사용불가!!! 컴파일 에러

	//함수 스코프
	int y = 10;
	add(y);

	printf("y=%d\n", y);

	return 0;
}

void add(int x)
{
	x = x + 100;
}

void func(void)
{
	int x = 20;

	printf("func x = %d\n", x);
}