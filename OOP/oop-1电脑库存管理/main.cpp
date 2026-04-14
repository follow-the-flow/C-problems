#include "Computer.h"
#include "ComputerCollection.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  ComputerCollection cc;//cc是一个用于记载所有电脑的情况的类
  for(int i = 0; i < n; i++){
    cin >> cc;//重载》》
  }

  int m;
  cin >> m;

  for(int i = 0; i < m; i++){
    string opt, nameA, nameB;
    cin >> opt;
    if (opt == "ASK"){
        cin >> nameA >> nameB;
        if(cc[nameA] < cc[nameB]){//重载大于号,同时重载【】
          cout << cc[nameB] << "\n" << cc[nameA] << "\n" << endl ;//\n是换行
        }else{
          cout << cc[nameA] << "\n" << cc[nameB] << "\n" << endl;
        }
    } else if (opt == "SELL"){
        cin >> nameA;
        --cc[nameA];//为什么能够直接对这个数据行进行加减？
        cout << cc[nameA] << "\n" << endl;        
    } else if (opt == "BUY"){
        cin >> nameA;
        ++cc[nameA];
        cout << cc[nameA] << "\n" << endl;
    } else if (opt == "CHANGE"){
        string price;
        cin >> nameA >> price;
        cc[nameA].setPrice(atoi(price.data()));//类中有一个调整价格的函数
        cout << cc[nameA] << "\n" << endl;
    } else{
      continue;
    }
  }
  
  cc.sortByScore();//类中有一个排序的函数
  cout << cc;//重载了<<

  return 0;
}