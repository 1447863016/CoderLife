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
        printf("请选择：\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            // play
            break;

        case 0:
            // play
        printf("正常退出！\n");
        system("pause");
        exit(0);
        break;
        
        default:
        printf("数据输入有误，重新输入\n");
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

