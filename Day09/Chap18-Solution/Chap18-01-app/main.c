// 파일 입출력 + 프로그램 실행경로
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <direct.h>
#include <string.h>

int main(void)
{
	char str[256]; // 경로 입력 변수

	_getcwd(str, sizeof(str));
	printf("현재 작업 폴더 : %s\n", str);
	
	FILE* fp, * ofp;

	// 디렉토리, 폴더 구분자로 /를 사용해도 무방
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		exit(1);
	}
	else
	{
		printf("파일 오픈 성공\n");
	}

	// 파일 복사용 오픈
	ofp = fopen("copy.txt", "w");
	if (ofp == NULL) // 실패 방지
	{
		printf("출력파일 열기 실패\n");
		return 1;
	}

	while (fgets(str, sizeof(str), fp) != NULL)
	{
		printf("한줄 쓰기 -> %s", str);
		str[strlen(str) - 1]  ='\0'; // \n -> \0 바꿔줘서
		fputs(str, ofp);
		fputs(" ", ofp); // 한줄 끝난뒤 스페이스 추가
	}

	fclose(ofp);
	fclose(fp);

	return 0;
}