

extern int count; // main.c에 있는 count을 가져와서 공유
extern int total; // input.c의 total을 가져와서 공유

double average(void)
{
	return total / (double)count;
}