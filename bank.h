#define _CRT_SECURE_NO_WARNINGS
#define NAME_LEN 20 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

typedef struct bank { // 계좌정보를 저장할 구조체 선언
	char* name[NAME_LEN]; // 예금주
	int id;               // 계좌번호
	int money;            // 잔액
	struct bank* next;
}bank, BANK;


bank* first, * last; // 노드의 처음과 끝
void Init_account(FILE* fp); // 노드의 처음과 끝에 메모리 할당하고, 파일에서 입력을 받도록 하는 함수
void Make_account(FILE* fp, FILE* yh); // 계좌를 생성하는 함수
void Deposit(FILE* fp, FILE* yh); // 입금 함수
void WithDraw(FILE* fp, FILE* yh); // 출금 함수
void WriteAccount(FILE* fp); // 계좌의 정보를 저장하는 함수
void Account_inquire(void); // 계좌를 조회하는 함수
void ReadAccount(int id, char* name, int money); // 텍스트 파일에서 입력을 받는 함수
void makefile(char* name, int money, FILE* yh);
void U_Account();//계좌 관리하는 메뉴 함수
void U_Money();//예금 관리하는 기능의 메뉴 함수
void nae_q(FILE* fp, FILE* yh);//계좌 내역을 확인하는 함수
