#include <iostream>
using namespace std;
int main()
{
    int sroce = 0;
    cout << "输入分数" <<endl;
    cin >> sroce;
    cout << "输入分数是" <<sroce<<endl;
    if (sroce > 600)
    {
        cout <<"考上了"<<endl;
    }else{cout <<"寄了"<<endl;}
    
    
    system("pause");
    return 0;
}