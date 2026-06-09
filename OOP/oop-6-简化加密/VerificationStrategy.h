#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
	virtual ~VerificationStrategy() = default;
};
class PrefixStrategy :public VerificationStrategy{
public:
	 std::string verify(std::string mes)override{
    std::string ans;
	for(int i=0;i<3;i++){
		ans+=mes[i];
	}
	return ans;
	 };

};
class IntervalStrategy:public VerificationStrategy{
public:
	std::string verify(std::string mes) override{
		std::string ans;
	for(int i=0;i<mes.length();i++){
		if(i%2==0)
		ans+=mes[i];
	}
	return ans;
	};

};