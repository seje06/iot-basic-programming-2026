// 메모리 동적 할당

#include <stdio.h> // 표준 입출력
#include <stdlib.h> // 표준 라이브러리

int main(void)
{
	// NULL - 아무것도 가리키지 않는 포인터값
	// 안전한 초기화를 위해서
	// 포인터 처리가 없음을 나타내기 위해서
	// NULL != 0
	// NULL은 안전하다
	// 실무에서 가장 많이나는 예외 HULL Pointer Exception
	int* pi = NULL; // 아무것도 가리키고 있지 않다
	double* pd = NULL; 

	// malloc : memory allocation(메모리 할당)
	pi = (int*)malloc(sizeof(int));  // 1. 메모리 동적 할당 후 포인터와 연결

	if (pi == NULL)
	{
		printf("# 메모리가 할당되지 않았습니다.\n");
		exit(1); // 에러발생(1) 리턴후 프로그램 종료
	}
	pd = (double*)malloc(sizeof(double)); // 1. 8byte 메모리 생성

	*pi = 10;	// 메모리 주소 어딘가에 동적으로 int 할당한 곳에 값을 10집어 대입하라
	*pd = 3.4;

	printf("정수형 : %d\n", *pi);
	printf("실수형 : %.1f\n", *pd);

	free(pi); // 2. 메모리를 동적할당한 것은 종료직전 무조건 free로 메모리를 반환!
	free(pd);

	return 0; // 에러없이(0) 종료
}