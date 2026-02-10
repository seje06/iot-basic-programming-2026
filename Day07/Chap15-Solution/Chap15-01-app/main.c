// 함수 포인터
// 함수도 변수처럼 주소를 가짐. 포인터로 활용가능
// 콜백, 대리자(이벤트) 함수 처리할 때 필요한 기능

#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);


int main(void)
{
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = fp(2, 3);
	printf("sum 결과 : %d\n", res);
	
	fp = sub;
	res = fp(2, 3);
	printf("sub 결과 : %d\n", res);

	fp = mul;
	res = fp(2, 3);
	printf("mul 결과 : %d\n", res);

	fp = div;
	res = fp(2, 3);
	printf("div 결과 : %d\n", res);





	

	// 함수 포인터 배열
	int (*fp_arry[4])(int, int);
	fp_arry[0] = sum;
	fp_arry[1] = sub;
	fp_arry[2] = mul;
	fp_arry[3] = div;

	for (int i = 0; i < 4; i++)
	{
		res = fp_arry[i](2,3);
		printf("fp_arry의 index %d 결과 : %d\n",i, res);
	}

	return 0;
}

int sum(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}