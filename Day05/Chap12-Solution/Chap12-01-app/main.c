
#include <stdio.h>


int main()
{
	const char* ch = "apple";
	const char* ch2 = "apple";
	// 문자열 출력
	printf("%s\n", "apple");
	
	// 문자열 주소확인
	printf("%zu\n", "apple");
	printf("%zu\n", ch);
	printf("%zu\n", ch2);

	printf("두번째 문자 주소 %u\n," "apple" + 1);
	printf("두번째 문자 주소 %c\n,", *("apple" + 1));
	printf("두번째 문자 주소 %c\n,", "apple"[0]);

	char fruit[6] = "apple";

	strcpy(fruit, "banan");
	printf("%s\n", fruit);
	char* dessert = "banana";
	printf("%s\n", dessert);

	return 0;
}