//
// Created by Hash on 2019-08-14.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "iostream"
#include "string.h"
using namespace std;
class Student {
public:
    Student(int age, char *name) {
        printf("构造函数\n");
        this->name = (char *) (malloc(sizeof(char) * 10));
        strcpy(this->name, name);
        this->age = age;
    }


    Student(char *name) : sex("man") {
        this->name = name;
    }

    Student() {
        printf("empty construct fun operate\n");

    }

    ~Student(){ //如果在对象内部堆内存上开辟内存，一定记得回收
        printf("~Student() operate\n");
        free(this->name); //free malloc
        this->name=NULL;
    }
    Student(const Student& student)
    {
        printf("对象的拷贝函数执行\n");
        this->age=student.age-1;
        char* studentName= student.name;
        char* modifyName="modify";
        char* name =(char*)malloc(strlen(studentName)+strlen(modifyName));
        strcpy(name,studentName);
        strcat(name,modifyName);//实现字符串拼接
        this->name=name;
    }
public:
    int getAge()
    {
        return this->age;

    }
    char* getName()
    {
        return this->name;
    }
    void setAge(int age)
    {
        Student::age=age;
    }
    void setName(char* name)
    {
        Student::name=name;
    }
    void printStudent(Student student)//student 是该方法栈中的一个新对象，拷贝构造函数赋值，方法执行完了会调用析构函数
    {
        cout<<student.getName()<<":"<<student.getAge()<<endl;
    }

private:
    int age;
    char* name;
    char* sex;
};
//析构函数 构造函数使用
int main()
{
//    Student student;//第一种
    //Student student1(222,"hh");//第二种
//    Student* student2=new Student(11,"jj");//第三种 new关键字返回的是一级指针
    Student* student3=(Student*)malloc(sizeof(Student));//第四种 malloc不会调用构造函数
    student3->setAge(10);
    student3->setName("test");
    //delete(student3); //注意delete是回收new对象的，并且是会调用析构函数的

//    free(student3);

    cout<<student3->getAge()<<endl;
    cout<<student3->getName()<<endl;
    student3->printStudent(*student3);

//    delete(student2);

    free(student3);


    //Student student1(22,"33");
    //Student a = student1;// student1 和 a 的地址不一样
    //cout<<a.getAge()<<endl;
//    Student stu2;//声明变量，开辟变量内存
// stu2= student1;//这个不会去调用拷贝构造函数，但是会赋值

//作为参数传递的时候会调用拷贝构造函数

}