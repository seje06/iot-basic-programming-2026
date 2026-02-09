// 다차원 배열

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	//int score[3][4];
	int score[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int total;
	double avg;

	char animal[5][20]; // 동물 5마리, 이름길이 20
	int count;

	int i, j; //2중 for문 변수

	//2차원 배열로 동물 이름 관리

	count = sizeof(animal) / sizeof(animal[0]);
	printf("%5d\n", count);
	for (i = 0; i < count; i++)
	{
		scanf("%s", animal[i]); // 만약 animal[i][j]라면 &animal[i][j] 
	}

	for (i = 0; i < count; i++)
	{
		printf("%d번 동물 %s", i, animal[i]);
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("%d번 학생, 4과목 점수 입력 : ", i);
		for (j = 0; j < 4; j++)
		{
			scanf( " %d", &score[i][j]); // 점수 입력 (앞쪽[]는 행 바깥쪽 for문 변수, 뒤쪽[]열 안쪽 for문 변수)
		}
	}

	//점수 채점

	for (i = 0; i < 3; i++)
	{
		total = 0;
		for (j = 0; j < 4; j++)
		{
			total += score[i][j];
		}
		avg = total / 4.0;

		printf("%d번 학생, 총점 : %d, 평균 : %.1lf\n", i, total, avg);
	}

	return 0;
}