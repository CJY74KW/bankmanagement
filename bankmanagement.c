#include "bank.h"

void Init_account(FILE* fp)
{
    int id;
    char name[NAME_LEN];
    int money;
    first = (bank*)malloc(sizeof(bank));
    last = (bank*)malloc(sizeof(bank));
    first->next = last;
    last->next = last;

    while (fscanf(fp, "%d %s %d", &id, name, &money) == 3) // 정수형, 문자형, 정수형 3개일 때만 입력을 받음
    {
        ReadAccount(id, name, money);
    }

}

void ReadAccount(int id, char* name, int money)
{
    bank* t;
    t = (bank*)malloc(sizeof(bank));
    t->id = id;
    strcpy(t->name, name);
    t->money = money;
    t->next = first->next; // 다음 노드를 가리킴
    first->next = t; // 노드의 처음을 가리킴
}

void Make_account(FILE* fp, FILE* yh)
{
    int id;
    char name[NAME_LEN];
    int money;
    bank* t;
    t = (bank*)malloc(sizeof(bank));
    printf("\n*********계좌 생성*********\n");
    printf("계좌번호 : ");
    scanf("%d", &id);
    printf("예 금 주 : ");
    scanf("%s", name);
    printf("입 금 액 : ");
    scanf("%d", &money);
    t->id = id;
    strcpy(t->name, name);
    t->money = money;
    makefile(name, money, yh);
    t->next = first->next;
    first->next = t;
    WriteAccount(fp); // 저장하는 함수로 파일 포인터를 넘겨줌
}

void Deposit(FILE* fp, FILE* yh)
{
    bank* t;
    int id;
    int money;
    printf("계좌번호 : "); scanf("%d", &id);
    for (t = first->next; t != last; t = t->next)
        if (t->id == id)
            printf("예금주명 : %s\n", t->name);
    printf("입 금 액 : "); scanf("%d", &money);
    for (t = first->next; t != last; t = t->next)
    {
        if (t->id == id)
        {
            makefile(t->name, money, yh);
            t->money += money; // 잔액에 입금할 금액을 더해서
            WriteAccount(fp); // 저장
            return;
        }
    }
    system("pause");
}

void WithDraw(FILE* fp, FILE* yh)
{
    int id;
    int money;
    bank* t;
    printf("계좌번호 : "); scanf("%d", &id);
    for (t = first->next; t != last; t = t->next)
        if (t->id == id)
            printf("예금주명 : %s\n", t->name);
    printf("출 금 액 : "); scanf("%d", &money);
    for (t = first->next; t != last; t = t->next)
    {
        if (t->id == id)
        {
            makefile(t->name, money * -1, yh);
            if (t->money < money) // 출금액이 잔액보다 클 경우
            {
                printf("출금액이 잔액을 초과하였습니다.\n");
                system("pause");
                return;
            }
            else
            {
                t->money -= money; // 잔액에서 출금액을 빼서
            }
            WriteAccount(fp); // 저장
            return;
        }

    }
    printf("없는 계좌번호입니다.\n");
    system("pause");
}

void Account_inquire(void)
{
    bank* t;
    for (t = first->next; t != last; t = t->next)
    {
        printf("\n*********잔액 조회*********\n");
        printf("계좌번호 : %d\n", t->id);
        printf("예 금 주 : %s님\n", t->name);
        printf("잔    액 : %d원\n\n", t->money);
    }
    system("pause");
}

void WriteAccount(FILE* fp)
{
    bank* t;
    rewind(fp); // 파일 읽는 포인터 지점을 맨 첨으로 돌리는 함수
    for (t = first->next; t != last; t = t->next)
    {
        fprintf(fp, "%d %s %d\n", t->id, t->name, t->money);
    }

}

void makefile(char* name, int money, FILE* yh)
{
    const char txt[] = ".txt";
    strcat(name, txt);
    yh = fopen(name, "a+");

    struct tm* date;
    const time_t _time = time(NULL);   // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    date = localtime(&_time); // 포맷팅을 위해 구조체에 넣기
    fprintf(yh, "%d년 %d월 %d일 %d시 %d분 %d초", date->tm_year + 1900, date->tm_mon + 1
        , date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);

    if (money > 0)
        fprintf(yh, " %d원 입금\n", money);
    else
        fprintf(yh, " %d원 출금\n", money * -1);
    name = strtok(name, ".txt");
    fclose(yh);
}

void nae_q(FILE* fp, FILE* yh)
{
    bank* t;
    int id;
    const char txt[] = ".txt";
    char str[50];
    printf("계좌번호 : ");
    scanf("%d", &id);
    for (t = first->next; t != last; t = t->next)
    {
        if (t->id == id)
        {
            char* name = t->name;
            name = strcat(name, txt);
            yh = fopen(name, "r+");
            while (fgets(str, sizeof(str), yh))
                printf("\n%s", str);
            strtok(t->name, ".txt");
        }
    }
    system("pause");
}
void Current_Time()
{
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷을 위해 구조체에 넣기

    printf("현재시간은 ");
    printf("%d년 ", t->tm_year + 1900);
    printf("%d월 ", t->tm_mon + 1);
    printf("%d일 ", t->tm_mday);
    printf("%d시 ", t->tm_hour);
    printf("%d분 ", t->tm_min);
    printf("%d초입니다. \n", t->tm_sec);

}

void U_Account()
{
    int input;
    FILE* fp;
    FILE* yh = NULL;
    fp = fopen("Bankdata.txt", "r+"); // 파일모드가 r+일 경우  읽고쓰기를 동시에 수행 합니다.
    Init_account(fp);
    do {
        system("cls");
        printf("원하시는 번호를 입력하세요.\n");
        printf("*********************************************\n");
        printf("1)계좌 생성 2)계좌 조회 3)계좌 내역 4)이전 메뉴 5)종료\n");
        printf("*********************************************\n");
        printf("입력 >");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            Make_account(fp, yh);
            break;
        case 2:
            Account_inquire();
            break;
        case 3:
            nae_q(fp,yh);
            break;
        case 4:
            return main();
        case 5:
            exit(1);
        }
    } while (input != 4);

}

void U_Money()
{
    int input;
    FILE* fp;
    FILE* yh = NULL;
    fp = fopen("Bankdata.txt", "r+"); // 파일모드가 r+일 경우  읽고쓰기를 동시에 수행 합니다.
    Init_account(fp);
    do {
        system("cls");
        printf("원하시는 번호를 입력하세요.\n");
        printf("*********************************************\n");
        printf("1)입금 2)출금 3)이전 메뉴 4)종료\n");
        printf("*********************************************\n");
        printf("입력 >");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            Deposit(fp, yh); // 입금 함수
            break;
        case 2:
            WithDraw(fp, yh); //출금 함수
            break;
        case 3:
            return main();
        case 4:
            exit(1);
        }
    } while (input != 4);

}
