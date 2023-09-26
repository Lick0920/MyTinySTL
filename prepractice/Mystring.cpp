// 字符串类
#include <iostream>
#include<string>
#include<cstring>
#include"Mystring.h"
using namespace std;

MyString::MyString()
{
    this->str = NULL;
    this->len = 0;
}
MyString::MyString(const char *str)
{
    if (str == NULL)
    {
        this->str = NULL;
        this->len = 0;
    }
    else
    {
        this->len = strlen(str);
        this->str = new char[this->len + 1];
        strcpy(this->str, str);
    }
}
MyString::~MyString()
{
    if (this->str != NULL){
        std::cout << this->str << "执行析构" <<std::endl;
        delete this->str;
        this->str = NULL;
        this->len = 0;
    }
}

// 拷贝构造
MyString::MyString(const MyString &anotherstr){
    int len = anotherstr.len;
    this->str = new char[len+1];
    strcpy(this->str, anotherstr.str);
}

// 重载<<  ->类外实现 类内实现的话必须少传一个参数
// 这个不能加上 MyString 作用域 否则。
ostream & operator<<(ostream &out, const MyString &str) // 注意返回ostream 否则无法连续输出
{
    out << str.str; // 友元才能访问私有成员
    return out;
}

istream & operator>>(istream &is, MyString &str){
    // 将s之前的字符串释放,如果非空 先释放
    if (str.str!= NULL){
        delete[] str.str;
        str.str = NULL;
        str.len = 0;
    }
    char temp_str[4096] = {0};
    std::cin >> temp_str;
    int len = strlen(temp_str);
    str.str = new char[len+1];
    str.len = len;
    strcpy(str.str, temp_str);
    return is; // 链式编程
}

// 重载 &
char MyString::operator[](int index)
{
    return this->str[index];
}

MyString & MyString::operator=(const MyString &s2)
{
    // 四步 空间检查 自我赋值检查 释放原有空间 申请新空间
    if (this == &s2) // 自我赋值检查
    {
        return *this;
    }
    if (this->str != NULL){
        delete[] this->str; //回收必须用 delete[]
        this->str = NULL;
        this->len = 0;
    }
    this->len = s2.len;
    this->str = new char[this->len + 1]; // 申请新空间 new[]
    strcpy(this->str, s2.str);
    return *this;  // 实现连续赋值,返回指针的解引用。this是隐式指针，指向当前对象的地址 一般都用->
}
// 重载+
MyString MyString::operator+(MyString &s2){
    // tmp = new char[s1.len + s2.len + 1];
    MyString s3;
    s3.str = new char[this->len + s2.len + 1];  // .前面必须是实体；
    // -> 箭头 左边必须是指针
    s3.len = this->len + s2.len;
    strcpy(s3.str, this->str);
    strcat(s3.str, s2.str);
    //  = MyString(s1.str + s2.str);
    //  = s1.len + s2.len;
    // MyString s3(s1.str + s2.str);
    // std::cout << s3 << std::endl;
    return s3;
}

int main()
{

    MyString s1("abc");
    MyString s2("ddd");
    MyString s3;
    // std::cin >> s1;
    // std::cout << s1 << std::endl;

    std::cout << s1 + s2 << std::endl;
    // string s2 = "sbs";
    // std::cout << s1 << std::endl;
    // std::cout << s2 << std::endl;

    // MyString s3;
    // // std::cout << s3 << std::endl;
    // s3 = s1;
    // std::cout << s3 << std::endl;
    return 0;
}