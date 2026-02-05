#include <stdio.h>

int main()
{
	//int kor, math, eng, social, sciencel; // 5과목 점수 저장변수
	int ary[5];    // 크기 5인 정수형 배열 생성
	int ary2[] = { 1,2,3,4 }; // 배열 초기화로 배열 크기를 자동지정
	int tot = 0; // 5과목 총점
	int i;
	int avg;

	ary[0] = 90;// 국어 점수
	ary[1] = 85;// 수학 점수
	ary[2] = 70;// 영어 점수
	ary[3] = 95;// 사회 점수
	ary[4] = 100;//과학 점수

	printf("국어 점수 : %d\n", ary[0]);
	printf("수학 점수 : %d\n", ary[1]);
	printf("영어 점수 : %d\n", ary[2]);
	printf("사회 점수 : %d\n", ary[3]);
	printf("과학 점수 : %d\n", ary[4]);

	//tot = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];

	for (i = 0; i < 5; i++) //반복문 사용하라
	{
		tot += ary[i];
	}

	printf("총점은 %d\n", tot);

	avg = tot / 5.0;
	printf("평균운 %.1f\n", avg);

	return 0;
}