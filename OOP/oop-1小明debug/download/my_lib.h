#ifndef MY_LIB_H
#define MY_LIB_H
#include <string>
#include <iostream>

void print();

void print(int x);

void print(bool x);

void print(std::string s);

void print(const char* c);

void print( char c);

std::string input();

class Array {
    int size{};//所有元素都初始化成零
    int a[100]{};
public:
    void append(int x);

    void pop();

    int getSize();

    int operator[](int index) const { return a[index]; }

    friend void print(Array a);//第二种方法，友元声明
};

void print(Array a);

#endif
