// 연산자

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	// 산술 연산자
	int x, y;
	int sum, sub, mul, mod;
	double div;
	int inv;

	x = 7;
	y = 3;
	sum = x + y; // 덧셈
	sub = x - y; // 뺄셈
	mul = x * y; // 곱셈
	div = (double)x / y; // 나눗셈. 실수로 형변환
	mod = x % y; // 나눈 나머지
	inv = -x;

	printf("x = %d, y = %d\n", x, y);
	printf("x + y = %d \n", sum);
	printf("x - y = %d \n", sub);
	printf("x × y = %d \n", mul);
	printf("x ÷ y = %lf \n", div);
	printf("x mod y = %d \n", mod);
	printf("inverse  x = %d\n", inv);

	// 대입연산자
	int a = 10; // int형 변수 a를 만들고 거기에 10을 집어넣어라
	int b = 20;
	char c = 'c';

	// 증감연산자
	++a; //a에 1을 증가시켜라
	//a++;
	//c++;
	//증감연산자의 위치에 따라 처리되는 순서가 다름!!

	--b;
	//b--;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("a = %d\n", a++);

	// 관계 연산자

	int d = 10;
	int res; //결과 저장변수

	// false => 0, true => 1
	res = (a > b);  // 0
	printf("a > b : %d\n", res);
	printf("a >= b : %d\n", a>=b);
	printf("a < b : %d\n", a < b);
	res = (a == b); // = 대입연산자, == 동치비교연산자
	res = (a != b); // 1

	// 논리 연산자
	// &&(and), ||(or), !(not)
	res = (a > 10) && (b < 20); // 1(true)
	printf("a(a>10) && (b<20) : %d\n", res);
	res = (a <= 10) && (b > 10); // 0(false)
	printf("a(a>10) && (b<20) : %d\n", res);
	res = (a < 10) || (b > 10);
	printf("a(a<10) || (b>10) : %d\n", res);

	res = !(a >= 30); //1
	printf("!(a>=30) : %d\n", res);

	//형 변환 연산자
	// int, short, char, long, float, double...
	printf("%d\n", (int)3.14);
	printf("%f\n", (float)3);
	// 형 변환 방법 : (데이터형)

	// 자동형변환
	char chval = 65;
	int ival = 0;

	ival = chval;
	printf("%d\n", ival);

	// sizeof 연산자
	int g = 25;
	float h = 3.1f;
	char ch = 'A';

	printf("int형 변수 크기 : %llu\n", sizeof(g));
	printf("int 타입 크기 : %lld\n", sizeof(int));
	printf("float 타입 크기 : %lld\n", sizeof(h));
	printf("double 타입 크기 : %lld\n", sizeof(1.5+3.4));
	printf("char 형 변수 크기 : %lld\n", sizeof(ch)); // 'A' 바로 대입하면 ASCII value 65로 int형(4)

	// 복합대입연산자
	printf("%d\n", a);
	a += 5; // a= a+5; 변수 a에 5를 더해서 변수 a에 대입하라!!
	// -=, *=, /=, %=

	//연산자 우선순위 주의!!
	res = 2;
	a = 10, b = 20;
	c = 30;

	res *= b + 10; // res = res * (b+10)
	printf("%d\n", res);

	// 콤마 연산자
	// 한번에 여러개 수식을 차례로 나열해야 할때 사용
	res = (++a, ++b); // a도 1증가, b도 1증가 후 가장 오른쪽에 있는 피연산자값을 res에 대입하라
	printf("%d, %d, %d\n", a, b, res);

	res = (++a, ++b, ++c);
	printf("%d, %d, %d, %d\n", a, b, c, res);

	// 삼항 연산자
	// (조건) ? 참결과 : 거짓결과
	int i = 30, j = 25;
	printf("작은 값 : %d\n", (i < 25) ? i : j);

	//비트 연산자
	a = 10; //    00000000 00000000 00000000 00001010
	b = 12; //    00000000 00000000 00000000 00001100

	// &(and), |(or)
	printf("a & b : %d\n", (a & b)); // 00000000 00000000 00000000 00001000 => 8
	printf("a | b : %d\n", (a | b)); // 00000000 00000000 00000000 00001000 => 14

	return 0;
}