#include "Operator.h"

Operator::Operator(Value *a, Value *b) : v1(a), v2(b) {}

int Operator::getV1()
{
    return v1->calc();
}
int Operator::getV2()
{
    return v2->calc();
}
