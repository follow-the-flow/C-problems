#include "my_lib.h"
#include <string>
void print() {
    std::cout << std::endl;
}

void print(int x) {
    std::cout << x << std::endl;
}

void print(bool x) {
    std::cout << (x ? "True" : "False") << std::endl;
    //运算符优先级
}

void print(std::string s) {
    std::cout << s << std::endl;
}

void print(const char* c) {
    std::cout << c << std::endl;
}
void print( char c) {
    std::cout << c << std::endl;
}

std::string input() {//不要乱用auto
    std::string s;
    std::cin >> s;
    return s;
}

// Array

void Array::append(int x) { a[size++] = x; }

void Array::pop() { size--; }

int Array::getSize() { return size; }//没有加上Array的类声明

void print(Array a) {
    for (int i = 0; i < a.getSize(); i++)
        //std::cout << a[i] << (i == a.getSize() - 1 ? '\n' : ' '); 
        //问题是访问私有成员
        std::cout << a[i] << (i == a.getSize() - 1 ? '\n' : ' ');
        //第一个方法是重载【】运算符，使其变成公有成员函数

}
