#include "Computer.h"
#include <string> 
bool Computer::operator< (const Computer& computer) {
	if (num < computer.num)
		return true;
	if (num > computer.num)
		return false;

	if (price < computer.price)
		return true;
	if (price > computer.price)
		return false;

	return false;
}

Computer& Computer::operator++ (){
	num++;
	return *this;
}


Computer& Computer::operator-- (){
	if(num>0){
		num--;
	}
	return *this;
}

ostream& operator<< (ostream& out, const Computer& computer) {
	out << computer.name << "-num-" << computer.num << "-price-" << computer.price;
	return out;
}
// 在 .cpp 文件中实现
Computer& Computer::addInfo(string n, int number, int p) {
    this->name = n;      // 修改当前对象的成员
    this->num = number;
    this->price = p;
    return *this;        // 返回当前对象本身的引用
}
Computer& Computer::setPrice(int number){
	this->price=number;
	return *this;
}
int Computer::getPrice(){
	return this->price;}

int Computer::getNum(){
	return this->num;
}
string Computer::getName(){
	return this->name;
}