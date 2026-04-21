#ifndef VEHICLE_H  // 如果没有定义过 VEHICLE_H
#define VEHICLE_H  // 那么就定义 VEHICLE_H.不要忘记头文件保护
#include<iostream>
using namespace std;

class Vehicle{
public:
  int wheel=0;
  int wing=0; 
  int set_wheel=0;
  int set_wing=0; 

void add_wheel(){wheel++;};
void add_wing(){wing++;};
bool finished(){
   if(wheel>=set_wheel&&wing>=set_wing)
    return true;
    return false;
};
void run(){
    if(set_wheel==3&&set_wing==2)
    cout<<"I am running and flying"<<endl;//换行好习惯！！！
    else if(set_wheel==2&&set_wing==0)
    cout<<"I am running"<<endl;
    else if(set_wheel==4&&set_wing==0)
    cout<<"I am running"<<endl;
};
void set_max_wheel_num(int n){set_wheel=n;};
void set_max_wing_num(int n){set_wing=n;};//赋值等于打错了！！
};
#endif