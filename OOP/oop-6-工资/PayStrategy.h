#pragma once
#include <string>

class PayStrategy {		
	public:						
	virtual double pay(std::string name, double money)=0;
	virtual ~PayStrategy() = default;
};


class NormalStrategy : public PayStrategy {	
	double pay(std::string name, double money)override{
		return money;
	}
};

class SwiftStrategy : public PayStrategy {
	double pay(std::string name, double money)override{
		if(money<10000)return money-10;
		else if(money>=10000&&money<=20000) return money-money*0.001;
		else return money-20;
	}	

};

class BitcoinStrategy : public PayStrategy {
	double pay(std::string name, double money)override{
		return money-(name.size()+8)*0.01;
	}	

};
