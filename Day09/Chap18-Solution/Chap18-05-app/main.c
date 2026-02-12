// 텍스트파일, 바이너리 파일 비교

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	FILE* tfp, * bfp; // tfp 텍스트용, bfp 바이너리용
	int num = 10;
	int res;

	tfp = fopen("./text.txt", "wt");
	fprintf(tfp, "%d", num);

	bfp = fopen("./binary.bin", "wb");
	fwrite(&num, sizeof(num), 1, bfp); // 배열이면 fwrite(arr, sizeof(arr[0]), 배열요소 갯수, fp);

	fclose(tfp);
	fclose(bfp);

	bfp = fopen("./binary.bin", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);

	return 0;
}