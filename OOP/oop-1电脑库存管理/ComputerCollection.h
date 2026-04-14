#ifndef __ComputerCOLLECTION_H__
#define __ComputerCOLLECTION_H__

#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;

class ComputerCollection
{
private:
	int computerNum = 0;
	Computer* computers[201];//创建了一个包含 201 个指针的数组
	
public:
	~ComputerCollection() {
    for (int i = 0; i < computerNum; i++) {
        delete computers[i];
    }
}
	friend istream& operator>> (istream& in, ComputerCollection& sc);
	friend ostream& operator<< (ostream& out, const ComputerCollection& sc);

	Computer& operator[] (const string& name);
	void sortByScore();
	
	Computer* has_name(string p);
};

#endif
