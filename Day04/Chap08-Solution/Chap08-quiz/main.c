// 대소문자 변환 프로그램

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char str[80];
	int j = 0;
	int i = 0;
	printf("문자열 입력 : ");
	gets(str); // DON'T Worry, Be Happy

	
	while (str[j] != '\0')
	{
		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			str[j] = (char)((int)str[j] + 32);
			i++;
		}

		j++;
	}
	
	puts(str);
	printf("\n %d", i);
}