#include <iostream>
#include <vector>
#include <string>
#include "PalString.h"
using namespace std;
int main(){
	vector<PalString> palstring_list;//palstring只负责一个
	int n, m;
	string str;
	cin >> n;
	getline(cin, str);
	for (int i = 0; i < n; ++i){
		getline(cin, str);
		PalString palstring{str.c_str()};//构造函数,后者是一种const chr*形态的指针
		palstring_list.push_back(palstring);
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		int tmp, k, k2;
		cin >> tmp;
		if (tmp == 0){
			cin >> k;
			cout << palstring_list[k].getString() <<endl;
		}else if (tmp == 1){
			cin >> k;
			getline(cin, str);
			getline(cin, str);
			palstring_list[k].changeString(str.c_str());
		}else if (tmp == 2){
			cin >> k;
			PalString palstring{palstring_list[k]};
			palstring_list.push_back(palstring);
		}else{
			cin >> k;
			cout << palstring_list[k] << endl;
		}
	}
}