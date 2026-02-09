// 이중 포인터

#include <stdio.h>

int main(void)
{
	int a = 10; // 실제 값
	int* pi =&a; // 포인터
	int** ppi = &pi; // 이중포인터

	printf("--------------------------------------------------\n");
	printf("변수      변수값    &연산     *연산     **연산    \n");
	printf("--------------------------------------------------\n");

	printf("  a%12d%12u\n", a, &a);
	printf(" pi%12u%12u%12d\n", pi, &pi,*pi);
	printf("ppi%12u%12u%12u%12d\n", ppi, &ppi, *ppi, **ppi);

	return 0;
}