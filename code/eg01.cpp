// 1.���� 2.���ݽṹ��� 3.����
#include "mylist.h"
// �������--------ѧ����Ϣ����
void menu()
{
    // ���Բ�����ͬ�����ļ�
    printf("--------------------------------------\n");
    printf("\t\t0.�˳�ϵͳ\n");
    printf("\t\t1.¼����Ϣ\n");
    printf("\t\t2.�����Ϣ\n");
    printf("\t\t3.�޸���Ϣ\n");
    printf("\t\t4.ɾ����Ϣ\n");
    printf("\t\t5.������Ϣ\n");
    printf("--------------------------------------\n");
}
// �û��Ľ���
    // ������ѡ�Ĳ˵���Ŀȥ�������
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
       printf("�����˳���\n");
       system("pause");
       exit(0);
        break;
    case 1:
       printf("-------------��¼����Ϣ��-------------------\n");
        printf("����ѧ�����������Ա�绰��\n");
        fflush(stdin);//��ջ���������������������������ݺ�������ַ�����
        scanf("%s%d%s%s",data.name,&data.age,data.sex,data.tel);
        insertNodeByHead(list,data);
        break;
    case 2:
       printf("-------------�������Ϣ��-------------------\n");
    //    ��ӡ����
        printList(list);
        break;
    case 3:
       printf("-------------���޸���Ϣ��-------------------\n");
       printf("�����޸�ѧ����������\n");
       scanf("%s",data.name);
       pMove = searchInfoByData(list,data.name);
        if (pMove == NULL)
        {
             printf("δ�ҵ������Ϣ\n");
             system("pause");
        }else{
            printf("�����޸�ѧ������Ϣ��\n");
            scanf("%s\t%d\t%s\t%s\n",pMove->data.name,&pMove->data.age,pMove->data.sex,pMove->data.tel);
            printf("�޸ĺ����ϢΪ��\n");
            printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        }
        break;
    case 4:
       printf("-------------��ɾ����Ϣ��-------------------\n");
       printf("����ɾ����ѧ������:");
       scanf("%s",data.name);
       deleteAppoinNode(list,data.name);
        break;
    case 5:
       printf("-------------��������Ϣ��-------------------\n");
       printf("������ҵ�ѧ������:");
       scanf("%s",data.name);
       pMove = searchInfoByData(list,data.name);
        if (pMove == NULL)
        {
             printf("δ�ҵ������Ϣ\n");
             system("pause");
        }else
        {
            printf("����\t����\t�Ա�\t�绰\n");
            printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        }
        
        break;
    
    default:
    printf("ѡ�������������\n");
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
// �����������
//     struct Node* list = createlist();
//     insertNodeByHead(list,1);
//     insertNodeByHead(list,2);
//     insertNodeByHead(list,3);
//     insertNodeByHead(list,4);
//     printList(list);
//     printf("ɾ���ڵ�\n");
//     deleteAppoinNode(list,3);
//     printList(list);
//     printf("���ҽڵ�\n");
//     printf("%d\n",searchInfoByData(list,2)->data);


    system("pause");
    return 0;
}
