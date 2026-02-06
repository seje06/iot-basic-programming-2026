// 문자 입력 실수
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char ch1, ch2;

	//scanf(" %c%c", &ch1, &ch2); // a엔터를 치면, ch = 'a', ch2 = '\n'
	/*scanf(" %c %c", &ch1, &ch2);
	printf("[%c%c]\n", ch1, ch2);*/

	// getchar(), putchar() 함수로 글자 하나를 입력, 출력
	// 주석변환1 ctrl + /
	// 주석변환2 ctrl + k, c
	// 주석해제 ctrl + k, u
	//ch1 = getchar();  // getchar()는 앞선 입력의 \n도 들어갈 수 있음!!
	//printf("입력값 -> ");
	//putchar(ch1);

	int num, grade; //학번, 학점

	printf("학번 입력 : ");
	scanf("%d", &num); // 학번입력
	getchar(); //키보드 버퍼의 내용은 읽어옴. 그냥 사라짐. buffer clear-> \n만 지움 엔터에 대한 해결만 하는것
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c\n", num, grade);

	return 0;
}