#pragma once
#include <string>
#include "User.h"//双引号！
#include "VerificationStrategy.h"
#include "EncryptStrategy.h"
class UserProxy:public User{
    EncryptStrategy* encStr;
    VerificationStrategy* verStr;
    RealUser* ruser;
public:
	UserProxy(RealUser* un,EncryptStrategy* an,
    VerificationStrategy* bn
    ): ruser(un)
     ,encStr(an),verStr(bn){};
	void sendMessage(std::string mes) {
        std::string Mes=encStr->encode(mes);
        ruser->sendMessage(Mes);//是void类型，不能够cout，况且里面已经包含cout
        //std::cout<<encStr->encode(mes)<<std::endl;
        std::cout<<verStr->verify(mes)<<std::endl;
}
};