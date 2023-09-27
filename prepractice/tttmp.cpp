#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int a = 99;
    // 类型转换 static_cast 用于基本数据类型; 具有继承关系的指针和引用
    // dynamic_cast 用于类的指针和引用，转换失败返回NULL
    //              子类可以转换为父类，父类不能转换为子类
    // const_cast    用于指针和引用的const转换
    // reinterpret_cast 用于指针和引用的二进制转换
    char c = static_cast<char>(a);
    std::cout << c << std::endl;
}