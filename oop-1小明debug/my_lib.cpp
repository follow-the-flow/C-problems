#include "my_lib.h"

void print() {
    std::cout << std::endl;
}

void print(int x) {
    std::cout << x << std::endl;
}

void print(bool x) {
    std::cout << (x ? "True" : "False" )<< std::endl;
}
void print(const char* s) {
    std::cout << s << std::endl;
}
void print(const std::string s) {
    std::cout << s << std::endl;
}

void print(char c) {
    std::cout << c << std::endl;
}

std::string input() {
    std::string s;
    std::cin >> s;
    return s;
}

// Array

void Array::append(int x) { if (size<100)a[size++] = x; }

void Array::pop() { 
    if(size>0)size--; }

int Array::getSize()const { return size; }

void print( Array a) {
    for (int i = 0; i < a.getSize(); i++)
        std::cout << a[i] << (i == a.getSize() - 1 ? '\n' : ' ');
}
