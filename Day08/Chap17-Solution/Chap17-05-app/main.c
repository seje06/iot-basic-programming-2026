// 공용체(Union)
// 구조체와 유사. 하나의 저장공간을 같이 사용
// 메모리용량을 완전 최적화(절약) 할때 사용
// 멤버변수끼리 데이터 충돌!

// 열거형(enumeration)
// 변수에 저장하는 정수값을 기호로 대체, 나열

#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER};

// struct student 16byte 사용
union student
{
	char ch1;
	int num;
	double grade;
	char name[10]; // 20byte, 8byte 배수로 크기를 잡고, 패팅바이트를 채움
};

int main(void)
{
	union student st1 = {.num = 315};
	printf("공용체 사이즈 %zu\n", sizeof(st1));

	printf("학번 : %d\n", st1.num);
	st1.grade = 4.4;
	printf("학점 : %.1f\n", st1.grade);
	printf("학번 : %d\n", st1.num);

	enum season ss;
	char* pc = NULL;

	ss = SPRING;
	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "tracking";
		break;
	case WINTER:
		pc = "skiing";
		break;
	}

	return 0;
}