#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 数据结构的设计---学生信息抽象出
struct student
{
    char name[20];
    int age;
    char sex[5];
    char tel[20];
};

// 结构 分结构去写
// 首先写对数据结构
struct Node
{
    // int data;
    struct student data;
    struct Node* next;
};
// 创建表
struct Node* createlist()
{
    // 结构体变量表示表头
    // 指针--->变量，动态内存申请
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    // 表头：做差异化处理 数据域 data 不做初始化
    headNode->next = NULL;
    return headNode;
};
// 创建结点
struct Node* createNode(struct student data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
// 插入结点
void insertNodeByHead(struct Node*headNode,struct student data)
{
    struct Node* newNode = createNode(data);
    // 表头法
    newNode->next = headNode->next;
     headNode->next = newNode;
}
// 指定位置删除
void deleteAppoinNode(struct Node* headNode,char* name)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode = headNode;
    if (posNode == NULL)
    {
        printf("数据为空，无法删除！\n");
        return;
    }
    while (strcmp(posNode->data.name,name))
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
        if (posNode == NULL)
        {
            printf("未找到指定位置无法删除！\n");
            return;
        }
    }
    // 找到了
    posFrontNode->next = posNode->next;
    free(posNode);
}

// 查找功能
struct Node* searchInfoByData(struct Node* headNode,char* name)
{
    struct Node* pMove = headNode->next;
    if (pMove == NULL)
    {
        return NULL;
    }
    while (strcmp(pMove->data.name,name))
    {
        pMove = pMove->next;
    }
    return pMove;
    
}
// 文件读操作
void readInfoFromFile(struct Node* headNode,char *filename)
{
    // 1.打卡
    FILE *fp;
    struct student data;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        fp = fopen(filename,"w+");
    }
    
    // 2.读文件
    while (fscanf(fp,"%s\t%d\t%s\t%s\n",data.name,data.age,data.sex,data.tel) != EOF)
    {
        insertNodeByHead(headNode,data);
    }
    
    // 3.关闭文件
    fclose(fp);
}


// 文件写操作
void writeInfoToFile(struct Node* headNode,char *filename)
{
    FILE *fp;
    fp = fopen(filename,"w");
    struct Node* pMove = headNode->next;
    while (pMove)
    {
        fprintf(fp,"%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        pMove = pMove->next;
    }
    
}

// 打印链表
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;
    // 设计到数据的处理
    printf("姓名\t年龄\t性别\t电话\n");
    while (pMove)
    {
        printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        pMove = pMove->next;
    }
    printf("\n");
    
}

