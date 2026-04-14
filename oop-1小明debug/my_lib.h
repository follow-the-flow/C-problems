#ifndef MY_LIB_H
#define MY_LIB_H

#include <iostream>
#include <string>
void print();

void print(int x);

void print(bool x);

void print(const std::string s );

void print(const char* s);

void print(char c);

std::string input();

class Array {
    int size{};
    int a[100]{};
public:
    
    void append(int x);

    void pop();

    int getSize() const;
    int& operator[](int index){return a[index];}
    
};

void print(Array a);

#endif
