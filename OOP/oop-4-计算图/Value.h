#ifndef VALUE_H
#define VALUE_H

class Value
{
public:
    virtual int calc() = 0;
	virtual ~Value() {};
};//是一个抽象类，等待覆盖
#endif
