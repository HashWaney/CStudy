//
// Created by Hash on 2019-08-14.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
/**
 * 函数的重载
 *
 */
#include "FunctionOverloading.h"
#include "cstdio"
using namespace std;
void FunctionOverloading::print() const {
    printf("m_real = %g\nm_img = %g\n",m_real,m_img);
}

FunctionOverloading  FunctionOverloading::operator+(const FunctionOverloading &A) const {
    return FunctionOverloading(m_real+A.m_real,m_img+A.m_img);
}

int main()
{
    FunctionOverloading A(1.23,5.7),B(5,12.2),C;
    C= A+B;
    C.print();
    return 0;
}