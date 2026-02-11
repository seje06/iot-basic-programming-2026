// 구조체 포인터 -> 연산자

#include <stdio.h>

struct score
{
	int kor;	//국어점수
	int eng;	//영어점수
	int math;	//수학점수
};

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

// 3. 구조체 배열을 주소로 받아서 출력하는 함수
void print_list(struct address*);

int main(void)
{
	struct score yuni = { 90,80,70 };
	//struct score yuni = { .kor = 90, .eng = 80, .math = 70 };

	struct score* ps = &yuni; // 구조체 포인터에 주소를 저장

	printf("국어 : %d\n", (*ps).kor); // ps->kor 와 동일
	// (*ps). 연산이 복잡함, 이를 단순화 시키는 게 ->
	printf("영어 : %d\n", *((int*)ps + 1));
	printf("수학 : %d\n", *((int*)ps + 2));

	// struct address 구조체 배열
	struct address list[5] = {
		{ "홍길동", 23, "111-1111", "울릉도 독도"},
		{ "이순신", 35, "211-1111", "서울 건천동"},
		{ "장보고", 19, "311-1111", "완도 청해진"},
		{ "유관순", 15, "411-1111", "충남 천안"},
		{ "안중근", 45, "511-1111", "황해도 해주"},
	};

	int i;

	// 2. 출력을 메인함수에서 하면 쉽다!
	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
	print_list(list);

	return 0;
}

// 구조체 배열 포인터를 사용하면
// *(포인터) 연산자로 작업하면 연산이 복잡해짐
// 그래서, 대신 -> 를 사용하는 것
void print_list(struct address* lp)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", lp[i].name, lp[i].age, lp[i].tel, lp[i].addr);
	}
}