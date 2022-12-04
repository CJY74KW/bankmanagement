#define _CRT_SECURE_NO_WARNINGS
#define NAME_LEN 20 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

typedef struct bank { // ���������� ������ ����ü ����
	char* name[NAME_LEN]; // ������
	int id;               // ���¹�ȣ
	int money;            // �ܾ�
	struct bank* next;
}bank, BANK;


bank* first, * last; // ����� ó���� ��
void Init_account(FILE* fp); // ����� ó���� ���� �޸� �Ҵ��ϰ�, ���Ͽ��� �Է��� �޵��� �ϴ� �Լ�
void Make_account(FILE* fp, FILE* yh); // ���¸� �����ϴ� �Լ�
void Deposit(FILE* fp, FILE* yh); // �Ա� �Լ�
void WithDraw(FILE* fp, FILE* yh); // ��� �Լ�
void WriteAccount(FILE* fp); // ������ ������ �����ϴ� �Լ�
void Account_inquire(void); // ���¸� ��ȸ�ϴ� �Լ�
void ReadAccount(int id, char* name, int money); // �ؽ�Ʈ ���Ͽ��� �Է��� �޴� �Լ�
void makefile(char* name, int money, FILE* yh);
void U_Account();//���� �����ϴ� �޴� �Լ�
void U_money();//���� �����ϴ� ����� �޴� �Լ�
void nae_q(FILE* fp, FILE* yh);//���� ������ Ȯ���ϴ� �Լ�