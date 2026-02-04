// switch~case 문
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	printf("switch~case 문 예제\n");

	int rank = 0, money = 0; //  변수 선언, 초기화
	printf("등수를 입력하세요\n");
	scanf(" %d", &rank);
	
	//switch (rank)
	//{
	//case 1: // 1등 이면
	//	money = 1000; //1000만원
	//	break;	//switch문을 탈출. 주의!! break문을 빼면 아래의 로직도 실행!!
	//case 2:
	//	money = 500;
	//	break;
	//case 3:
	//	money = 200;
	//	break;
	//case 4:
	//	money = 50;
	//	break;
	//default:	// if문으로 보자면 else
	//	money = 10;
	//	break;
	//}

	if (rank == 1)
	{
		money = 1000;
	}
	else if (rank == 2)
	{
		money = 500;
	}
	else if (rank == 3)
	{
		money = 200;
	}
	else if (rank == 4)
	{
		money = 50;
	}
	else
	{
		money = 10;
	}
	printf("%d등 당첨금 %d만원에 당첨되셨습니다.\a\n", rank, money);

	return 0;
}