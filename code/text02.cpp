#include <iostream>
#include <string>
using namespace std;
#define day 7//定义宏常量或const修饰
//编译器默认小数为double类型，需要使用float变量后加f
//默认情况下 输出一个小数为6位有效数字
int main()
{
    int a = 10;
    const int b = 12;
    cout <<sizeof(short)<<endl;
    cout <<sizeof(int)<<endl;
    cout <<sizeof(long int)<<endl;
    cout <<sizeof(long long)<<endl;
    cout <<sizeof(float)<<endl;
    cout <<sizeof(double)<<endl;
    cout <<"aaaaaaa\tone week has"<<day<<"days"<<endl;
    char ch = 'a';//''只能引用一个字符，不能多个，多个需要字符串
    cout <<int(ch)<<endl;
    int ch1 = 97;
    cout <<(char)ch1<<endl;
    string str1 = "fuck";
    char str2[] = "fuck you too";
    cout <<str1<<endl;
    cout <<str2<<endl;
    a = 0;
    while (a < 1000000)
    {
        cout <<a<<endl;
        a ++;
    }
    
    system("pause");
    return 0;
}