//
// Created by Hash on 2019-08-18.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#include "namespace_demo.h"
#include <iostream>
#include "string.h"
using namespace NameSpaceA;
using namespace std;
//..组件化 分模块
//测试namespace
int main2()
{
    printf("a = %d\n",name);
    printf("a = %d\n",NameSpaceB::age);

    NameSpaceB::NameSpaceC::Teacher teacher;
    NameSpaceB::NameSpaceC::Teacher t1;
    char a[10]={"hello c++"};
    //字符串赋值操作
    strcpy(teacher.name,a);
    teacher.age=1;
    printf("t1.name=%s\n",teacher.name);
    printf("t1.age=%d\n",teacher.age);
    return 0;
}
int main()
{
    int a =10;//4个字节，a内存空间的别名
    int &b=a;//b就是a的别名
    a=11;//直接赋值
    {
        int *p =&a;
        *p =12;
        printf("a:%d , b:%d \n",a,b);// a 12 b 12
    }

    int c =144;
    a=c;
    int *pInt=&a;
    printf("&a value :%d, &a address:%p\n",*(&a),&a);//144

    b=*pInt;

    printf("a:%d b:%d,pInt:%p\n",a,b,pInt);// a 144 b 144

}


