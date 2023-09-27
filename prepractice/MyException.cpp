#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include <exception>
#include <string>

class MyException : public std::exception {
public:
    MyException(const std::string& msg) : m_msg(msg) {}
    const char* what() const noexcept override {
        return m_msg.c_str();
    }
private:
    std::string m_msg;
};

class MyDerivedException : public MyException {
public:
    MyDerivedException(const std::string& msg) : MyException(msg) {}
    const char* what() const noexcept override {
        return "MyDerivedException";
    }
};

int main(){
    try {
        throw MyDerivedException("MyDerivedException");
    } catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}