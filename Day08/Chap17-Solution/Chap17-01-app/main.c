// 구조체(Structure)

#include <stdio.h>

#pragma pack(1)
struct student
{
	char ch1;
	short num;
	char ch2;
	int score;	// 4byte
	double grade; // 8byte
	char ch3;
};

int main(void)
{
	struct student st1;

	printf("구조체 student 크기 : %zu\n", sizeof(st1)); // 실제 사용되는 바이트는 12바이트 하지만, 패딩바이트로 16byte로 구성
	// 구조체에 선언하는 멤버변수의 위치만 조정해도 패딩바이트가 사라짐 -> 24byte


	return 0;
}