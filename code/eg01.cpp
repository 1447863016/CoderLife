// 1.界面 2.数据结构设计 3.交互
#include "mylist.h"
// 数据设计--------学生信息抽象
void menu()
{
    // 所以操作都同步到文件
    printf("--------------------------------------\n");
    printf("\t\t0.退出系统\n");
    printf("\t\t1.录入信息\n");
    printf("\t\t2.浏览信息\n");
    printf("\t\t3.修改信息\n");
    printf("\t\t4.删除信息\n");
    printf("\t\t5.查找信息\n");
    printf("--------------------------------------\n");
}
// 用户的交互
    // 根据所选的菜单项目去进行设计
struct Node* list = NULL;
void keydown()
{
    int choice = 0;
    struct student data;
    scanf("%d",&choice);
    struct Node* pMove = NULL;
    switch (choice)
    {
    case 0:
       printf("正常退出！\n");
       system("pause");
       exit(0);
        break;
    case 1:
       printf("-------------【录入信息】-------------------\n");
        printf("输入学生姓名年龄性别电话：\n");
        fflush(stdin);//清空缓冲区，不清除可能输入整形数据后会跳过字符输入
        scanf("%s%d%s%s",data.name,&data.age,data.sex,data.tel);
        insertNodeByHead(list,data);
        break;
    case 2:
       printf("-------------【浏览信息】-------------------\n");
    //    打印链表
        printList(list);
        break;
    case 3:
       printf("-------------【修改信息】-------------------\n");
       printf("输入修改学生的姓名：\n");
       scanf("%s",data.name);
       pMove = searchInfoByData(list,data.name);
        if (pMove == NULL)
        {
             printf("未找到相关信息\n");
             system("pause");
        }else{
            printf("输入修改学生的信息：\n");
            scanf("%s\t%d\t%s\t%s\n",pMove->data.name,&pMove->data.age,pMove->data.sex,pMove->data.tel);
            printf("修改后的信息为：\n");
            printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        }
        break;
    case 4:
       printf("-------------【删除信息】-------------------\n");
       printf("输入删除的学生姓名:");
       scanf("%s",data.name);
       deleteAppoinNode(list,data.name);
        break;
    case 5:
       printf("-------------【查找信息】-------------------\n");
       printf("输入查找的学生姓名:");
       scanf("%s",data.name);
       pMove = searchInfoByData(list,data.name);
        if (pMove == NULL)
        {
             printf("未找到相关信息\n");
             system("pause");
        }else
        {
            printf("姓名\t年龄\t性别\t电话\n");
            printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        }
        
        break;
    
    default:
    printf("选择错误重新输入\n");
    system("pause");

        break;
    }
    writeInfoToFile(list,"1.txt");
}



int main()
{
    list = createlist();
    // readInfoFromFile(list,"1.txt");
    while (1)
{
    
    menu();
    keydown();
    system("pause");
    system("cls");
}
// 测试链表代码
//     struct Node* list = createlist();
//     insertNodeByHead(list,1);
//     insertNodeByHead(list,2);
//     insertNodeByHead(list,3);
//     insertNodeByHead(list,4);
//     printList(list);
//     printf("删除节点\n");
//     deleteAppoinNode(list,3);
//     printList(list);
//     printf("查找节点\n");
//     printf("%d\n",searchInfoByData(list,2)->data);


    system("pause");
    return 0;
}
