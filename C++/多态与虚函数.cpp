//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
/**
 * 基类指针指向了派生类对象，那么就应该使用派生类的成员变量和成员函数》》
 *
 * 通过基类指针只能访问派生类的成员变量，但是不能访问派生类成员函数，但是为了能够让基类能够访问
 * 派生类的成员函数，C++增加了虚函数
 *
 *
 * 有了虚函数，基类指针指向基类就使用基类的成员（包括成员函数和成员变量）指向派生对象时就使用派生类的成员；
 * 换句话说；基类指针可以按照基类也可以按照派生类来执行对应的函数，存在多种形态，或者多种表现方式，
 * 这就是多态的表现形式
 *
 *
 * 1.C++虚函数的唯一用处就是构成多态
 * 2.C++提供多态的目的：可以通过基类指针对所有派生类（直接派生和间接派生）的成员变量和成员函数进行访问（如果没有多态，只能访问成员变量）
 */
//
#include "stdio.h"
using namespace std;

//class People{
//public:
//    People(const char* name,int age);
//    void print() const ;
//
//protected:
//    const char *m_name;
//    int m_age;
//
//};
//
//People::People(const char *name, int age):m_name(name),m_age(age) {
//
//}
//
//void People::print() const {
//    printf("name: %s, age :%d\n",m_name,m_age);
//}
//
//class Student : public  People{
//public:
//    Student(const char* name,int age, float score);
//    void print() const;
//
//private:
//    float m_score;
//
//
//};
//
//Student::Student(const char *name, int age, float score):People(name,age),m_score(score) {}
//void Student::print() const {
//    printf("name: %s,age:%d,score:%g\n",m_name,m_age,m_score,m_score);
//
//}
//
//int main()
//{
//    People *people = nullptr;
//    people =new People("lisi",23);
//    people->print();
//    delete people;
//
//    people =new Student("zhansan",2,33.2);
//    people->print();
//    delete people;
//    return 0;
//}

class Anim{
public:
    Anim(const char* name, int age);
    virtual ~Anim(){}
    virtual void eat() const ;

protected:
    const char* m_name;
    int m_age;
};

class Dog:public Anim{
public:
    Dog(const char*name,int age, float score);
    virtual ~Dog() override{};
    virtual void eat() const override ;
private:
    float m_score;
};
Anim::Anim(const char *name, int age) :m_name(name),m_age(age){}
void Anim::eat() const {
    printf("name:%s age:%d\n",m_name,m_age);
}

Dog::Dog(const char *name, int age, float score):Anim(name,age),m_score(score){}
void Dog::eat() const {
    printf("name:%s age:%d score:%g\n",m_name,m_age,m_score);
}
int main()
{

    Anim *anim = nullptr;

    anim =new Anim("anim",22);
    anim->eat();
    delete anim;


    anim =new Dog("dog",2,22.2);
    anim->eat();
    delete anim;


}




