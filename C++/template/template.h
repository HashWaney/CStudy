//
// Created by Hash on 2019-08-22.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#ifndef DEMO_TEMPLATE_H
#define DEMO_TEMPLATE_H

using  namespace std;
const int MAXSIZE =1000;
template <class T>
class Template{
public:
    Template(){length=0;}
    Template(const T a[],int n);
    int locate(T x);
    T get(int i);//获取第i个位置元素
    bool remove(int index);//删除指定下标元素

private:
    int length;
    T data[MAXSIZE];


};


#endif //DEMO_TEMPLATE_H
