#include "bank.h"

int main()
{
    int input;
    FILE* fp;
    FILE* yh = NULL;
    fp = fopen("Bankdata.txt", "r+"); // 파일모드가 w+일 경우  읽고쓰기를 동시에 수행 합니다.
    Init_account(fp);

    do
    {
        system("cls");
        fflush(stdin);
        printf("\n");
        Current_Time();
        printf("\n");
        printf("원하시는 번호를 입력하세요.\n");
        printf(" □□□□■■□□■■□□□□□■■■□□□\n");
        printf(" □□□□■■□□■■□□□□■■■■□□□\n");
        printf(" □□□□■■□■■□□□□■■□□□□□□\n");
        printf(" □□□□■■■■□□□□□■■□□□□□□\n");
        printf(" □□□□■■■□□□□□□■■■■□□□□\n");
        printf(" □□□□■■□□□□□□□□■■■■□□□\n");
        printf(" □□□□■■■□□□□□□□□□□■■□□\n");
        printf(" □□□□■■■■□□□□□□□□■■□□□\n");
        printf(" □□□□■■□■■□□□□□□■■□□□□\n");
        printf(" □□□□■■□□■■□□□■■■■□□□□\n");
        printf(" □□□□■■□□■■□□□■■□□□□□□\n");
        printf("*********************************************\n");
        printf("1)계좌 관리 2)예금 관리 3)종료 \n");
        printf("*********************************************\n");
        printf("입력 >");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            U_Account();
            break;
        case 2:
            U_Money();
            break;
        case 3:
            input = 0;
            free(first); // 종료하면서 메모리 반환
            free(last);
            break;
        default:
            printf("잘못 입력하셨습니다. \n");
            system("pause");
            return main();
        }
    } while (input != 0);
}

