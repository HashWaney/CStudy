//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "iostream"
using namespace std;

class Parent{
public:
    //父类函数必须要有virtual关键字
    virtual  void fun(){
        cout<< "parent function"<<endl;
    }
};

class Child : public  Parent
{
    void fun(){
        cout<<"child function"<<endl;
    }
};



int main()
{
    Parent *p =NULL; //create parent pointer
    Parent parent;
    Child child;

    p =&parent;//指向parent 的指针
    cout<<"parent address:"<<&p<<endl;
    p->fun();//执行parent的fun函数
    p=&child; //指向子类的对象
    cout<<"child address:" <<&p<<endl;
    p->fun();//执行的是子类的fun函数


    cout<<"对象调用方法"<<endl;


    return 0;




}