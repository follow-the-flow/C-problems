#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
#include <string>
using namespace std;

class Computer
{
private:
	string name;
	int num = 0;
	int price = 0;

public:
	bool operator< (const Computer& Computer);
	Computer& operator++ ();
	Computer& operator-- ();
	Computer& setPrice(int number);
	int getPrice();
	int getNum();
	string getName();
	Computer& addInfo(string n, int number, int p);
	friend ostream& operator<< (ostream& out, const Computer& computer);
};

#endif
