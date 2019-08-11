//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "stdio.h"
#include "stdarg.h"
#include "iostream"

using namespace std;

void sum(int count, int first ...)
{
    va_list  vaList; //创建list，保存可变参数
    //可变参数开始
    va_start(vaList,count);//Loop 循环
    int num = va_arg(vaList, int);
    cout<<num<<endl;


    int num2 =va_arg(vaList,int);
    cout<<num2<<endl;


    int num3 =va_arg(vaList,int);//内存溢出
    cout<<num3<<endl;
}

int add_va(int num,int first,...)
{
    int ret=0,arg,i;
    va_list  vaList;//定义一个可变参数变量

    ret =first;
    va_start(vaList,first);//初始化可变参数
    cout<<"ret init:"<<ret<<endl;
    for(int i =1;i<num;i++)
    {
        arg =va_arg(vaList,int);
        cout<<"arg:"<<arg<<endl;
        ret+=arg;//获取下一个类型为int的参数
        cout<<"ret:"<<ret <<endl;

    }
    va_end(vaList);//清楚变量vaList；

    return ret;

}
void print_variable(const char* format...){
    va_list  ap;
    va_start(ap,format);
    char ch;
    while (ch=(*format++)){
        if (ch=='%'){
            ch=*(format++);
            if (ch=='s')//%s
            {
                char *name = va_arg(ap,char *);
//                cout<<"name::"<<name<<endl;代码跟踪调试
                cout<<name;
            }else if(ch =='d')//%d
            {
                int age = va_arg(ap, int);
//                cout<<"age::"<<age<<endl;代码跟踪调试
                cout<<age;
            }

        }else{
//            cout<<"ch::"<<ch<<endl; 代码跟踪调试
            cout<<ch;
        }
    }

}

int main()
{
   // sum(3,4,5);
    printf("%d\n",add_va(3,2,3,4));
    print_variable("My name is %s, age %d.","Hash",2);
    return -1;
}