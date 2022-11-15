#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Facl(int n)//求阶乘
{
    if (n <= 1)
    {
        return 1;
    }else return n * Facl(n-1);
    
}

// 求斐波那契数列
int Fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }else return Fib(n -1) + Fib(n -2);
    
}
int main()
{
    int n = 0;
    while (1)
    {
    printf("enter a character\n");
    scanf("%d",&n);
    int num = Fib(n);
    printf("%d",num);
    // system("cls");
    system("pause");
    }
    

    
    return 0 ;
}