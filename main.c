#include "bank.h"

int main()
{
    int input;
    FILE* fp;
    FILE* yh = NULL;
    fp = fopen("Bankdata.txt", "r+"); // ���ϸ�尡 w+�� ���  �а��⸦ ���ÿ� ���� �մϴ�.
    Init_account(fp);

    do
    {
        system("cls");
        fflush(stdin);
        printf("\n");
        Current_Time();
        printf("\n");
        printf("���Ͻô� ��ȣ�� �Է��ϼ���.\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf(" ����������������������\n");
        printf("*********************************************\n");
        printf("1)���� ���� 2)���� ���� 3)���� \n");
        printf("*********************************************\n");
        printf("�Է� >");
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
            free(first); // �����ϸ鼭 �޸� ��ȯ
            free(last);
            break;
        default:
            printf("�߸� �Է��ϼ̽��ϴ�. \n");
            system("pause");
            return main();
        }
    } while (input != 0);
}

