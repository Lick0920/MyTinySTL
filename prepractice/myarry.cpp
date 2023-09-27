#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
    this->m_capacity = capacity;
    this->m_size = 0;
    this->pAddress = new T[this->m_capacity];
    }
    MyArray(const MyArray<T>& arr){
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++){
            this->pAddress[i] = arr.pAddress[i];
    }
    }
    T& operator[](int index){
        return this->pAddress[index];
    }
    MyArray<T>& operator=(const MyArray<T>& arr){
        if(this->pAddress != NULL){
            this->m_capacity = 0;
            this->m_size = 0;
            delete[] this->pAddress;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[this->m_capacity];
        for(int i=0; i<this->m_size;i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    ~MyArray(){
        if(this->m_capacity != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
            printf("析构函数调用\n");
        }
    }
    void push_back(T& data){
        if(this->m_capacity == this->m_size){
            return;
        }
        // 对象元素必须能被拷贝；否则，无法放入容器中
        // 如果成员有指针，必须深拷贝！
        this->pAddress[this->m_size] = data;
        this->m_size++;
        return;
        
    }

    void push_back(T&& data){
        if(this->m_capacity == this->m_size){
            return;
        }
        else{
            this->pAddress[this->m_size] = data;
            this->m_size++;
            return;
        }
    }

    int m_size;
    int m_capacity;
    T* pAddress;
};

int main(){
    // 容器都是值语义，不是引用语义；放入容器的对象会被复制，而不是被引用
    MyArray<float> arr1(5);
    float a = 10.0, b = 20.0;
    // 不能对右值引用
    // 临时变量 只能在当前使用 arr1.push_back(10)
    // 右值引用是 C++11 中一个非常重要的特性，它可以支持移动语义和完美转发，提高程序的性能和灵活性。
    arr1.push_back(a);
    arr1.push_back(b);
    arr1.push_back(1000);
    // 容器
    MyArray<float> arr2(arr1);
    MyArray<float> arr3(5);
    arr3 = arr2;
    for(int i=0; i<arr2.m_size; i++){
        std::cout << arr2[i] << arr3[i] << std::endl;
    }
    return 0;
}