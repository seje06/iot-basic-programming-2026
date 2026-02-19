#pragma once

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#pragma region 전처리 영역

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region 매크로 선언 영역

// 사람은 숫자보다 이름에 익숙. 유지보수를 위해서
#define MAX_CONTACTS  100    // 100명 주소록
#define INIT_CAPACITY   2	 // 초기값 15로 구성
#define NAME_LEN	   31	 // 이름 최대길이
#define PHONE_LEN      21
#define EMAIL_LEN      65
#define ADDR_LEN	  121
#define MEMO_LEN	   31

#pragma endregion

typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char address[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;   // 이후 Contact 이름으로 사용



#pragma region 함수선언 영역

// 함수 선언
void print_menu(void);   // 이 소스내에서만 쓰겠다
int read_menu(void);
void add_contact(void);
void list_contacts(void);
void search_contact(void);
void update_contact(void);
void delete_contact(void);
int save_contacts(const char* filename); // 파일명이 변경되면 안됨
int load_contacts(const char* filename);
void sort_by_name(void); //이름순 정렬 qsort() 함수 사용, stdlib.h에 포함
int ab_init(void); //주소록 초기화
void ab_free(void); // 주소록 메모리 해제
#pragma endregion

#endif

// 외부 main.c에서 호출할 함수리스트