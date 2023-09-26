#include <iostream>
using namespace std;
class Base1 {
public:
    virtual void foo() {
        std::cout << "Base1::foo()" << std::endl;
    }
};

class Base2 {
public:
    virtual void foo() {
        std::cout << "Base2::foo()" << std::endl;
    }
};

class Derived : public  Base1, public  Base2 {
public:
    void foo() {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base1* b1 = new Derived();
    b1->foo(); // 输出 "Derived::foo()"
    // delete b1;

    Base2* b2 = new Derived();
    b2->foo(); // 输出 "Derived::foo()" // 多态 子类重写了父类的虚函数
    // delete b2;

    return 0;
}
