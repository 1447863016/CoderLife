#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    //rand()����һ���������rand()%a������һ��С��a�������
    //�����֣�����С�˸���ʾ
    srand((unsigned int)time(NULL));
    int a = 0;
    int b = 0;
    a = rand() % 100 + 1;
    cout <<"�������²������"<<endl;
    cin >> b;
    while (b != a)
    {
        if (b > a)
        {
            cout <<"����Ŀ��ֵ����������"<<endl;
            cin >> b;
        }
        if (b < a)
        {
            cout <<"С��Ŀ��ֵ����������"<<endl;
            cin >> b;
        }       
    }
    cout <<"���ˣ����ֵ�"<<endl;
    cout <<"a��ֵΪ"<<a<<endl;
    system("pause");
    return 0;
}