// void 포인터

#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.5;

	void* vp; // void 포인터
	int* pa;

	vp = &a;
	printf("a : %d \n", *(int*)(vp));

	vp =&b;
	printf("d : %.1lf \n", *(double*)(vp)); // vp를 double*로 변경후 사용. 형변환을 뺄 수 없음(에러!)

	pa = vp; // 대입연산에서는 형변환을 안써도 오류x. 단 명시적으로 형변환 추가해 줄것
	printf("pa : %.1lf\n", *(double*)pa);


	return 0;
}