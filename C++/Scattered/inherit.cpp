//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
/**
 * 1) public 继承方式
 *  基类中所有public 成员在派生类中为public属性
 *  基类中所有protected成员在派生类中为protected属性
 *  基类中所有private成员在派生类中不能使用
 *
 * 2) protected继承方式
 *  基类中所有的public成员在派生类中为protected属性
 *  基类中所有的protected成员在派生类中为protected属性
 *  基类中所有private成员在派生类中不能使用
 *
 * 3）private继承方式
 *  基类中的所有public成员在派生类中为private属性
 *  基类中的所有protected成员在派生类中为private属性
 *  基类中的所有private成员在派生类中不能使用
 *
 */
//
#include "printf.h"
#include "stdio.h"
#include "iostream"
#include "cstdio"
using namespace std;
class People{
public:
    void setName(const char* name){
        m_name= name;
    }
    void setAge(int age)
    {
        m_age=age;
    }
    const char *getName() const
    {
        return m_name;
    }
    int getAge() const {
        return m_age;
    }

private:
    const char* m_name;
    int m_age;
};
//public继承方式
class Student:public People{
public:
    void setScore(float score)
    {
        m_score=score;
    }
    float getScore() const {
        return m_score;
    }

private:
    float m_score;
};
int  main1()
{
    Student s;
    s.setName("hash");
    s.setAge(12);
    s.setScore(22.2);
    printf("name:%s,age:%d,score:%g\n",s.getName(),s.getAge(),s.getScore());
    return 0;
}


/*************using 来改变权限的问题*******************/
class A {
public:
    void setMa(int ma)
    {
        m_a=ma;
    }
    int getMa(){
        return  m_a;
    }

protected:
    int m_a;
    float m_b;
    float m_c;
private:
    char *m_d;

};

class B : public A{

public:
    using A::m_a;
protected:
    using A::m_b;
    //using A::m_d;基类的private成员在派生类不可见
private:
    using A::m_c;

};

int main2()
{
    A a;
    B b;
    b.m_a=1;
    a.setMa(b.m_a);
    cout<<"A m_a: "<<a.getMa()<<endl;
    return 0;

}


//---------派生类 覆盖子类的方法------------
class X {
public:
    void func()
    {
        printf("class X :func()\n");

    }

protected:
    void funcPro()
    {
        printf("class X: funcPro\n");
    }
private:
    void funcPri()
    {
        printf("class X :funcPri\n");
    }
};
class SX : public X
{
public:
    void func()
    {
        printf("class SX: func()\n");
    }

};

int main3()
{
    SX sx;
    sx.func();
//    sx.X::funcPri();
    sx.X::func();//派生类调用基类的成员方法
    return 0;
}

class SS {
public:
    void func()
    {
        printf("class SS: func()\n");
    }
    void func(int)
    {
        printf("class SS: func(int)\n");
    }
};

class SSX :public SS{
public:
    int a;
    void func(char)
    {
        printf("class SSX : func(char)\n");
    }
    void func(float)
    {
        printf("class SSX: func(float)\n");
    }
};

int main4()
{
    SSX ss;
    ss.func('A');
    ss.func(1.f);
    ss.a=1;
    //ss.func(); 无法调用基类的成员函数
   // ss.func(10);
}

//----------内存模型----------
//没有继承关系时：成员变量和成员函数会分开存储，成员变量存储在栈，堆，全局数据区，而成员函数存储在代码区
//有继承关系时：派生类的内存模型可看成基类成员变量和新增成员变量的总和，而所有成员函数仍然存储在代码区，由所有对象共享


//////////////////////////////////构造函数start///////////////////////////////////////////////
class Basic{
public:
    Basic(): basic(1){}

protected:
    int basic;

};
class BasicA:public Basic{
public:
    BasicA():Basic(),basicA(2){}
protected:
    int basicA;
};

class BasicB:public BasicA{
protected:
    int basicB;
public:
    BasicB():BasicA(),basicB(3){}
};
class BasicC:public BasicB{
protected:
    int basicC;
public:
    BasicC():BasicB(),basicC(4){}
};

class BasicD:public BasicC{
protected:
    int basicD;
public:
    BasicD():BasicC(),basicD(5){}
};
int main5()
{
    BasicD d;
    printf("sizeof(d) = %lu\n", sizeof(d));
    printf("Basic::basic=%d,BasicA::basicA=%d,BasicB::basicB=%d,BasicC:basicC=%d,BasicD::basicD=%d\n-------Address Basic =%p",
            *(int*)&d,
            *(int*)((long)&d+4),
            *(int*)((long)&d+8),
            *(int*)((long)&d+12),
            *(int*)((long)&d+16),(int*)&d);
    return 0;
}
/////////////////////////////////构造函数end/////////////////////////////////////////////////////////////////
/********

1。类的构造函数不能被继承（即使被继承，其名称和派生类名称不一样，不能作为派生类的构造函数，当然更不能成为普通的成员函数）
2。在派生类的构造函数中调用基类的构造函数，派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类，通过派生类创建对象
时必须要调用基类的构造函数

class A{
public:
    A(){
        printf("class_A A()\n");
    }
    A(int){
        printf("class_A A(int)\n");

    }

}

class B :public A{
public:
    B(){
        printf("class_B B()\n");
    }
    B(char){
        printf("class_B B(char)\n");
    }

}
class C:public B{

public:
    C():B('A'){
        printf("class_C C()\n");
    }


}

int main(){
    C c;
    return 0;

}

********/
//-======析构函数========
//析构函数也不能继承，在派生类的析构函数中不能显示地调用基类的析构函数，因为每一个类只有一个析构函数，编译器知道如何选择，
//析构函数的执行顺序和构造函数的执行顺序正好相反
//1--创建派生类对象时，构造函数的执行顺序和继承顺序相同，即先执行基类构造函数，在执行了派生类构造函数
//2。而销毁派生类对象时，析构函数的执行顺序和继承顺序相反，即先执行派生类析构函数函数，在执行基类析构函数

//class Haha{
//public:
//    Haha()
//    {
//        printf("HaHa()\n");
//
//    }
//    ~Haha(){
//        printf("~HaHa()\n");
//    }
//
//};
//
//class HeHe : public Haha{
//public:
//    HeHe(){
//        printf("HeHe()\n");
//
//    }
//    ~HeHe()
//    {
//        printf("~HeHe()\n");
//    }
//};
//
//class HoHo :public HeHe{
//public:
//    HoHo(){
//        printf("HoHo()\n");
//
//    }
//    ~HoHo(){
//        printf("~HoHo()\n");
//    }
//};
//int main()
//{
//    HoHo ho;
//    return 9;
//}
//------------------***类的多继承***----------------------------------------/
class O {
public:
    O()
    {
        printf("O()\n");
    }
    ~O(){
        printf("~O()\n");
    }

protected:
    void print()
    {
        printf("O::print()\n");
    }
};


class P {
public:
    P()
    {
        printf("P()\n");
    }
    ~P(){
        printf("~P()\n");

    }

protected:
    void print()
    {
        printf("P::print()\n");
    }
};

class R :public O,public P{
public:
    R():O(),P(){
        printf("R()\n");
    }
    ~R(){
        printf("~R()\n");

    }

public:
    void print()
    {
        P::print();
        O::print();
    }
};
int main()
{
    R r;
    r.print();

}
