//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
/**
 * 单例模式创建唯一实例
 * 使用静态成员属性或者函数时候 需要使用域运算符::
 *
 */
#include "static.h"
STATIC* STATIC::instance=0;
STATIC* STATIC::getInstance() {
    if(!instance){
        instance =new STATIC();
    }
    return instance;
}

