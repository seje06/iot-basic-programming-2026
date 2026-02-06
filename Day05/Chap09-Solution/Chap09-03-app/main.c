// 포인터 크기

#include <stdio.h>

int main(void)
{
	char ch; // 문자형 변수
	int in; // 정수형 변수
	double db; // 실수형 변수

	// 선언 및 초기화
	char* pch = &ch;
	int* pin = &in;
	double* pdb = &db;

	// 주소크기 출력
	// 윈도우가 64비트 => 8 * 8bit = 64bit
	printf("char 형 변수 주소 크기 : %zu bytes\n", sizeof(&ch)); // 8
	printf("int 형 변수 주소 크기 : %zu bytes\n", sizeof(&in)); // 8
	printf("double 형 변수 주소 크기 : %zu bytes\n", sizeof(&db)); // 8

	//포인터 크기
	printf("char 형 *변수 주소 크기 : %zu bytes\n", sizeof(pch));
	printf("int 형 *변수 주소 크기 : %zu bytes\n", sizeof(pin));
	printf("double 형 *변수 주소 크기 : %zu bytes\n", sizeof(pdb));

	//포인터가 가리키는 변수 크기
	printf("char 형 * 가리키는 변수 주소 크기 : %zu bytes\n", sizeof(*pch));
	printf("int 형 * 가리키는 변수 주소 크기 : %zu bytes\n", sizeof(*pin));
	printf("double 형 * 가리키는 변수 주소 크기 : %zu bytes\n", sizeof(*pdb));
}