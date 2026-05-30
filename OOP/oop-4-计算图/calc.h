#ifndef CALC_H
#define CALC_H
#include "Operator.h"
class Constant: public Value
{
    int val;
public:
    Constant(int v) : val(v) {};
int calc() override {
    return val;  // 更清晰
}
void setValue(int v) { val = v; } //为后面的modify留下修改接口
};

class Plus: public Operator
{
public:
    Plus(Value *r1, Value *r2) : Operator(r1, r2) {}
int calc() override {
    return getV1()+getV2();  // 更清晰
}
};

class Sub: public Operator
{
public:
    Sub(Value *r1, Value *r2) : Operator(r1, r2) {}
int calc() override {
    return getV1()-getV2();  // 更清晰
}
};

class Multiply: public Operator
{
public:
    Multiply(Value *r1, Value *r2) : Operator(r1, r2) {}
int calc() override {
    return getV1()*getV2();  // 更清晰
}
};

class Print : public Value {
    Value *target;
public:
    Print(Value *t) : target(t) {}
    
    int calc() override {
        return target->calc();  // 不输出，只返回值
    }
};

class Modify : public Value {
    Constant *target;  // 必须是 Constant*，才能调用 setValue
    int newVal;
public:
    Modify(Constant *t, int v) : target(t), newVal(v) {
        target->setValue(newVal);}
    //初始化的同时调整一下就可以，和calc操作解耦  
    int calc() override { 
        return target->calc();
    }
};
#endif