//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
/**
 * C++在创建对象的时候可以采用两种方式：（类名为Test） （1）Test test （2）Test *pTest =new Test（）；
 * 区别：对象内容所在的内存空间不同，
 * 1）从静态存储区分配：内存在程序编译时期就已经分配好了，这块内存在程序整个运行期间都存在，例如全局变量，static变量
 * 2）从栈上创建：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束后在将这些局部变量的内存空间回收，
 *   分配内存空间效率很高，但是分配的内存容量有限
 * 3）从堆上分配：程序在运行的时候用malloc或new申请任意多少内存，需要自行调用free或者delete进行内存释放
 *
 *
 *  new创建对象是创建在堆中的
 *  不使用new创建对象，对象的内存空间是在栈中，起作用范围只是在函数内部，
 *
 *
 *
 */
//
#include "iostream"
using namespace std;

class Parent{
public:
    //父类函数必须要有virtual关键字
    Parent();
    ~Parent();


    virtual void fun(){
        cout<< "parent function"<<endl;
    }
};
Parent::Parent()
{

};

Parent::~Parent() {
};
class Child : public  Parent
{
public:
    void fun(){
        cout<<"child function"<<endl;
    }
};



int main()
{
    Parent *p =NULL; //create parent pointer
    Parent parent;// create parent instance
    Child child; // create child instance

    p =new Parent();
//    p =&parent;//指向parent 的指针
    cout<<"parent address:"<<&p<<endl;
    p->fun();//执行parent的fun函数
    p =new Child();
//    p=&child; //指向子类的对象
    cout<<"child address:" <<&p<<endl;
    p->fun();//执行的是子类的fun函数


    cout<<"对象调用方法"<<endl;

    parent.fun();

    child.fun();

    return 0;




}