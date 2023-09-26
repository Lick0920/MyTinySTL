#include <iostream>
// 实现智能指针
template <typename T>
class MySmartPointer
{
private:
    T* ptr;
    size_t* ref_count;// 无符号整型 表示对象大小
public:
    // 构造函数
    MySmartPointer(): ptr(nullptr), ref_count(nullptr){}
    // 显式构造函数，允许隐形类型转换，创建一个智能指针并管理指定的对象
    explicit MySmartPointer(T* p): ptr(p), ref_count(new size_t(1)){}  // ptr是 T的指针

    // 拷贝构造函数,创建新智能指针 并共享同一对象
    MySmartPointer(const MySmartPointer<T>& other): ptr(other.ptr), ref_count(other.ref_count)
    {
        if (ref_count)
        {
            (*ref_count)++;  // 先加
        }
    }
    // 移动构造函数，从另一个智能指针中窃取资源
    MySmartPointer(MySmartPointer<T>&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // 析构函数
    ~MySmartPointer()
    { // ref_count
        std::cout << "析构函数调用 没删除资源" << std::endl;
        if (ref_count && --(*ref_count) == 0) //引用为0时 删除资源
        {
            delete ptr;
            delete ref_count;
            std::cout << "析构函数调用,删除资源" << std::endl;
        }
    }
        // 重载箭头运算符 ->  像指针一样访问被管理对象。
    T* operator->() // 返回T类型的指针
    {
        return ptr;
    }

    // 重载 = 允许指针赋值 改变指针指向 ，使两个智能指针共享同一对象
    MySmartPointer<T>& operator=(const MySmartPointer<T>& other)
    {
        if (this != &other) // 记得释放this指针 
        {
            if (this->ref_count && --(*ref_count) == 0)
            {
                delete ptr;  // 加不加this 指针都行
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count)
            {
                ++(*ref_count); // 引用计数加1
            }
        }
        return *this;
    }


    // 重载解引用运算符 *  像指针一样访问被管理对象。
    T& operator*() //返回T类型的引用,返回T对象本身
    {
        return *ptr;
    }

    size_t use_count()
    {
        return ref_count ? *ref_count : 0;
    }
};


int main() {
    MySmartPointer<int> sp1(new int(42)); // 创建智能指针，管理一个整数对象
    MySmartPointer<int> sp2 = sp1; // 使用拷贝构造函数创建一个新智能指针，共享同一对象
    MySmartPointer<int> sp3;
    sp3 = sp1; // 使用赋值运算符，仍然共享同一对象

    // 输出智能指针的内容和引用计数
    std::cout << "sp1: " << *sp1 << ", Use count: " << sp1.use_count() << std::endl;
    std::cout << "sp2: " << *sp2 << ", Use count: " << sp2.use_count() << std::endl;
    std::cout << "sp3: " << *sp3 << ", Use count: " << sp3.use_count() << std::endl;

    return 0;
}
