#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int my_strlen(char* str)// 使用计数变量完成strlen函数

// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         count ++;
//         str ++;
//     }
//     return count;
    
// }

// 使用递归来完成strlen，和求树的深度相似
int my_strlen(char* str)
{
    if (*str != '\0')
    {
        return(1 + my_strlen(str + 1));
    }else{
        return 0 ;
    }
    
}
int main()
{
    char arr[] = "bit";
    // int len = strlen(arr);
    // printf("%d\n",len);
    int len = my_strlen(arr);
    printf("len =  %d\n",len);
    system("pause");
    return 0;
}
// 书写递归需要找到限制条件，且递归过后会接近这个限制条件
