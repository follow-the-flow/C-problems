#pragma once

#include <string>
#include <iostream>
class Animal{

    public:
    std::string name;
    Animal(std::string n): name(n) {
    };
    virtual ~Animal(){;};
    virtual void swim(){};
    virtual void speak(){};
    void action(){speak();swim();}
};