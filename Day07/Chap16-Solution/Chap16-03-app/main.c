// 나머지 동적할당 함수

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi = NULL;
	int size = 5;
	int count = 0;
	int num, i;

	// calloc : Coninuos ALLOCation(연속된 메모리 할당)
	pi = (int*)calloc(size, sizeof(int)); //20byte로 저장공간(5칸)  // 공간을 전부 0(calloc만)으로 초기화 // malloc으로 해도됨 ex) malloc(size * sizeof(int))
	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf(" %d", &num);
		if (num <= 0)
		{
			break; // 양수 입력 중지
		}

		if (count == size) // 초기상태(5) 크기를 다 사용했으면
		{
			size += 5;
			//realloc : RE-ALLOCation(메모리 다시할당)
			pi = (int*)realloc(pi, size * sizeof(int)); // 40byte 로 저장공간 늘림
		}

		pi[count++] = num;
	}

	// 음수 0을 넣어서 입력을 종료하면
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}

	free(pi); // 동적할당 공간 os에게 반납

	return 0;
}