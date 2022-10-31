#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int map[4][4]={0};
int score=0;
int movenum=-1;
char input;
int gameover=1;
int change=1;//判断数组是否改变，0不变

void menu()
{
	system("CLS");//清屏
	int i=0,j=0;
	printf("                 欢迎来到2048\n");
	printf("     ----------------------------------------\n");
	printf("     W——UP S——DOWN A——LEFT D——RIGHT\n");
	printf("     Please enter 0 if you do not want paly.\n");
	printf("     MOVE:%d          SCORE:%d\n",movenum,score);
	printf("     Made by PGG\n");
	printf("     \n     |-------------------------------------------|\n");
    for ( i = 0; i <= 3; i++)
    {
    	for ( j = 0;  j<= 3; j++)
    	{
       		printf("     ");
    		if (map[i][j]==0)
    			printf("|     ");
    		else
    			printf("|%5d",map[i][j]);
    	}
    	printf("     |\n     |-------------------------------------------|\n");
    }
}

int randIntNum()
{//再数组里随机生成一个地址并赋值
	int i,j,n;
	if (change>=1)
		{
			do{
				i=((unsigned)rand())%4;
				j=((unsigned)rand())%4;
			}while(map[i][j]!=0);
			n=((unsigned)rand())%2;
			if (n==0)
				map[i][j]=n+2;
			else
				map[i][j]=n+3;
			movenum++;
		}
}

int main()
{
	srand(time(NULL));
	menu();
	randIntNum();
    return 0;
}
