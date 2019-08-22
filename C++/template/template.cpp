//
// Created by Hash on 2019-08-22.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
/**
 * template 其实对应的就是java中的泛形
 */
#include "template.h"
#include "iostream"
template <class T>
Template<T>::Template(const T a[], int n) {
    if (n>MAXSIZE) throw "array out of length";
    for (int i = 0; i < n; i++) {
        data[i]=a[i];

    }
    length=n;
}
template <class T>
T Template<T>::get(int i) {
    if (i<1||i>length)throw "illegal state";
    return data[i-1];
}
template <class T>
int Template<T>::locate(const  T x) {
    for(int i =0;i<length;i++)
    {
        if (x==data[i])
        {
            return i+1;
        }

    }
    return 0;
}
template <class T>
bool Template<T>::remove(int index) {
    if (index<1||index>length)throw "illegal state";
    for(int i=index;i<this->length;i++)
    {
      this->data[i]=this->data[i+1];

    }
    this->length--;
    return true;
}

int main()
{
    int a[7]={21,212,3,1,2,31,32};
    Template<int> list(a,7);
    int v = list.locate(5);
    cout << v << endl;
    int d = list.get(1);
    cout << d << endl;
    list.remove(1);
    int d2 = list.get(2);
    cout << d2 << endl;
}