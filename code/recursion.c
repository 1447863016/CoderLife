#include<stdio.h>
#include<stdlib.h>

void print(int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d\n",n % 10);
    
}

int main()
{
    unsigned int a = 0;
    printf("enter a character\n");
    scanf("%d",&a);
    print(a);
    system("pause");
    return 0 ;
}