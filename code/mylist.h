#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���ݽṹ�����---ѧ����Ϣ�����
struct student
{
    char name[20];
    int age;
    char sex[5];
    char tel[20];
};

// �ṹ �ֽṹȥд
// ����д�����ݽṹ
struct Node
{
    // int data;
    struct student data;
    struct Node* next;
};
// ������
struct Node* createlist()
{
    // �ṹ�������ʾ��ͷ
    // ָ��--->��������̬�ڴ�����
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    // ��ͷ�������컯���� ������ data ������ʼ��
    headNode->next = NULL;
    return headNode;
};
// �������
struct Node* createNode(struct student data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
// ������
void insertNodeByHead(struct Node*headNode,struct student data)
{
    struct Node* newNode = createNode(data);
    // ��ͷ��
    newNode->next = headNode->next;
     headNode->next = newNode;
}
// ָ��λ��ɾ��
void deleteAppoinNode(struct Node* headNode,char* name)
{
    struct Node* posNode = headNode->next;
    struct Node* posFrontNode = headNode;
    if (posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ����\n");
        return;
    }
    while (strcmp(posNode->data.name,name))
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
        if (posNode == NULL)
        {
            printf("δ�ҵ�ָ��λ���޷�ɾ����\n");
            return;
        }
    }
    // �ҵ���
    posFrontNode->next = posNode->next;
    free(posNode);
}

// ���ҹ���
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
// �ļ�������
void readInfoFromFile(struct Node* headNode,char *filename)
{
    // 1.��
    FILE *fp;
    struct student data;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        fp = fopen(filename,"w+");
    }
    
    // 2.���ļ�
    while (fscanf(fp,"%s\t%d\t%s\t%s\n",data.name,data.age,data.sex,data.tel) != EOF)
    {
        insertNodeByHead(headNode,data);
    }
    
    // 3.�ر��ļ�
    fclose(fp);
}


// �ļ�д����
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

// ��ӡ����
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode->next;
    // ��Ƶ����ݵĴ���
    printf("����\t����\t�Ա�\t�绰\n");
    while (pMove)
    {
        printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        pMove = pMove->next;
    }
    printf("\n");
    
}

