#include <game.h>

void menu()
{
    printf("*************************");
    printf("***1.play    0.exit******");
    printf("*************************");
}

void text()
{
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            // play
            break;

        case 0:
            // play
        printf("�����˳���\n");
        system("pause");
        exit(0);
        break;
        
        default:
        printf("��������������������\n");
        system("pause");
        exit(0);
            break;
        }
    } while (/* condition */);
    
}

int main()
{
    test();
    return 0;
}

