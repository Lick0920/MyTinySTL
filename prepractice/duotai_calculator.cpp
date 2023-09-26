#include <iostream>
#include <string>
using namespace std;

// 开闭原则， 拓展新功能 多态的好处：不用修改源码
class Caculator
{
public:
    int getResult(char oper)
    {
        if (oper == '+')
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == '-')
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == '*')
        {
            return m_Num1 * m_Num2;
        }
        return 0;
    }
    int m_Num1;
    int m_Num2;

};

// 用多态实现计算器
class AbstractCaculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

class AddCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

class SubCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

class MulCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test01()
{
    Caculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    std::cout << "a + b = " << c.getResult('+') << std::endl;
    std::cout << "a - b = " << c.getResult('-') << std::endl;
}
void test02()
{
    AbstractCaculator *abc = new AddCaculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    std::cout << "a + b = " << abc->getResult() << std::endl;
    delete abc;
    abc = new SubCaculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    std::cout << "a - b = " << abc->getResult() << std::endl;
    delete abc;
}


int main()
{
    test01();
    test02();
    return 0;
}