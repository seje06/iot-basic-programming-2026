 // 주소록 프로그램 step1

#define _CRT_SECURE_NO_WARNINGS

#pragma region include 영역

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region 매크로

// 유지보수를 위해서
#define MAX_CONTACTS 100 // 100명 주소록
#define NAME_LEN 31 // 이름 최대길이
#define PHONE_LEN 20
#define EMAIL_LEN 64
#define ADDR_LEN 129
#define MEMO_LEN 129

#pragma endregion

typedef struct _contact
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;

#pragma region 변수 영역
// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;
#pragma endregion

#pragma region 함수선언 영역
// 함수 선언
static void print_menu(void); // 이 소스내에서만 쓰겠다
static int read_menu(void);
static void read_line(char* buf, int size);

static void add_contact(void);
static void list_contacts(void);

static void search_contact(void);
static void print_contact(int index);

static void update_contact(void);
static void delete_contact(void);
#pragma endregion

int main(void)
{
	int choice = 0;

	while (1) // 무한루프 :
	{
		print_menu(); // 메뉴를 출력
		choice = read_menu();// choice 값에 입력 받음

		switch (choice)
		{
		case 1:
			//printf("%s\n", "[ADD] 연락처 추가 (기능 구현요)");
			add_contact();
			break;
		case 2:
			//puts("[LIST] 연락처 목록");
			list_contacts();
			break;
		case 3:
			search_contact();
			break;
		case 4:
			update_contact();
			break;
		case 5:
			delete_contact();
			break;
		case 6:
			puts("프로그램 종료");
			return 0;
		default:
			puts("메뉴는 1~6사이 입니다.");
			break;
		}
		puts(" ");
	}

	return 0;
}

#pragma region 사용자 함수 정의

// 메뉴출력 함수
static void print_menu(void)
{
	puts("==================================================");
	puts("             주소록 프로그램 (step 3)             ");
	puts("==================================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 종료");
	puts("--------------------------------------------------");
}

// 메뉴읽기 함수
static int read_menu(void)
{
	int choice, ch;
	printf("선택 > ");
	if (scanf("%d", &choice) != 1)
	{
		while ((ch = getchar()) != '\n' && ch!=EOF) {}
		return -1;
	}

	//scanf 뒤에 있는 버퍼에 엔터값 제거
	while ((ch = getchar()) != '\n' && ch != EOF) {}
	return choice;
}

//fgets로 입력할때 문제가 발생하지 않도록, 문자열 끝에 \n을 제거
static void read_line(char* buf, int size)
{
	if (fgets(buf, size, stdin) == NULL)
	{
		buf[0] = "\0";
		return;
	}

	// strcspn(buf, '\n') = buf 문자열 내에서 \n을 찾아서 위치값을 리턴
	// "Hello World!\n" -> "Hello World!\0"
	// buf[12] = '\0'
	buf[strcspn(buf, "\n")] = '\0'; // 문자열 끝에 \n을 \0으로 변경
}

// 메뉴 1번 기능. 연락처 추가
static void add_contact(void)
{
	if (count >= MAX_CONTACTS)
	{
		puts("주소록 최대인원 100명에 도달 했습니다.");
		return;
	}

	puts("[ADD] 새 연락처 입력");

	printf("이름 : ");
	read_line(contacts[count].name, NAME_LEN);

	printf("전화 : ");
	read_line(contacts[count].phone, PHONE_LEN);
	
	printf("주소 : ");
	read_line(contacts[count].address, ADDR_LEN);
	
	printf("이메일 : ");
	read_line(contacts[count].email, EMAIL_LEN);

	printf("메모 : ");
	read_line(contacts[count].memo, MEMO_LEN);

	count++;
	puts("추가 완료!");
}


void print_char(char ch, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c", ch);
	}
}

// 메뉴 2. 주소록 목록
static void list_contacts(void)
{
	int i;

	if (count == 0)
	{
		puts("[LIST] 저장된 연락처 없음.");
		return;
	}
	puts("[LIST] 연락처 목록");
	puts("----------------------------------------------------------------------------------------------------");
	printf("%4s | %-10s | %-17s | %-30s | %-25s\n", "No", "Name", "Phone", "Address", "Enail");
	puts("----------------------------------------------------------------------------------------------------");

	// contacts 배열에 들어있는 주소록 출력
	for (i = 0; i < count; i++)
	{
		/*printf("%4d | ", i);
		print_char(' ', 10 - strlen(contacts[i].name));
		printf("%s | ", contacts[i].name);
		print_char(' ', 17 - strlen(contacts[i].phone));
		printf("%s | ", contacts[i].phone);
		print_char(' ', 30 - strlen(contacts[i].address));
		printf("%s | ", contacts[i].address);
		print_char(' ', 25 - strlen(contacts[i].email));
		printf("%s\n", contacts[i].email);*/

		printf("%4d | %-11s | %-15s | %-36s | %-25s\n",
			i, contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
	}

	puts("----------------------------------------------------------------------------------------------------");
}

static void search_contact(void)
{
	char keyword[NAME_LEN];
	int found = 0;
	int i;

	if (count == 0)
	{
		puts("검색할 연락처가 없습니다.");
		return;
	}

	printf("검색할 이름 입력 : ");
	read_line(keyword, NAME_LEN);

	if (strlen(keyword) == 0)
	{
		puts("검색할 이름이 없습니다.");
		return;
	}

	puts("검색 결과 : ");
	puts("------------------------------------------------------------");

	for (i = 0; i < count; i++)
	{
		//strcmp와 유사한 기능, strstr(찾을 문자열, 찾는 문자열) 같은 문자열이 있으면 그 문자열 리턴
		if (strstr(contacts[i].name, keyword) != NULL)
		{
			printf("순번 : %d\n", i + 1);
			// 상세 출력
			print_contact(i);
			puts("------------------------------------------------------------");
			found = 1;
		}
	}
	
	if (found < 1)
	{
		puts("일치하는 연락처가 없습니다.\n");
	}
}

static void print_contact(int index)
{
	printf("이름   : %s\n", contacts[index].name);
	printf("전화   : %s\n", contacts[index].phone);
	printf("주소   : %s\n", contacts[index].address);
	printf("이메일 : %s\n", contacts[index].email);
	printf("메모   : %s\n", contacts[index].memo);
}

static void update_contact(void)
{
	char buf[MEMO_LEN];
	int index, ch;

	if (count == 0)
	{
		puts("수정할 연락처가 없습니다.");
		return;
	}

	printf("[UPDATE] 수정할 번호 (1 ~ %d) > ", count);
	if (scanf("%d", &index) != 1) // 입력  실패면
	{
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;
	}
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	if (index < 1 || index > count)
	{
		puts("입력범위 초과");

		return;
	}

	puts("현재 정보:");
	print_contact(index - 1); // 실제 인덱스는 0,1,2지만 검색순번은 1,2,3 을 사용하기 때문에 -1
	puts("------------------------------------------------------------");
	//일단 검색해서 나온 결과 보기까지 구현

	//실제 수정 로직
	puts("새 값 입력 (엔터만 입력하면 기존값 유지)");

	printf("이름 (%s) > ", contacts[index-1].name);
	read_line(buf, NAME_LEN);
	if (buf[0] != '\0')
	{
		strncpy(contacts[index - 1].name, buf, NAME_LEN);
	}

	printf("전화 (%s) > ", contacts[index - 1].phone);
	read_line(buf, PHONE_LEN);
	if (buf[0] != '\0')
	{
		strncpy(contacts[index - 1].phone, buf, PHONE_LEN);
	}

	printf("주소 (%s) > ", contacts[index - 1].address);
	read_line(buf, ADDR_LEN);
	if (buf[0] != '\0')
	{
		strncpy(contacts[index - 1].address, buf, ADDR_LEN);
	}

	printf("이메일 (%s) > ", contacts[index - 1].email);
	read_line(buf, EMAIL_LEN);
	if (buf[0] != '\0')
	{
		strncpy(contacts[index - 1].email, buf, EMAIL_LEN);
	}

	printf("메모 (%s) > ", contacts[index - 1].memo);
	read_line(buf, MEMO_LEN);
	if (buf[0] != '\0')
	{
		strncpy(contacts[index - 1].memo, buf, MEMO_LEN);
	}
}

static void delete_contact(void)
{
	int idx, i, ch;
	char yn[8];

	if (count == 0)
	{
		puts("삭제할 연락처가 없습니다.");
		return;
	}

	printf("[UPDATE] 수정할 번호 (1 ~ %d) > ", count);
	if (scanf("%d", &idx) != 1) // 입력  실패면
	{
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;
	}
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	if (idx < 1 || idx > count)
	{
		puts("입력범위 초과");

		return;
	}

	puts("삭제할 정보 :");
	print_contact(idx - 1);

	printf("정말 삭제하시겠습니까? (y/n) > ");
	read_line(yn, (int)sizeof(yn));

	if (!yn[0] == 'y' || yn[0] == 'Y')
	{
		puts("삭제 취소합니다.");
		return;
	}

	for (i = idx - 1; i < count - 1; i++)
	{
		contacts[i] = contacts[i + 1];
	}

	count--;

	puts("삭제 완료!");
}

#pragma endregion