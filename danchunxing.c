#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)
#define m 2			//����Լ�����̸���
#define n 4			//������߱�������
double M = 1e6;
double A[m][n];		//�洢AԼ������
double C[n];		//�洢Ŀ�꺯����ֵϵ��C����
double b[m];		//�洢Լ��������Դϵ��b����
double CB[m];		//�洢������ϵ������
double seta[m];		//��ų���������ı仯���
double sigma[n];	//�洢�����������
double x[n];		//�洢���߱���
int num[m];			//�洢������������������
double Z = 0;		//��¼Ŀ�꺯��ֵ

void input();
void print();
int FindSwapInVar();		//ȷ���������
int FindSwapOutVar(int a);	//ȷ����������
void Iterate(int a, int b);	//��������

//ȷ������������������м����������ڵ���0ʱ����ǰ��Ϊ���Ž�
int FindSwapInVar()
{
	int i, k = 0;//��k�����������
	int flag = 1;
	double min = 0;
	for (i = 0; i < n; i++)
	{
		if (sigma[i] < 0)
		{
			flag = 0; break;
		}
	}
	if (flag == 1)//�ҵ��˿�
		return -1;
	for (i = 0; i < n; i++)//�ҳ����ļ�������
	{
		if (sigma[i] < min)//��min���ⰴ��sigma��С��Ϊ�������
		{
			min = sigma[i];
			k = i;
		}
	}
	return k;
}
//ȷ����������
int FindSwapOutVar(int a)
{
	int i, j;
	int flag = 1;
	int k = a;//a�������
	for (i = 0; i < m; i++)//���ĳ����С��0�ļ���������Ӧ��������������Ԫ�ء�0 ���������޽��
	{
		if (A[i][k] > 0)
		{
			flag = 0; break;
		}
	}
	if (flag == 1)
	{
		printf("�����Թ滮�������޽�⡢�����Ž⣡\n");
		return -1;
	}
	for (i = 0; i < m; i++)
	{
		if (A[i][k] > 0)
			seta[i] = b[i] / A[i][k];
		else seta[i] = M;//��A[i][k]��0��ʱ���ǲ���Ҫ���ǵ�
		//Ȼ���Ǹ��ݱ�ֵ��Сԭ������ ���Ը���Ӧ�Ŀ�һ���ܴ��M
	}
	double min = M;
	for (i = 0; i < m; i++)//�õ���������
	{
		if (min >= seta[i])
		{
			min = seta[i];
			j = i;
		}
	}
	num[j] = k + 1;
	CB[j] = C[k];
	return j;
}
//�������㣬�����µĵ����α�
void Iterate(int p, int q)
{
	int i, j, r, c;//row�� column�У�r,l)����ת��Ԫ
	r = p;//�к�		p�ǳ�������
	c = q;//�к�		q���������
	double temp1 = A[r][c];
	double temp2, temp3;
	//��׼������
	b[r] /= temp1;
	for (j = 0; j < n; j++)
		A[r][j] /= temp1;
	for (i = 0; i < m; i++)//��׼��������
	{
		if (i != r)
			if (A[i][c] != 0)
			{
				temp2 = A[i][c];
				b[i] -= temp2 * b[r];//b[r]ת��Ԫ��Ӧb
				for (j = 0; j < n; j++)
					A[i][j] -= temp2 * A[r][j];//A[r][j]��ת��Ԫ��Ӧ��
			}
	}
	//�ҵĵ�������
	temp3 = sigma[c];
	for (i = 0; i < n; i++)
	{
		sigma[i] -= A[r][i] * temp3;
	}

}
//���뺯����Լ�������ļ���ϵ������A����ʼ�����������ִ���
//����Լ����������Դϵ��b��Ŀ�꺯����ֵϵ��C
void input()
{
	int i, j;
	printf("�밴˳�����뷽�����ϵ������A����%d��%d�У�:\n", m, n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%lf", &A[i][j]);
	printf("�밴˳�������ʼ�������������������ִ���num����\n");
	for (i = 0; i < m; i++)
		scanf("%d", &num[i]);
	printf("�밴˳������Լ����������Դϵ��b����\n");
	for (i = 0; i < m; i++)
		scanf("%lf", &b[i]);
	printf("�밴˳������Ŀ�꺯���ļ�ֵϵ��C����\n");
	for (i = 0; i < n; i++)
		scanf("%lf", &C[i]);
	for (i = 0; i < n; i++)
		sigma[i] = C[i];
	for (i = 0; i < m; i++)
		CB[i] = C[num[i] - 1];//��ʾ��������ϵ������Ϊ�����������ת��Ϊ�������
}
//���
void print()
{
	int i, j;
	printf("\n--------------------------------------------------------------------------\n");
	for (i = 0; i < m; i++)
	{
		printf("%8.2f\tX(%d) %8.2f ", CB[i], num[i], b[i]);
		for (j = 0; j < n; j++)
			printf("%8.2f ", A[i][j]);
		if (i != m - 1)
			printf("\n");
	}
	printf("\n--------------------------------------------------------------------------\n");
	printf("\t\t ��          ");
	for (i = 0; i < n; i++)
		printf(" %8.2f", sigma[i]);
	printf("\n--------------------------------------------------------------------------\n");
}
int main()
{
	int i, j, k = 1;
	int p, q;//q�ǻ������
	input();
	printf("\n--------------------------------------------------------------------------\n");
	printf("\tCB\tXB\tb\t");
	for (i = 0; i < n; i++)
		printf(" X(%d)\t", i + 1);
	for (i = 0; i < n; i++)
		x[i] = 0;
	while (1)
	{
		q = FindSwapInVar();
		if (q == -1)
		{
			print();
			printf("\n��ϲ���õ����Ž⣡\n");
			printf("���н�Ϊ��");
			for (j = 0; j < m; j++)
				x[num[j] - 1] = b[j];//��Ϊx[n]��Ӧ��n+1�����߱���
			for (i = 0; i < n; i++)
			{
				printf("x%d=%.2f ", i + 1, x[i]);
				Z = Z + x[i] * C[i];
			}
			printf("\n����ֵΪ��Z* = %.2f", Z);
			break;
		}
		print();
		p = FindSwapOutVar(q);
		printf("\n���е�%d�ε���,����Ԫλ��Ϊ(%d,%d)\n", k++, p + 1, q + 1);
		if (q == -1) break;
		Iterate(p, q);
	}
        system("pause");

}

