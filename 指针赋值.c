//
// Created by Hash on 2019-08-07.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"


//指针做函数参数间接改变我们的运算结果
//int getFoleLen(int* p)
//{
//    *p = 40;
//    return  true;
//}
//这样只能修改形参的值，不能改变实参的值， 不通过操作地址的话，编译器是将实参的值复制给形参， 而不是把实参传递过来
///形参 add（int b） 实参 add（2）；
int getFoleLen(int b)
{
    //形参变量和函数里面的变量本质是一样的，只不形参变量具有对外的属性
    b =100;
    return true;
}

/*int getFoleLen()
{ return 只能返回一个结果
    int a =100;
    return a;
}*/
void main()
{
    int *p =NULL;
    int a =10;
    //直接修改a的值
    a =12;
    //间接修改
    p = &a;
    *p = 20;//p的值是a的地址，*就像一把钥匙 通过地址 找到一块内存空间，就间接修改了a的值

    printf("a， %d\n",a);
    getFoleLen(&a);
    printf("a1, %d\n",a);
    getFoleLen(a);
    printf("a2, %d\n",a);



}