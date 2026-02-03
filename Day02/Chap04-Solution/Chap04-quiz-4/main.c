#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	float height;
	float weight;
	
	float bmi;

	printf("키와 몸무게를 입력하시오.\n");
	scanf(" %f %f", &height, &weight);

	bmi = weight / ((height/100) * (height / 100));

	printf("BMI : %.1f %s\n", bmi, (bmi >= 20 && bmi < 25)? "정상":"비정상");
	return 0;
}