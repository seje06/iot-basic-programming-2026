// fflush 예제
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

int main(void)
{
	int i;
	printf("작업 진행");
	FILE* fp;

	fp = fopen("temp.txt", "a+");

	for (i = 0; i < 10; i++)
	{
		fputs("dwd", fp);
		
		Sleep(100); //0.5초씩 대기
	}
	fflush(fp); // 현재 버퍼에 담은 데이터를 한꺼번에 내려보낸다.

	fclose(fp);
	printf("완료!");

	return 0;
}