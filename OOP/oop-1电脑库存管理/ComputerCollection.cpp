#include "ComputerCollection.h"
#include <algorithm>
#include <string>
istream& operator>> (istream& in, ComputerCollection& cc)
{
	string temp;
	in >> temp;
	string name = "";
	
	int i = 0;
	int num = 0;
	for (; i < temp.length(); ++i) {
		if (temp[i] == '-') {
			++i;
			num = int(temp[i] - '0');
			++i;
			break;
		}
		name += temp[i];
	}
	for (; i < temp.length(); ++i) {
		if (temp[i] == '-') {
			++i;
			break;
		}
		num = num * 10 + int(temp[i] - '0');
	}
	
	int price = 0;
	for (; i < temp.length(); ++i) {
		price = price * 10 + int(temp[i] - '0');
	}

	Computer* p = cc.has_name(name);
	if (p == nullptr) {
		p = new Computer();
		cc.computers[cc.computerNum] = p;
		cc.computerNum++;
	}
	p->addInfo(name, num, price);
	
	return in;
}

ostream& operator<< (ostream& out, const ComputerCollection& cc)
{
	for (int i = 0; i < cc.computerNum; ++i) {
		out << *(cc.computers[i]) << endl;
	}
	return out;
}

Computer& ComputerCollection::operator[](const string& name)
{
	return *(this->has_name(name));
}



void ComputerCollection::sortByScore() {
    // std::sort 需要三个参数：起始地址，结束地址，以及比较规则
    std::sort(this->computers, this->computers + this->computerNum, [](Computer* a, Computer* b) {
        // 1. 如果库存不同，库存高的优先
        if (a->getNum() != b->getNum()) {
            return a->getNum() > b->getNum();
        }
        // 2. 如果库存相同，价格高的优先
        return a->getPrice()> b->getPrice();
    });
}

Computer* ComputerCollection::has_name(string p){
	for(int i=0;i<this->computerNum;i++){
			//if(this->computers[i].name==p){ 
			if(this->computers[i]->getName()==p){
				//computers[i]已经是一个指针了
				
				return this->computers[i];
			}
		}
		return nullptr;
	}