#include <iostream>
#include <string>
#include "Value.h"
#include "Operator.h"
#include "calc.h"
int n;
Value *v[100001];//指向value的指针数组，每一个成员都是value*，抽象类
std::string s;
int main()
{
    std::cin >> n;
    int a, b;
    for(int i = 1; i <=n; ++i)
    {
        std::cin >> s;
        if(s == "Constant")
        {
            std::cin>>a;
            v[i]=new Constant(a) ;


        }
        else if(s == "Plus")
        {
            std::cin>>a>>b;
            v[i]=new Plus(v[a],v[b]) ;

        }
        else if(s == "Sub")
        {
            std::cin>>a>>b;
            v[i]=new Sub(v[a],v[b]) ;
        }
        else if(s == "Multiply")
        {
            std::cin>>a>>b;
            v[i]=new Multiply(v[a],v[b]) ;
        }
        else if(s == "Print") {
    int t;
    std::cin >> t;
    v[i] = new Print(v[t]);
    std::cout << v[i]->calc() << std::endl;  // 只在这里输出
    }
        else if(s == "Modify") {
        int t, val;
         std::cin >> t >> val;
        v[i] = new Modify((Constant*)v[t], val);
        v[i]->calc();  // 立刻执行！
    }
    }
	return 0;
}
