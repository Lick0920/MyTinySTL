#include <iostream>
using namespace std;
class MyString
{
public:
    MyString(); // 默认构造
    MyString(const char *str);
    MyString(int len);//生成一个长度为len的字符串
    MyString(const MyString &str);//拷贝构造函�?

    bool operator==(const MyString &str); //
    bool operator!=(const MyString &str);
    MyString & operator=(const MyString &str);
    MyString operator+(const MyString &str);

    // 重载 []
    char operator[](int index);
    // 重载 + 
    MyString operator+(MyString &s2); //引用传递-》 节省拷贝构造的空间
    //重载<< >>
    friend ostream &operator<<(ostream &out, const MyString &str);
    friend istream &operator>>(istream &in, MyString &str);

    ~MyString();
private:
    int len;
    char *str;
    //重载 操作? == + << >> = 
};
