#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    //rand()生成一个随机数，rand()%a，生成一个小于a的随机数
    //猜数字，大了小了给提示
    srand((unsigned int)time(NULL));
    int a = 0;
    int b = 0;
    a = rand() % 100 + 1;
    cout <<"输入您猜测的数字"<<endl;
    cin >> b;
    while (b != a)
    {
        if (b > a)
        {
            cout <<"大于目标值，重新输入"<<endl;
            cin >> b;
        }
        if (b < a)
        {
            cout <<"小于目标值，重新输入"<<endl;
            cin >> b;
        }       
    }
    cout <<"对了，好兄弟"<<endl;
    cout <<"a的值为"<<a<<endl;
    system("pause");
    return 0;
}