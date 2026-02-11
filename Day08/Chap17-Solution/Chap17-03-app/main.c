
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
	int age;
	double height;
};

struct student
{
	int id; //
	double grade;
	struct profile pf;
};

int main(void)
{
	struct student st1 = { 2,1.2,{2,2.3} };

	st1.id = 9537;
	st1.grade = 4.1;
	st1.pf.age = 25;
	st1.pf.height = 173.0;

	// 출력
	printf("학번 : %d\n", st1.id);
	printf("학점 : %.1f\n", st1.grade);
	printf("나이 : %d\n", st1.pf.age);
	printf("키 : %.1f\n", st1.pf.height);

	return 0;
}