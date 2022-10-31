#include<stdio.h>
#include<stdlib.h>
#include  <time.h>
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        j = (rand());
        printf("%d\n",j);
    }
    
    
    system("pause");
    return 0;
}