#pragma once
#include <cstring>
#include <algorithm>
#include <iostream>
//实现<<的重载
//深拷贝：为目标对象new一块全新的内存
class PalString{
    char* mes;
    char* create()const{
        /*std::string mes1=mes;
        std::string mes2=mes;
        std::string mes3;
        std::reverse(mes2.begin(),mes2.end());//void
        mes3=mes1+mes2;
        return mes3;*/ //char*可以转化成string，但是string难以转化
        int len=std::strlen(mes);
        char* mes1=new char[2*len+1];
        for(int i=0;i<len;i++){
            mes1[i]=mes[i];
        }
        for(int i=len;i<2*len;i++){
            mes1[i]=mes[2*len-1-i];
        }
        mes1[2*len]='\0';//有效索引是0-2len
        return mes1;//转移了所有权，不需要手动删除
    }
public:
    PalString(const char* m){//不会修改m
            int len = std::strlen(m); //strlen操作以\0结尾的          // 计算长度
            mes = new char[len + 1]; // 分配空间（含 '\0'）
            std::strcpy(mes, m);
    };
    ~PalString(){
        delete[] mes;
        mes=nullptr;};
    char*getString(){
        //return mes;不对，根据题目的要求，是要直接返回回文
        return create();
    }
    void changeString(const char* ver){
        delete[] mes;//安全手动释放
        int len=std::strlen(ver);
        mes=new char[len+1];
        std::strcpy(mes,ver);
    }
    //重载运算符,返回的是输出流的引用
    friend std::ostream& operator<<(std::ostream& os,const PalString &obj){
        //friend让他可以访问私有成员
        char* p=obj.create();//const类对象只能调用带有后置const的函数
        os<<p;
        delete[] p;
        return os;//return之后就直接结束了，不可以在他的后面做删除
    }
    PalString(const PalString& other){//因为对象比较大&，避免不必要的拷贝，使用const，防止修改
        int len=std::strlen(other.mes);
        mes=new char[len+1];
        std::strcpy(mes,other.mes);
    }
    PalString& operator=(const PalString& other){
        if(this==&other) {//排除如果是自赋值的情况
        return *this;}
        delete[]mes;//这是直接释放这一块内存，如果不是立刻直接给赋值
        //一般会加上 mes=nullptr
        
            int len=std::strlen(other.mes);
            mes=new char[len+1];
            std::strcpy(mes,other.mes);
             return *this;//返回所有成员，而非单独的mes指针

    }


};