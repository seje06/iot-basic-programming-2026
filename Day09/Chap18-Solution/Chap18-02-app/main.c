// 파일 입출력2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h> // OS관련 또는 코드페이지 인코딩 해결

int main(void)
{
	//콘솔출력, 입력을 UTF-8(65001)로 고정설정
	SetConsoleOutputCP(65001); // 콘솔출력 코드페이지
	SetConsoleCP(65001); // 콘솔자체 코드페이지

	FILE* ifp, * ofp;

	// 텍스트 내 포맷에 맞춰서 변수 선언
	char name[20];
	int kor, eng, math; //국, 영, 수 점수
	int total;
	double avg;
	int res;
	char str[256];

	ifp = fopen("original.txt", "r"); // r모드는 파일이 없으면 실패
	if (ifp == NULL)
	{
		printf(u8"입력 파일 오픈 실패!\n");
		exit(1);
	}

	ofp = fopen("./copy.txt", "w");// w쓰기 모드는 파일이 없으면 파일 생성
	if (ofp == NULL)
	{
		printf(u8"출력 파일 생성 실패!\n");
		exit(1);
	}

	// 입력 파일포인터에서 읽어서 한줄씩 각 변수에 할당
	while (fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math) != EOF)
	{
		total = kor + eng + math;
		avg = total / 3.0;

		printf(u8"%s%5d%7.1lf\n", name, total, avg); // 콘솔에 출력
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}

	printf(u8"파일 복사 완료\n");

	fclose(ifp);
	fclose(ofp);
	return 0;
}