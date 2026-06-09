#pragma once
# include <string>
#include <algorithm>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
	virtual ~EncryptStrategy() = default;
};
class InsertStrategy:public EncryptStrategy{
public:
	std::string encode(std::string mes) override{
		std::string res;
		for(char n :mes){
			//n=n+'#';是在增加数值，不是再进行操作
			res+= n;
			res+='#';
		}
		return res;

	}
};
class InvertStrategy:public EncryptStrategy{
public:
	std::string encode(std::string mes) override{
    std::reverse(mes.begin(), mes.end());
    return mes;

	}
};
