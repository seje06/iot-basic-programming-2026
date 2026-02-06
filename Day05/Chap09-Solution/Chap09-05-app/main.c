// 포인터 사용이유

#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
	int a = 10, b = 20;

	printf("원본 a, b = %d, %d\n", a, b);

	swap(&a, &b);

	printf("변경후 a, b = %d, %d\n", a, b);

	return 0;
}


void swap(int* pa, int* pb)
{
	int temp; // 교환을 위한 임시 변수

	temp = *pa; //temp = 10
	*pa = *pb;
	*pb = temp;
}