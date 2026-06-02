#pragma once
#include <string>
#include <memory>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {
public:
    
//Calculator(std::shared_ptr<OccupationStrategy> a, std::shared_ptr<PayStrategy> b)
    //: a_(a), b_(b) {}
    //void setStrategyB(std::unique_ptr<PayStrategy> b) { std::unique_ptr<PayStrategy> b; }//注意使用move函数初始化

    double getSalary(double base, double bonus, double level)const {
        return a_->getSalary(base,  bonus,  level);}
    double pay(std::string name, double money){
        return b_->pay(name,money);
    }
   Calculator(OccupationStrategy* a, PayStrategy* b)
    : a_(a), b_(b) {}

private:
    OccupationStrategy* a_;
    PayStrategy* b_;

};