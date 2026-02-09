// 값 복사 전달 & 주소 복사
// 리턴값을 포인터 변수로 받기

#include <stdio.h>

int add_ten(int);

void plus_ten(int*);

int* sum(int, int); // 매개변수는 일반변수, 리턴은 포인터변수

int main(void)
{
	int a = 100;
	int* result; //주소를 받는다

	a = add_ten(a);
	printf("a=%d\n", a);

	plus_ten(&a);
	printf("a=%d\n", a);

	result = sum(40, 60); // 정적변수 res의 주소를 돌려받음.
	printf("*result = : %d\n", *result);

	return 0;
}

int* sum(int a, int b)
{
	static int res; // 정적 지역변수. static을 써서 sum함수가 끝나도 변수가 살아있도록 하겠다는 의미

	res = a + b;

	return &res; // 정적변수의 주소를 반환
}


//void add_ten(int num)
//{
//	num = num + 10;
//}

int add_ten(int num)
{
	num = num + 10;
	
	return num;
}

void plus_ten(int* pa)
{
	*pa = *pa + 10;
}

